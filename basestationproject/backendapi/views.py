# Django Imports
from django.http import JsonResponse, StreamingHttpResponse, HttpResponse
from django.views.decorators.csrf import csrf_exempt
from django.shortcuts import render
from django.core.cache import cache

# Django Rest Framework Imports
from rest_framework.response import Response
from rest_framework.views import APIView
from rest_framework.decorators import api_view
from rest_framework import status

# ROS 2 and Message Imports
import rclpy
from rclpy.node import Node
from rclpy.executors import MultiThreadedExecutor
from sensor_msgs.msg import Image
from custom_msgs.msg import DrivetrainFeedback, ScienceFeedback, ScienceControl
from std_msgs.msg import String


# Third-party Imports
import cv2
import numpy as np
import httpx
import json
import time
import threading
from asgiref.sync import async_to_sync

# Custom Imports
from . import models



def get_data():
    data = cache.get('my_data')
    if data is None:
        # Retrieve data from the database or another source
        data = models.retrieve_data()
        cache.set('my_data', data, timeout=3600)  # Cache for 1 hour
    return data


# Store mock devices in Redis
def store_devices(request):
    devices = [
        {"name": "Function", "status": 15},
        {"name": "Function", "status": 63},
        {"name": "Function", "status": 41},
        {"name": "Function", "status": 87},
        {"name": "Function", "status": 29},
    ]
    cache.set("connected_devices", json.dumps(devices), timeout=None)
    return JsonResponse({"message": "Devices stored successfully!"})

# Fetch connected devices from Redis
def get_devices(request):
    devices = cache.get("connected_devices")
    devices = json.loads(devices) if devices else []
    return JsonResponse(devices, safe=False)

# Store robo specs in Redis
def get_robo_specs(request):
    specs = [
        {"name": "ARM", "type": "ROBOTIC ARM", "quantity": 2},
        {"name": "Motor 1", "type": "WHEELS", "quantity": 2},
        {"name": "Science Sensor", "type": "SENSOR", "quantity": 1},
        {"name": "Front Camera", "type": "Sony 24Px", "quantity": 1},
        {"name": "Rear Camera", "type": "Aony 98Px", "quantity": 1},
    ]
    cache.set("robo_specs", json.dumps(specs), timeout=None)
    return JsonResponse({"message": "Robo specs stored successfully!"})

# Fetch robo specs from Redis
def get_specs(request):
    specs = cache.get("robo_specs")
    specs = json.loads(specs) if specs else []
    return JsonResponse(specs, safe=False)

# Connect rover simulation
@csrf_exempt  # temp remove in prod
def connect_rover(request):
    cache.set("rover_status", "connected", timeout=None)
    return JsonResponse({"status": "connected", "message": "Rover connected successfully!"})

# Disconnect rover simulation
def disconnect_rover(request):
    cache.set("rover_status", "disconnected", timeout=None)
    return JsonResponse({"status": "disconnected", "message": "Rover disconnected successfully!"})

# Command-Related Views
class RoverCommand(APIView):
    def get(self, request):
        pass  # Functionality to be added later

# Arm Control Views
class ArmOverview(APIView):
    def get(self, request):
        pass  # Functionality to be added later

class ArmActivate(APIView):
    def get(self, request):
        return Response({"message": "Arm activation placeholder."}, status=status.HTTP_200_OK)

class ArmDeactivate(APIView):
    def get(self, request):
        return Response({"message": "Arm deactivation placeholder."}, status=status.HTTP_200_OK)

# Rover-control related views
class RoverMove(APIView):
    def get(self, request):
        return Response({"message": "Rover move placeholder."}, status=status.HTTP_200_OK)

class RoverStart(APIView):
    def get(self, request):
        return Response({"message": "Rover start placeholder."}, status=status.HTTP_200_OK)

class RoverStop(APIView):
    def get(self, request):
        return Response({"message": "Rover stop placeholder."}, status=status.HTTP_200_OK)


fps = 15


class ROS2Manager:
    """Singleton ROS2 Manager to handle initialization and node management."""
    _instance = None
    _lock = threading.Lock()  # Ensure thread-safe singleton initialization

    def __init__(self):
        if ROS2Manager._instance is not None:
            raise Exception("This is a singleton class. Use get_instance() instead.")

        # Initialize ROS2 if not already initialized
        if not rclpy.ok():
            rclpy.init()

        self.executor = MultiThreadedExecutor(context=rclpy.get_default_context())  # Ensure proper context
        self.nodes = {}  # Stores all nodes

        # Start executor thread
        self.executor_thread = threading.Thread(target=self.executor.spin, daemon=True)
        self.executor_thread.start()

    @classmethod
    def get_instance(cls):
        """Thread-safe singleton instance creation."""
        with cls._lock:
            if cls._instance is None:
                cls._instance = ROS2Manager()
        return cls._instance

    def add_node(self, node):
        """Add a new node to the executor and manage it."""
        self.nodes[node.get_name()] = node
        self.executor.add_node(node)


# Initialize Singleton ROS2 Manager
ros_manager = ROS2Manager.get_instance()


class MultiCameraSubscriber(Node):
    """Subscriber to multiple camera topics dynamically."""
    def __init__(self, camera_id):
        super().__init__(f'camera_stream_subscriber_{camera_id}')
        self.camera_id = camera_id
        self.subscription = self.create_subscription(
            Image, f'/camera_{camera_id}/image_raw', self.image_callback, fps)
        self.current_frame = None
        self.lock = threading.Lock()

    def image_callback(self, msg):
        """Process received image frames."""
        np_arr = np.frombuffer(msg.data, np.uint8)
        frame = np_arr.reshape((msg.height, msg.width, 3))
        with self.lock:
            self.current_frame = frame


def initialize_cameras():
    """Initialize all camera subscribers dynamically."""
    camera_nodes = {}
    for cam_id in range(4):  # Cameras 0 to 3
        camera_node = MultiCameraSubscriber(cam_id)
        ros_manager.add_node(camera_node)
        camera_nodes[cam_id] = camera_node
    print("✅ All camera nodes initialized!")
    return camera_nodes


camera_nodes = initialize_cameras()
    

def get_frame(request, camera_id):
    """Serve a single frame from a specific camera."""
    camera_id = int(camera_id)
    if camera_id in camera_nodes and camera_nodes[camera_id].current_frame is not None:
        with camera_nodes[camera_id].lock:
            success, jpeg = cv2.imencode('.jpg', camera_nodes[camera_id].current_frame)
            if not success:
                return HttpResponse(status=500)
        return HttpResponse(jpeg.tobytes(), content_type="image/jpeg")
    return HttpResponse(status=204)  # No content if no frame is available


class DrivetrainFeedbackSubscriber(Node):
    """Subscriber to Drivetrain Feedback topic."""
    def __init__(self):
        super().__init__('drivetrain_feedback_subscriber')
        self.subscription = self.create_subscription(
            DrivetrainFeedback, '/drivetrain_feedback', self.feedback_callback, 10
        )
        self.latest_feedback = {}

    def feedback_callback(self, msg):
        """Process drivetrain feedback messages."""
        self.latest_feedback = {
            "epoch_time": msg.epoch_time,
            "wheel_position": msg.wheel_position,
            "wheel_velocity": msg.wheel_velocity,
            "wheel_torque": msg.wheel_torque,
        }

from django.http import JsonResponse

def get_drivetrain_feedback(request):
    """Retrieve the latest drivetrain feedback data."""
    global feedback_node  # Ensure we use the initialized feedback subscriber

    if feedback_node.latest_feedback:
        # Convert NumPy arrays to Python lists
        formatted_feedback = {
            "epoch_time": feedback_node.latest_feedback["epoch_time"],
            "wheel_position": feedback_node.latest_feedback["wheel_position"].tolist()
            if isinstance(feedback_node.latest_feedback["wheel_position"], np.ndarray)
            else feedback_node.latest_feedback["wheel_position"],
            "wheel_velocity": feedback_node.latest_feedback["wheel_velocity"].tolist()
            if isinstance(feedback_node.latest_feedback["wheel_velocity"], np.ndarray)
            else feedback_node.latest_feedback["wheel_velocity"],
            "wheel_torque": feedback_node.latest_feedback["wheel_torque"].tolist()
            if isinstance(feedback_node.latest_feedback["wheel_torque"], np.ndarray)
            else feedback_node.latest_feedback["wheel_torque"],
        }

        return JsonResponse(formatted_feedback)

    return JsonResponse({"error": "No feedback available"}, status=204)


# Initialize drivetrain subscriber
feedback_node = DrivetrainFeedbackSubscriber()
ros_manager.add_node(feedback_node)

class ScienceFeedbackSubscriber(Node):
    """Subscriber to Science Feedback topic."""
    def __init__(self):
        super().__init__('science_feedback_subscriber')
        self.subscription = self.create_subscription(
            ScienceFeedback, '/science_feedback', self.feedback_callback, 10
        )
        self.latest_feedback = {}

    def feedback_callback(self, msg):
        """Process science feedback messages."""
        self.latest_feedback = {
            "water_percent": msg.water_percent,
            "temperature": msg.temperature,
            "ilmenite_percent": msg.ilmenite_percent,
        }

# Science Control Publisher
class ScienceControlPublisher(Node):
    """Publisher to Science Control topic."""
    def __init__(self):
        super().__init__('science_control_publisher')
        self.publisher = self.create_publisher(ScienceControl, '/science_control', 10)

    def publish_control(self, data):
        """Publish control data."""
        msg = ScienceControl()
        msg.heat_status = data.get("heat_status", False)
        msg.water_status = data.get("water_status", False)
        msg.ilmenite_status = data.get("ilmenite_status", False)
        msg.deploy_heat = data.get("deploy_heat", False)
        msg.deploy_sensors = data.get("deploy_sensors", False)
        self.publisher.publish(msg)

# Initialize Science Feedback Subscriber
science_feedback_node = ScienceFeedbackSubscriber()
ros_manager.add_node(science_feedback_node)

# Initialize Science Control Publisher
science_control_node = ScienceControlPublisher()
ros_manager.add_node(science_control_node)


def get_science_feedback(request):
    """Retrieve the latest science feedback data."""
    if science_feedback_node.latest_feedback:
        return JsonResponse(science_feedback_node.latest_feedback)
    return JsonResponse({"error": "No science feedback available"}, status=204)


@csrf_exempt
def set_science_control(request):
    """Set science control settings via a ROS2 publisher."""
    if request.method == "POST":
        try:
            data = json.loads(request.body)
            science_control_node.publish_control(data)
            return JsonResponse({"status": "success", "message": "Science control command sent!"})
        except json.JSONDecodeError:
            return JsonResponse({"error": "Invalid JSON"}, status=400)
    
    return JsonResponse({"error": "Invalid request method"}, status=405)


class RoverLogsSubscriber(Node):
    """Subscriber for the Rover_Logs topic."""
    def __init__(self):
        super().__init__('rover_logs_subscriber')
        self.subscription = self.create_subscription(
            String, 'rover_logs', self.log_callback, 10
        )
        self.latest_logs = []

    def log_callback(self, msg):
        """Store received log messages."""
        log_message = msg.data
        self.latest_logs.append(log_message)
        self.get_logger().info(f"Received log: {log_message}")

# Initialize the log subscriber and add to ROS2 Manager
rover_logs_node = RoverLogsSubscriber()
ros_manager.add_node(rover_logs_node)

# Django API Endpoint to Fetch Logs
def get_rover_logs(request):
    """Retrieve logs from the Rover_Logs topic."""
    if rover_logs_node.latest_logs:
        return JsonResponse({"logs": rover_logs_node.latest_logs})
    
    return JsonResponse({"logs": [], "message": "No logs received yet."}, status=204)

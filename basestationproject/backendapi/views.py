# Django imports
from django.core.cache import cache
from django.http import JsonResponse
from django.shortcuts import render
from django.views.decorators.csrf import csrf_exempt
from django.http import StreamingHttpResponse, JsonResponse

from . import models


# Third-party imports
import cv2
import httpx
import rclpy
import json
import time
import numpy as np
from asgiref.sync import async_to_sync
from rest_framework import status
from rest_framework.decorators import api_view
from rest_framework.response import Response
from rest_framework.views import APIView

# Custom imports
from custom_msgs.msg import CustomMessage  # Import the custom message

# redis testing
from django.core.cache import cache

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


# Initialize ROS only once

"""
rclpy.init()  # Make sure this is only called once in the script
node = rclpy.create_node('django_custom_message_publisher')
publisher = node.create_publisher(CustomMessage, 'example_topic', 10)
msg = CustomMessage()

class SendCommandView(APIView):
    def post(self, request):
        # Data from the client
        command_data = request.data  # e.g., {"command": "move"}

        # Wrap the async call to FastAPI in `async_to_sync`
        response = async_to_sync(self.send_command_to_fastapi)(command_data)

        # Return the FastAPI response to the Django client
        return Response(response)

    async def send_command_to_fastapi(self, command_data):
        # Async call to the FastAPI server
        fastapi_url = "http://127.0.0.1:8080/command"
        async with httpx.AsyncClient() as client:
            response = await client.post(fastapi_url, json=command_data)
            return response.json()


class PublishCustomMessageView(APIView):
    def post(self, request):
        # Extract data from the request
        data = request.data.get("data", "default_data")
        flag = bool(request.data.get("flag", False))

        epoch_time = int(time.time() * 1e9)       

        # Create and publish the custom message
        msg.epoch_time = epoch_time
        msg.data = data
        msg.flag = flag

        publisher.publish(msg)
        node.get_logger().info(f"Published to 'example_topic': {msg}")

        return Response({"status": "success", "message": "Custom message published!"})

    def killNode(self, request):
        node.destroy_node()
        rclpy.shutdown()

"""

"""
Camera Controller
"""
# camera views here
"""
from rclpy.node import Node
from sensor_msgs.msg import Image
from django.http import StreamingHttpResponse
import threading


class CameraSubscriber(Node):
    def __init__(self):
        super().__init__('camera_stream_subscriber')
        self.subscription = self.create_subscription(
            Image,
            '/camera_0/image_raw',  # Ensure this topic matches exactly
            self.image_callback,
            10)
        self.current_frame = None
        self.lock = threading.Lock()
        self.get_logger().info("CameraSubscriber initialized!")  # Debug log

    def image_callback(self, msg):
        self.get_logger().info(f"Received an image with resolution: {msg.width}x{msg.height}")  # Debug log
        np_arr = np.frombuffer(msg.data, np.uint8)
        frame = np_arr.reshape((msg.height, msg.width, 3))

        with self.lock:
            self.current_frame = frame


camera_node = None
camera_thread = None

def start_ros_node():
    global camera_node
    rclpy.init()
    camera_node = CameraSubscriber()
    rclpy.spin(camera_node)

def generate_frames():
    global camera_node
    while True:
        if camera_node and camera_node.current_frame is not None:
            with camera_node.lock:
                success, jpeg = cv2.imencode('.jpg', camera_node.current_frame)
                if not success:
                    print("Failed to encode frame")
                    continue

                frame = jpeg.tobytes()
                print("Streaming frame...")  # Debug log

            yield (b'--frame\r\n'
                   b'Content-Type: image/jpeg\r\n\r\n' + frame + b'\r\n\r\n')
        else:
            print("No frames available yet")  # Debug log

def video_feed(request):
    return StreamingHttpResponse(generate_frames(), content_type='multipart/x-mixed-replace; boundary=frame')



import cv2
import numpy as np
from django.http import HttpResponse

def get_frame(request):
    # Serve a single frame from the ROS2 topic as a JPEG image
    global camera_node
    if camera_node and camera_node.current_frame is not None:
        with camera_node.lock:
            success, jpeg = cv2.imencode('.jpg', camera_node.current_frame)
            if not success:
                return HttpResponse(status=500)

        return HttpResponse(jpeg.tobytes(), content_type="image/jpeg")
    
    return HttpResponse(status=204)  # No content if no frame is available


# Start the ROS node in a separate thread
if camera_thread is None:
    camera_thread = threading.Thread(target=start_ros_node, daemon=True)
    camera_thread.start()

"""

import cv2
import numpy as np
from django.http import HttpResponse
import threading
import rclpy
from rclpy.node import Node
from rclpy.executors import MultiThreadedExecutor
from sensor_msgs.msg import Image

# Dictionary to store camera nodes
camera_nodes = {}
fps = 30
class MultiCameraSubscriber(Node):
    def __init__(self, camera_id):
        super().__init__(f'camera_stream_subscriber_{camera_id}')
        self.camera_id = camera_id
        self.subscription = self.create_subscription(
            Image,
            f'/camera_{camera_id}/image_raw',  # Dynamic topic
            self.image_callback,
            fps)
        self.current_frame = None
        self.lock = threading.Lock()
        # self.get_logger().info(f"CameraSubscriber {camera_id} initialized!")

    def image_callback(self, msg):
        # self.get_logger().info(f"Received image from camera_{self.camera_id}: {msg.width}x{msg.height}")
        np_arr = np.frombuffer(msg.data, np.uint8)
        frame = np_arr.reshape((msg.height, msg.width, 3))

        with self.lock:
            self.current_frame = frame


def start_ros_nodes():
    """ Start a single ROS2 executor for all cameras """
    global camera_nodes
    if not rclpy.ok():
        rclpy.init()

    executor = MultiThreadedExecutor()

    for cam_id in range(4):  # Cameras 0 to 3
        camera_nodes[cam_id] = MultiCameraSubscriber(cam_id)
        executor.add_node(camera_nodes[cam_id])

    print("✅ All camera nodes initialized! Starting executor...")

    executor_thread = threading.Thread(target=executor.spin, daemon=True)
    executor_thread.start()


# Start ROS2 nodes when Django starts
start_ros_nodes()


def get_frame(request, camera_id):
    """ Serve a single frame from a specific camera """
    global camera_nodes
    camera_id = int(camera_id)  # Ensure it's an integer

    if camera_id in camera_nodes and camera_nodes[camera_id].current_frame is not None:
        with camera_nodes[camera_id].lock:
            success, jpeg = cv2.imencode('.jpg', camera_nodes[camera_id].current_frame)
            if not success:
                return HttpResponse(status=500)

        return HttpResponse(jpeg.tobytes(), content_type="image/jpeg")

    return HttpResponse(status=204)  # No content if no frame is available

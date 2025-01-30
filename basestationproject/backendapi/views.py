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
@csrf_exempt # temp remove in prod
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
        pass # Functionality to be added later

# Arm Control Views
class ArmOverview(APIView):
    def get(self, request):
        pass # Functionality to be added later

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



# Initialize ROS and publish the custom message
rclpy.init()  # Make sure this doesn't conflict with other nodes
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
        # epoch_time = int(request.data.get("epoch_time", 0))
        
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
Camera Controller
"""


from django.http import StreamingHttpResponse, JsonResponse
from django.views.decorators.csrf import csrf_exempt
import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
import numpy as np
import cv2
import json
import threading

# Dictionary to store latest images from each camera topic
latest_frames = {}

# Camera settings (FPS, Mode, Active)
camera_settings = {
    "1": {"fps": 30, "active": True, "mode": "rgb"},
    "2": {"fps": 30, "active": True, "mode": "rgb"},
}

class CameraSubscriber(Node):
    """ROS 2 Subscriber Node for Camera Topics"""
    def __init__(self):
        super().__init__("camera_subscriber")
        self.subscribers = {}
        
        for cam_id in camera_settings.keys():
            topic_name = f"camera_t{cam_id}"
            self.subscribers[cam_id] = self.create_subscription(
                Image,
                topic_name,
                lambda msg, cam_id=cam_id: self.image_callback(msg, cam_id),
                10
            )
    
    def image_callback(self, msg, cam_id):
        """Convert ROS 2 Image message to OpenCV format."""
        if not camera_settings[cam_id]["active"]:
            return  # Ignore if camera is off
        
        # Convert sensor_msgs/Image to OpenCV format
        frame = np.frombuffer(msg.data, dtype=np.uint8).reshape((msg.height, msg.width, -1))

        # If depth mode, apply color map
        if camera_settings[cam_id]["mode"] == "depth":
            frame = cv2.applyColorMap(cv2.convertScaleAbs(frame, alpha=0.03), cv2.COLORMAP_JET)

        latest_frames[cam_id] = frame

# Initialize ROS node in a separate thread
rclpy.init()
ros_node = CameraSubscriber()
threading.Thread(target=rclpy.spin, args=(ros_node,), daemon=True).start()

def generate_stream(camera_id):
    """Stream the latest frame from a ROS topic."""
    while True:
        if not camera_settings[camera_id]["active"]:
            continue
        
        if camera_id in latest_frames:
            frame = latest_frames[camera_id]
            _, jpeg = cv2.imencode(".jpg", frame)
            yield (b"--frame\r\n"
                   b"Content-Type: image/jpeg\r\n\r\n" + jpeg.tobytes() + b"\r\n")

@csrf_exempt
def camera_stream(request, camera_id):
    """Django view to stream a camera topic."""
    if camera_id not in camera_settings:
        return JsonResponse({"error": "Invalid camera ID"}, status=400)
    return StreamingHttpResponse(generate_stream(camera_id), content_type="multipart/x-mixed-replace; boundary=frame")

@csrf_exempt
def update_fps(request, camera_id):
    """Update FPS setting for a camera."""
    if request.method == "POST":
        data = json.loads(request.body)
        fps = data.get("fps", 30)
        camera_settings[camera_id]["fps"] = fps
        return JsonResponse({"message": "FPS updated", "fps": fps})
    return JsonResponse({"error": "Invalid request"}, status=400)

@csrf_exempt
def toggle_camera(request, camera_id):
    """Turn a camera on or off."""
    if camera_id in camera_settings:
        camera_settings[camera_id]["active"] = not camera_settings[camera_id]["active"]
        return JsonResponse({"message": "Camera toggled", "active": camera_settings[camera_id]["active"]})
    return JsonResponse({"error": "Invalid camera ID"}, status=400)

@csrf_exempt
def toggle_mode(request, camera_id):
    """Switch between RGB and Depth mode."""
    if camera_id in camera_settings:
        camera_settings[camera_id]["mode"] = "depth" if camera_settings[camera_id]["mode"] == "rgb" else "rgb"
        return JsonResponse({"message": "Mode toggled", "mode": camera_settings[camera_id]["mode"]})
    return JsonResponse({"error": "Invalid camera ID"}, status=400)

# Django imports
from django.core.cache import cache
from django.http import JsonResponse
from django.shortcuts import render
from django.views.decorators.csrf import csrf_exempt

# Third-party imports
import httpx
import rclpy
import json
from asgiref.sync import async_to_sync
from rest_framework import status
from rest_framework.decorators import api_view
from rest_framework.response import Response
from rest_framework.views import APIView

# Custom imports
from custom_msgs.msg import CustomMessage  # Import the custom message
from . import models
import time


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

# class ArmActivate(APIView):
#     def get(self, request):
#         pass # Activate arm logic
#
# class ArmDeactivate(APIView):
#     def get(self, request):
#         pass  # Deactivate arm logic
#
#
# # Rover Control Views
# class RoverMove(APIView):
#     def get(self, request):
#         pass   # Rover move logic
#
#
# class RoverStop(APIView):
#     def get(self, request):
#         pass  # Rover stop logic
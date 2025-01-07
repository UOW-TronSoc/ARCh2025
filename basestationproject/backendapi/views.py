from django.shortcuts import render
from rest_framework.decorators import api_view
from rest_framework.views import APIView
from rest_framework.response import Response
from asgiref.sync import async_to_sync
import httpx
import rclpy
from custom_msgs.msg import CustomMessage  # Import the custom message
import time



@api_view(['GET'])
def hello_world(request):
    return Response({'message': 'Hello, world!'})


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
        fastapi_url = "http://127.0.0.1:8001/command"
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
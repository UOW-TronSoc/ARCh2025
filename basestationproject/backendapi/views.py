from django.shortcuts import render

# Create your views here.
from rest_framework.decorators import api_view
from rest_framework.views import APIView
from rest_framework.response import Response

import rclpy
from rclpy.node import Node
from custom_msgs.msg import CustomMessage

@api_view(['GET'])
def hello_world(request):
    return Response({'message': 'Hello, world!'})


class SendDriveCommandView(APIView):
    def post(self, request):
        # Extract the drive data from the request
        epoch_time = int(request.data.get("epoch_time", 0))
        data = request.data.get("data", "default_data")
        flag = bool(request.data.get("flag", False))
        left_drive = int(request.data.get("leftDrive", 0))
        right_drive = int(request.data.get("rightDrive", 0))

        # Publish the data to ROS 2 topic
        rclpy.init(args=None)
        node = rclpy.create_node('django_drive_command_publisher')
        publisher = node.create_publisher(CustomMessage, 'drive_commands', 10)

        msg = CustomMessage()
        msg.epoch_time = epoch_time
        msg.data = data
        msg.flag = flag
        msg.left_drive = left_drive
        msg.right_drive = right_drive

        publisher.publish(msg)
        node.get_logger().info(f"Published drive command: {msg}")

        node.destroy_node()
        rclpy.shutdown()

        return Response({"status": "success", "message": "Drive command published"})


class kanga_connection():
  def connect(request):
    pass
  
  
# backend functional code here or where you will post to

class KangaConnection(APIView):
    def connect(request):
        pass

    def disconnect(request):
        pass

class DeviceDetails(APIView):
    def retrieve(request):
        pass

    def store(request):
        pass

class QuickOverview(APIView):
    def retrieve(request):
        pass

class RoboSpec(APIView):
    def retrieve(request):
        pass

class ControlCommandLogHistory(APIView):
    def retrieve(request):
        pass

class NLI_Section(APIView):
    def retrieve(request):
        pass

class MapControls(APIView):
    def control(request):
        pass

class DataGraph(APIView):
    def retrive(request):
        pass

class DataLogHistory(APIView):
    def retrieve(request):
        pass
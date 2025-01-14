from django.views.decorators.csrf import csrf_exempt
from django.core.cache import cache
from django.http import JsonResponse
from rest_framework.response import Response
from rest_framework.views import APIView
from rest_framework import status



import json

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
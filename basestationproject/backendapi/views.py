from django.shortcuts import render

# Create your views here.
from rest_framework.decorators import api_view
from rest_framework.views import APIView
from rest_framework.response import Response

@api_view(['GET'])
def hello_world(request):
    return Response({'message': 'Hello, world!'})


class kanga_connection():
  def connect(request):
    pass
  
  
# backend functional code here or where you will post to
class Logs(APIView):
    def retrieve(request):
        pass

    def store(request):
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
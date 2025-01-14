from django.shortcuts import render

# Create your views here.

from rest_framework.decorators import api_view
from rest_framework.response import Response


@api_view(['GET'])
def hello_world(request):
    return Response({'message': 'Hello, world!'})


class kanga_connection():
  def connect(request):
    pass
  
  
# backend functional code here or where you will post to

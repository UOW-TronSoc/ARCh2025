from django.shortcuts import render
from rest_framework.decorators import api_view
from rest_framework.views import APIView
from rest_framework.response import Response
from asgiref.sync import async_to_sync
import httpx



@api_view(['GET'])
def hello_world(request):
    return Response({'message': 'Hello, world!'})


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


# backend functional code here or where you will post to

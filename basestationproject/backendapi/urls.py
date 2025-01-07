from django.urls import path
from .views import *

urlpatterns = [
    path('hello-world/', hello_world, name='hello_world'),
    path('send-command/', SendCommandView.as_view(), name='send-command')
    # pages urls here
]
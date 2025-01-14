from django.urls import path
from .views import *

urlpatterns = [
    path('hello-world/', hello_world, name='hello_world'),
    path('kanga-connection/', kanga_connection.as_view(), name="kanga-connection"),
    
    # pages urls here
]
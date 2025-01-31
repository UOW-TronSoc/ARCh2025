from django.urls import path, include, re_path
from . import views

urlpatterns = [
    # path('send-drive-command/', views.SendCommandView.as_view(), name='send-command'),
    # path('publish-custom-message/', views.PublishCustomMessageView.as_view(), name='publish_custom_message'),

    # API endpoint to store mock device data in Redis
    path("store-devices", views.store_devices, name="store_devices"),

    # API endpoint to fetch connected devices data from Redis
    path("devices", views.get_devices, name="get_devices"),

    # API endpoint to store robo spec (inventory) data in Redis
    path("store-specs", views.get_robo_specs, name="store_specs"),

    # API endpoint to fetch robo spec (inventory) data from Redis
    path("specs", views.get_specs, name="get_specs"),

    # Optional: Endpoints for connecting and disconnecting the rover
    path("connect", views.connect_rover, name="connect_rover"),
    path("disconnect", views.disconnect_rover, name="disconnect_rover"),

    path('command/', views.RoverCommand.as_view(), name='rover-command'),
    path('arm-overview/', views.ArmOverview.as_view(), name='rover-arm-overview'),
    path('arm/activate/', views.ArmActivate.as_view(), name='arm-activate'),
    path('arm/deactivate/', views.ArmDeactivate.as_view(), name='arm-deactivate'),
    path('rover/move/', views.RoverMove.as_view(), name='rover-move'),
    path('rover/start/', views.RoverStart.as_view(), name='rover-start'),
    path('rover/stop/', views.RoverStop.as_view(), name='rover-stop'),

    path('video_feed/', views.get_frame, name='video_feed'),  # Updated


]
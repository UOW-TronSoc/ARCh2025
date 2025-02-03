from django.urls import path, include, re_path
from . import views

urlpatterns = [
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

    path('video_feed/<int:camera_id>/', views.get_frame, name='video_feed'),

    path('drivetrain-feedback/', views.get_drivetrain_feedback, name='drivetrain-feedback'),

    path('science-feedback/', views.get_science_feedback, name='science-feedback'),
    path('science-control/', views.set_science_control, name='science-control'),

    path('logs/', views.get_rover_logs, name='get_rover_logs'),



]
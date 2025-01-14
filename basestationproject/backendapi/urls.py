from django.urls import path
from . import views
from .views import *

urlpatterns = [
    path('kanga-connect/', KangaConnection.as_view(), name='Kanga Connection'),
    path('device-details/', DeviceDetails.as_view(), name='Device Details'),
    path('quick-overview/', QuickOverview.as_view(), name='Quick Overview'),
    path('robo-spec/', RoboSpec.as_view(), name='Robo Specs'),
    path('control-command-log-history/', ControlCommandLogHistory.as_view(), name='Control Command and Log History'),
    path('nli/', NLI_Section.as_view(), name='Natural Language Interface Section'),
    path('map-controls/', MapControls.as_view(), name='Map and Controls'),
    path('data-graph/', DataGraph.as_view(), name='Data Graph'),
    path('data-log-history', DataLogHistory.as_view(), name='Data Logging History'),
    
    # API endpoint to store mock device data in Redis
    path("api/store-devices", store_devices, name="store_devices"),

    # API endpoint to fetch connected devices data from Redis
    path("api/devices", get_devices, name="get_devices"),

    # API endpoint to store robo spec (inventory) data in Redis
    path("api/store-specs", get_robo_specs, name="store_specs"),

    # API endpoint to fetch robo spec (inventory) data from Redis
    path("api/specs", get_specs, name="get_specs"),

    # Optional: Endpoints for connecting and disconnecting the rover
    path("api/connect", connect_rover, name="connect_rover"),
    path("api/disconnect", disconnect_rover, name="disconnect_rover"),

    path('api/command/', RoverCommand.as_view(), name='rover-command'),
    path('api/arm-overview/', ArmOverview.as_view(), name='rover-arm-overview'),
    path('api/arm/activate/', ArmActivate.as_view(), name='arm-activate'),
    path('api/arm/deactivate/', ArmDeactivate.as_view(), name='arm-deactivate'),
    path('api/rover/move/', RoverMove.as_view(), name='rover-move'),
    path('api/rover/start/', RoverStart.as_view(), name='rover-start'),
    path('api/rover/stop/', RoverStop.as_view(), name='rover-stop'),
]

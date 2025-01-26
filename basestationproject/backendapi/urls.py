from django.urls import path
from .views import *

urlpatterns = [
    path('hello-world/', hello_world, name='hello_world'),
    # pages urls here
    path('logs/', Logs.as_view(), name='Logs'),
    path('kanga-connect/', KangaConnection.as_view(), name='Kanga Connection'),
    path('device-details/', DeviceDetails.as_view(), name='Device Details'),
    path('quick-overview/', QuickOverview.as_view(), name='Quick Overview'),
    path('robo-spec/', RoboSpec.as_view(), name='Robo Specs'),
    path('control-command-log-history/', ControlCommandLogHistory.as_view(), name='Control Command and Log History'),
    path('nli/', NLI_Section.as_view(), name='Natural Language Interface Section'),
    path('map-controls/', MapControls.as_view(), name='Map and Controls'),
    path('data-graph/', DataGraph.as_view(), name='Data Graph'),
    path('data-log-history', DataLogHistory.as_view(), name='Data Logging History'),
]
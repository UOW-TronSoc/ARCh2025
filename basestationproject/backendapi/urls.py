from django.urls import path
from .views import *

urlpatterns = [
    path('hello-world/', hello_world, name='hello_world'),
    path('send-command/', SendCommandView.as_view(), name='send-command'),
    path('publish-custom-message/', PublishCustomMessageView.as_view(), name='publish_custom_message'),

    # pages urls here
]
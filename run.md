
1) python manage.py runserver
2) uvicorn main:app --host 127.0.0.1 --port 8001
3) python command_listener.py

curl -X POST http://127.0.0.1:8000/api/publish-custom-message/ -H "Content-Type: application/json" -d '{"epoch_time": 1673032025, "data": "Hello from Django!", "flag": true}'

Overwritten epoch_time

# Running ROS Docker

Install Docker on your machine. Follow the instructions on the official website to install Docker on your machine.
[Docker Installation](https://docs.docker.com/get-docker/)

Once Docker engine is installed and running:

1. Run command inside the folder where Dockerfile is present:

```
docker build -t ros2-humble .
```

2. Run command to start the ROS container:

```
docker run -it --rm -v ./ros2_ws:/ros2_ws -p 9090:9090 ros2-humble
```

3. Once a ROS container is running, to start a new terminal session in the same container

```
docker ps
```

```
docker exec -it <container_name_or_id> /bin/bash
```

4. To create a new ROS2 package for ROS comms:

```
ros2 pkg create ros_django_comms --build-type ament_python
```

5. To run the ROS2 bridge server:

```
ros2 launch rosbridge_server rosbridge_websocket_launch.xml
```



curl -X POST "http://127.0.0.1:8080/command" -H "Content-Type: application/json" -d '{"left_drive": 50, "right_drive": -50}'

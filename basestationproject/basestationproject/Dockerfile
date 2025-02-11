FROM python:3.10

WORKDIR /app

COPY ../requirements.txt .
RUN pip install -r requirements.txt

COPY . .

# Set up ROS2
RUN echo "source /ros2_ws/install/setup.bash" >> ~/.bashrc
CMD ["bash", "-c", "source /ros2_ws/install/setup.bash && python3 manage.py runserver 0.0.0.0:8000"]
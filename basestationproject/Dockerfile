# Base ROS 2 Humble image
FROM ros:humble-ros-base

# Install system dependencies, including supervisor, Python, and Node.js
RUN apt-get update && apt-get install -y \
    python3-pip \
    python3-colcon-common-extensions \
    ros-humble-rclpy \
    ros-humble-std-msgs \
    ros-humble-sensor-msgs \
    supervisor \
    nodejs \
    npm \
    && apt-get clean

# Set the working directory
WORKDIR /app

# Create logs directory
RUN mkdir -p /app/logs

# Install Python dependencies for Django and FastAPI
COPY requirements.txt /app/
RUN pip install --no-cache-dir -r requirements.txt

# Copy the project files into the container
COPY basestationproject/ /app/basestationproject/
COPY backendapi/ /app/backendapi/
COPY fastapi_server/ /app/fastapi_server/
COPY ros2_nodes/ /app/ros2_nodes/
COPY frontend/ /app/frontend/

# Build React frontend
WORKDIR /app/frontend/my-react-app
RUN npm install
RUN npm run build

# Return to app directory
WORKDIR /app

# Copy supervisord configuration
COPY supervisord.conf /app/supervisord.conf

# Expose the necessary ports
EXPOSE 8000 8001 3000

# Command to start supervisord
CMD ["supervisord", "-c", "/app/supervisord.conf"]

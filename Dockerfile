# Use the official ROS 2 Humble base image
FROM ros:humble

# Set environment variables
ENV DEBIAN_FRONTEND=noninteractive

# Update the package list and install necessary tools
RUN apt-get update && \
    apt-get install -y --no-install-recommends \
        build-essential \
        git \
        python3-pip \
        python3-colcon-common-extensions && \
    rm -rf /var/lib/apt/lists/*

# Install additional dependencies (example, adjust as needed)
RUN apt-get update && \
    apt-get install -y --no-install-recommends \
        ros-humble-demo-nodes-cpp \
        ros-humble-demo-nodes-py \
        ros-humble-rosbridge-server && \
    rm -rf /var/lib/apt/lists/*

# Create a workspace directory
WORKDIR /ros2_ws

# Copy your ROS 2 workspace (adjust the source path if needed)
# Ensure your workspace includes "src" folder and any packages you want to build
COPY ./ros2_ws /ros2_ws

# Build the ROS 2 workspace
RUN . /opt/ros/humble/setup.sh && \
    colcon build

# Source the ROS 2 setup script and workspace setup script
CMD ["/bin/bash", "-c", "source /opt/ros/humble/setup.sh && source /ros2_ws/install/setup.sh && bash"]
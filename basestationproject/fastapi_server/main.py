from fastapi import FastAPI, HTTPException
import rclpy
from rclpy.node import Node
from rclpy.action import ActionClient
from std_msgs.msg import String
import asyncio

app = FastAPI()

# Initialize ROS 2 node outside the FastAPI lifecycle
class ROS2Client:
    def __init__(self):
        rclpy.init()
        self.node = rclpy.create_node('fastapi_ros2_client')
        self.publisher = self.node.create_publisher(String, 'commands', 10)
        self.action_client = None  # Set this up if using ROS actions

    def publish_command(self, command: str):
        msg = String()
        msg.data = command
        self.publisher.publish(msg)
        self.node.get_logger().info(f"Published command: {command}")

    async def send_goal(self, command: str):
        # Example of sending a goal if using an action client
        goal_msg = YourAction.Goal()
        goal_msg.command = command

        if not self.action_client.wait_for_server(timeout_sec=5.0):
            raise HTTPException(status_code=500, detail="Action server not available")

        goal_future = self.action_client.send_goal_async(goal_msg)
        goal_handle = await goal_future

        if not goal_handle.accepted:
            raise HTTPException(status_code=500, detail="Goal rejected by action server")

        # Wait for result
        result_future = goal_handle.get_result_async()
        result = await result_future
        return result.result.feedback

ros2_client = ROS2Client()

@app.post("/command")
async def handle_command(data: dict):
    command = data.get("command")
    if not command:
        raise HTTPException(status_code=400, detail="Command not provided")

    try:
        ros2_client.publish_command(command)  # Publish directly to a topic
        # Alternatively, use send_goal if using an action
        return {"status": "success", "message": f"Command '{command}' sent"}
    except Exception as e:
        raise HTTPException(status_code=500, detail=str(e))

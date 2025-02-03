from fastapi import FastAPI, HTTPException
from fastapi.middleware.cors import CORSMiddleware
from pydantic import BaseModel
import rclpy
from rclpy.node import Node
from custom_msgs.msg import DrivetrainControl
import time

print("starting?")

# Initialize the FastAPI app
app = FastAPI()

# Add CORS middleware
app.add_middleware(
    CORSMiddleware,
    allow_origins=["*"],  # Allows all origins. Replace with specific URLs for production
    allow_credentials=True,
    allow_methods=["*"],  # Allows all HTTP methods
    allow_headers=["*"],  # Allows all headers
)

# Define a Pydantic model for request validation
class DriveCommand(BaseModel):
    left_drive: int
    right_drive: int

# ROS 2 Node to handle publishing
class ROS2Client:
    def __init__(self):
        try:
            rclpy.init()
            self.node = rclpy.create_node('fastapi_ros2_client')
            self.publisher = self.node.create_publisher(DrivetrainControl, 'drive_commands', 10)
            self.node.get_logger().info("ROS2Client initialized successfully!")
        except Exception as e:
            print(f"Error initializing ROS2Client: {e}")
            raise

    def publish_drive_command(self, left_drive: int, right_drive: int):
      try:
          msg = DrivetrainControl()
          msg.epoch_time = int(time.time() * 1000)  # Current epoch time in milliseconds
        #   msg.data = "Joystick command"
        #   msg.flag = True

          # Ensure values fit within int8 range (-128 to 127)
          if not (-128 <= left_drive <= 127):
              raise ValueError(f"left_drive value {left_drive} is out of range for int8")
          if not (-128 <= right_drive <= 127):
              raise ValueError(f"right_drive value {right_drive} is out of range for int8")

          msg.lf_drive = left_drive
          msg.lb_drive = left_drive
          msg.rb_drive = right_drive
          msg.rf_drive = right_drive

          # Debug logs
          """self.node.get_logger().info(
              f"Publishing: left_drive={left_drive}, right_drive={right_drive}"
          )"""

          # Publish the message
          self.publisher.publish(msg)
          """self.node.get_logger().info("Drive command published successfully!")"""

      except Exception as e:
          self.node.get_logger().error(f"Unexpected error: {e}")
          raise


# Initialize ROS2Client
ros2_client = ROS2Client()

@app.post("/command")
async def handle_command(command: DriveCommand):
    # Endpoint to handle joystick drive commands sent from the frontend.
    try:
        # Extract validated data from the Pydantic model
        left_drive = command.left_drive
        right_drive = command.right_drive

        # Log incoming data for debugging
        # print(f"Received command: left_drive={left_drive} (type={type(left_drive)}), right_drive={right_drive} (type={type(right_drive)})")

        # Validate range of the inputs
        if not (-100 <= left_drive <= 100) or not (-100 <= right_drive <= 100):
            raise HTTPException(status_code=400, detail="Drive values must be between -100 and 100")

        # Publish to ROS 2 topic
        ros2_client.publish_drive_command(left_drive, right_drive)
        return {"status": "success", "message": "Drive command sent successfully"}

    except Exception as e:
        print(f"Error while processing command: {e}")
        raise HTTPException(status_code=500, detail=str(e))

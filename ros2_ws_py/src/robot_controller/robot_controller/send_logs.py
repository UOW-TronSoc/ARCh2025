import rclpy
from rclpy.node import Node
from std_msgs.msg import String
import time

class RoverLogsPublisher(Node):
    """Publisher node to send test logs to the Rover_Logs topic."""
    def __init__(self):
        super().__init__('rover_logs_publisher')
        self.publisher_ = self.create_publisher(String, 'Rover_Logs', 10)

    def send_log(self, message):
        """Send a log message to the topic."""
        msg = String()
        msg.data = message
        self.publisher_.publish(msg)
        self.get_logger().info(f"Sent log: {message}")

def main():
    rclpy.init()
    node = RoverLogsPublisher()

    try:
        counter = 1
        while rclpy.ok():
            log_message = f"Test Log Entry {counter}: System Check OK"
            node.send_log(log_message)
            counter += 1
            time.sleep(2)  # Send a log every 2 seconds
    except KeyboardInterrupt:
        node.get_logger().info("Shutting down log publisher...")
    finally:
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()

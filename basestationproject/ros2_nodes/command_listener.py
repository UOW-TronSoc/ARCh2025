import rclpy
from rclpy.node import Node
from std_msgs.msg import String

class CommandListener(Node):
    def __init__(self):
        super().__init__('command_listener')
        self.subscription = self.create_subscription(
            String,
            'commands',
            self.listener_callback,
            10
        )

    def listener_callback(self, msg):
        self.get_logger().info(f"Received command: {msg.data}")
        # Add logic to handle commands (e.g., motor control, task execution)

def main(args=None):
    rclpy.init(args=args)
    node = CommandListener()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()

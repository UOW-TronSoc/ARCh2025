import rclpy
from rclpy.node import Node
from std_msgs.msg import String  # Replace with your message type if custom

class CommandListener(Node):
    def __init__(self):
        super().__init__('command_listener')
        self.subscription = self.create_subscription(String, 'commands', self.listener_callback, 10)
        self.publisher = self.create_publisher(String, 'example_topic', 10)
        self.get_logger().info("Command Listener Node Initialized.")


    def listener_callback(self, msg):
        self.get_logger().info(f"Received command: {msg.data}")
        # Process and republish to example_topic
        response = f"Processed: {msg.data}"  # Simulated processing
        out_msg = String()
        out_msg.data = response
        self.publisher.publish(out_msg)
        self.get_logger().info(f"Published to 'example_topic': {response}")



# Placeholder functions for processing specific commands
def blackbox_control(command):
    """
    Processes control commands (e.g., for chassis movement).
    """
    # Simulate control logic (e.g., move forward, stop, etc.)
    if "move" in command:
        return "Chassis moving forward"
    elif "stop" in command:
        return "Chassis stopped"
    return "Unknown control command"


def blackbox_arm(command):
    """
    Processes arm commands (e.g., pick, place, etc.).
    """
    # Simulate robotic arm logic
    if "pick" in command:
        return "Arm picking object"
    elif "place" in command:
        return "Arm placing object"
    return "Unknown arm command"


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

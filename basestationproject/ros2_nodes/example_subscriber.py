import rclpy
from rclpy.node import Node
from std_msgs.msg import String


class ExampleSubscriber(Node):
    def __init__(self):
        super().__init__('example_subscriber')
        self.subscription = self.create_subscription(String, 'example_topic', self.listener_callback, 10)
        self.get_logger().info("Example Subscriber Node Initialized.")

    def listener_callback(self, msg):
        self.get_logger().info(f"Received on 'example_topic': {msg.data}")


def main(args=None):
    rclpy.init(args=args)
    node = ExampleSubscriber()

    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()

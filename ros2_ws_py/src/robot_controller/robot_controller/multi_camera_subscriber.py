import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
from cv_bridge import CvBridge
import cv2
import numpy as np
from collections import deque

class MultiCameraSubscriber(Node):
    def __init__(self):
        super().__init__('multi_camera_subscriber')

        # Define camera topics
        self.camera_topics = [
            "/camera_0/image_raw",
            "/camera_1/image_raw",
            "/camera_2/image_raw",
            "/camera_3/image_raw"
        ]

        # Create CvBridge for image conversion
        self.bridge = CvBridge()

        # Create dictionary to store images
        self.image_buffers = {topic: deque(maxlen=1) for topic in self.camera_topics}

        # Create subscribers dynamically
        self.subscribers = []
        for topic in self.camera_topics:
            sub = self.create_subscription(Image, topic, self.image_callback, 10)
            self.subscribers.append(sub)
            self.get_logger().info(f"Subscribed to {topic}")

        # Create a timer to update display
        self.create_timer(0.1, self.update_display)

    def image_callback(self, msg):
        """Callback for receiving images from cameras."""
        try:
            # Convert ROS Image message to OpenCV format
            cv_image = self.bridge.imgmsg_to_cv2(msg, desired_encoding="bgr8")

            # Identify camera from topic name
            camera_topic = msg.header.frame_id if msg.header.frame_id else "unknown"

            # Store latest image in queue
            if camera_topic in self.image_buffers:
                self.image_buffers[camera_topic].append(cv_image)

        except Exception as e:
            self.get_logger().error(f"Error processing image: {str(e)}")

    def update_display(self):
        """Combines images from all cameras and displays them in one window."""
        image_list = []
        blank_image = np.zeros((480, 640, 3), dtype=np.uint8)  # Placeholder if camera missing

        for topic in self.camera_topics:
            if self.image_buffers[topic]:
                img = self.image_buffers[topic][-1]  # Get latest image
            else:
                img = blank_image  # Use blank image if no feed

            # Resize for uniformity
            img = cv2.resize(img, (320, 240))
            image_list.append(img)

        # Arrange images in 2x2 grid
        row1 = np.hstack(image_list[:2])  # First two cameras
        row2 = np.hstack(image_list[2:])  # Next two cameras
        combined_image = np.vstack([row1, row2])  # Stack into final display

        # Show the combined frame
        cv2.imshow("Multi-Camera View", combined_image)
        cv2.waitKey(1)

def main(args=None):
    rclpy.init(args=args)
    node = MultiCameraSubscriber()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        node.get_logger().info("Shutting down")
    finally:
        node.destroy_node()
        rclpy.shutdown()
        cv2.destroyAllWindows()

if __name__ == '__main__':
    main()

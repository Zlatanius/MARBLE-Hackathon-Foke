import rclpy
from rclpy.node import Node

import cv2
from sensor_msgs.msg import Image
from cv_bridge import CvBridge


class UnityImageSubscriber(Node):

    def __init__(self):
        super().__init__('minimal_subscriber')
        self.subscription = self.create_subscription(
            Image,
            '/floater/microscope',
            self.listener_callback,
            10)
        self.subscription  # prevent unused variable warning

        self.bridge = CvBridge()

    def listener_callback(self, msg):
        self.get_logger().info("Image received from microscope")
        image = self.bridge.imgmsg_to_cv2(msg)
        cv2.imshow("new_window", image)
        cv2.waitKey(1) # for some reason this is necessary 

def main(args=None):
    rclpy.init(args=args)
    unityImageSubscriber = UnityImageSubscriber()
    rclpy.spin(unityImageSubscriber)
    unityImageSubscriber.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()


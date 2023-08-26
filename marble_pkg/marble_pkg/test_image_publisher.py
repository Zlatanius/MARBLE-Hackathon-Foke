import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image

from cv_bridge import CvBridge
import cv2
import os
import numpy as np

class TestImagePublisher(Node):
    def __init__(self): 
        super().__init__('image_publisher')
        self.publisher_ = self.create_publisher(Image, 'image_topic', 10) ###### here
        timer_period = 30  # seconds
        self.timer = self.create_timer(timer_period, self.timer_callback)
        self.image_list = []

        test_dir = "/home/adna/ros2_ws/src/marble_pkg/marble_pkg/test_images"
        image_filenames = [filename for filename in os.listdir(test_dir)]

        for filename in image_filenames:
            full_path = test_dir + '/' + filename
            if(os.path.isfile(full_path)):
                self.image_list.append(cv2.imread(full_path, cv2.IMREAD_COLOR))

        self.bridge = CvBridge()
        self.image_counter = 0

    def timer_callback(self):
        image_to_send = self.image_list[self.image_counter]

        my_msg = self.bridge.cv2_to_imgmsg(np.array(image_to_send, dtype=np.uint8), "bgr8")

        self.publisher_.publish(my_msg) 
        self.get_logger().info('Publishing an image')
        self.image_counter = self.image_counter + 1
        if(self.image_counter == 4):
            self.image_counter = 0


def main(args=None):

    rclpy.init(args=args)
    image_publisher = TestImagePublisher()
    rclpy.spin(image_publisher)
    image_publisher.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
     main()
import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image # Pripazite da je dobar tip poruke sa topica /microscope (message type)
import numpy as np
from roboflow import Roboflow
from custom_msgs.msg import CountWithFloaterInfo
import cv2
from cv_bridge import CvBridge

class InferenceNode(Node):
    def __init__(self):
        super().__init__('inference_node')
        rf = Roboflow(api_key="y7AJ0XS1QYZYxBZMhLYw")
        project = rf.workspace("marbleyolov8").project("marble_yolov8")
        self.model = project.version(4).model
        self.get_logger().info("The model should be loaded and ready to go") #this is okay and working so far

        self.bridge = CvBridge()
        
        self.subscriber_1 = self.create_subscription(Image, '/floater1/microscope', self.callback, 10)
        self.subscriber_2 = self.create_subscription(Image, '/floater2/microscope', self.callback, 10)
        self.subscriber_3 = self.create_subscription(Image, '/floater3/microscope', self.callback, 10)

        self.publisher_ = self.create_publisher(CountWithFloaterInfo, 'count_topic', 30)

    def cv_size(self, img):
        return tuple(img.shape[1::-1])

    def callback(self, msg):
        caller_id = msg.header.frame_id
        strings = caller_id.split("/", 2)
        caller_id = strings[0]

        #self.get_logger().info('A new image is being processed')
        image = self.bridge.imgmsg_to_cv2(msg)
        if(self.cv_size(image) == (6000, 4000)):
            new_size = (1500, 1000)
            image = cv2.resize(image, new_size, interpolation=cv2.INTER_AREA)

        dictionary = self.model.predict(image, confidence=34, overlap=40).json() 

        larvae_counter = 0

        for prediction in dictionary["predictions"]:
            if(prediction["class"] == "larva"):
                larvae_counter = larvae_counter + 1

        my_msg = CountWithFloaterInfo()
        my_msg.floater_info = caller_id
        my_msg.larvae_count = larvae_counter

        self.publisher_.publish(my_msg) 
        #self.get_logger().info('Floater ' + str(caller_id) + ' has found ' + str(larvae_counter) + ' larvae')
        # this is to check the state of the tracking node
        # looks like it has an issue, these are working as expected

def main(args=None):
    rclpy.init(args=args)
    node = InferenceNode()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
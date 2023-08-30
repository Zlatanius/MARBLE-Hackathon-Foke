import rclpy
from rclpy.node import Node
from roboflow import Roboflow
from cv_bridge import CvBridge
import cv2
import numpy as np

from std_msgs.msg import UInt16
from sensor_msgs.msg import Image

class SingleFloaterInferenceNode(Node):
    def __init__(self):
        super().__init__("inference_node")
        self.get_logger().info("This node performs inference on images from the floater/microscope node")
        self.bridge = CvBridge()

        rf = Roboflow(api_key="y7AJ0XS1QYZYxBZMhLYw")
        project = rf.workspace("marbleyolov8").project("marble_yolov8")
        self.model = project.version(4).model
        self.get_logger().info("The model should be loaded and ready to go") #this is okay and working so far

    # ovaj node mora biti i subscriber i publisher
    # prvo se subscribea pa onda pravi predikciju i nju publisha
        self.subscription = self.create_subscription(
            Image,
            '/floater/microscope', # topic for testing: image_topic, topic for unity evaluation: /floater/microscope
            self.listener_callback,
            1)
        self.subscription  # prevent unused variable warning

        self.publisher_ = self.create_publisher(UInt16, 'count_topic', 30)

    def cv_size(self, img):
        return tuple(img.shape[1::-1])
    
    def listener_callback(self, msg):
        self.get_logger().info('A new image is being processed')
        image = self.bridge.imgmsg_to_cv2(msg)
        if(self.cv_size(image) == (6000, 4000)):
            new_size = (3000, 2000)
            image = cv2.resize(image, new_size, interpolation=cv2.INTER_AREA)
        #cv2.imshow("new_window", image)
        #cv2.waitKey(1)

        dictionary = self.model.predict(image, confidence=34, overlap=40).json() 
        # if there are different image sizes, it will probably work with just adjusting the confidence levels 
        # for image size 6000 x 4000 confidence of 34 is best, for lower it may even need 20
        # predictions are really good for a lower number of larvae, the higher one is a bit off
        # but still very large in comparison with the rest of the dataset

        larvae_counter = 0

        for prediction in dictionary["predictions"]:
            if(prediction["class"] == "larva"):
                larvae_counter = larvae_counter + 1

        my_msg = UInt16()
        my_msg.data = larvae_counter

        self.publisher_.publish(my_msg) # custom message
        self.get_logger().info('Publishing the number of larvae')
        

    # svi floateri objavljuju na zajednicki floater/microscope topic 


def main(args=None):
    rclpy.init(args=args)
    node = SingleFloaterInferenceNode()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == "__main__":
    main()

# the images are working just fine, but i left the script in its old version 
# because the new one was slowing my computer down a bunch

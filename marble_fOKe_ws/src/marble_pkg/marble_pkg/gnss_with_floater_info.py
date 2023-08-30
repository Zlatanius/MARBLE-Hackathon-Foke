import rclpy
from rclpy.node import Node

from sensor_msgs.msg import NavSatFix
from custom_msgs.msg import LocationWithFloaterInfo

class GNSSWithFloaterInfoPublisher(Node):
    def __init__(self):
        super().__init__('gnss_repacking_node')
        
        self.publisher_ = self.create_publisher(LocationWithFloaterInfo, 'location_topic', 30)

        self.subscriber_1 = self.create_subscription(NavSatFix, '/floater1/gnss', self.callback, 10)
        self.subscriber_2 = self.create_subscription(NavSatFix, '/floater2/gnss', self.callback, 10)
        self.subscriber_3 = self.create_subscription(NavSatFix, '/floater3/gnss', self.callback, 10)
 
    def callback(self, msg):
        caller_id = msg.header.frame_id
        strings = caller_id.split("/", 2)
        caller_id = strings[0]
        
        #self.get_logger().info(f'From {caller_id}: "{(msg.latitude, msg.longitude, msg.altitude)}"')
        new_msg = LocationWithFloaterInfo()
        new_msg.floater_info = caller_id 
        new_msg.latitude = msg.latitude
        new_msg.longitude = msg.longitude
        new_msg.altitude = msg.altitude

        self.publisher_.publish(new_msg) # custom message

def main(args=None):
    rclpy.init(args=args)
    node = GNSSWithFloaterInfoPublisher()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
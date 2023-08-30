# Copyright 2016 Open Source Robotics Foundation, Inc.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

import rclpy
from rclpy.node import Node
from geometry_msgs.msg import PoseWithCovarianceStamped  
from sensor_msgs.msg import NavSatFix
from std_msgs.msg import String
from custom_msgs.msg import CommsMessage

class GeoCaller(Node):

    def __init__(self):
        super().__init__('geofloater_node')
        self.publisher_ = self.create_publisher(String, 'geofloater', 10)
        self.publisher_freedom = self.create_publisher(String, 'floater1/freetodrown', 10)
        self.subscription_depth1 = self.create_subscription(
        	PoseWithCovarianceStamped,
        	'floater1/depth', 
        	self.depth_callback,
        	10
        )    
        # this section needs to be uncommented for the integration with communication node
        # of course communication node and larvae ident node must be running
         
        #self.subscription_lastfullframe = self.create_subscription(
        #	CommsMessage,
        #	'comms_topic/last_full_frame', 
        #	self.full_frame_callback,
        #	10
        #)
        
        # this section is simulating the communication and larvae indent node where it 
        # simulates the message on last_full_frame
        # generally it doesn't matter what is published it is just forwarded by the floater 
        # that is surfacing in a string format
        # this section needs to be commented when the integration is done
        
        self.subscription_lastfullframe = self.create_subscription(
            String,
            'topic',
            self.full_frame_callback,
            10
        )
        #timer_period = 0.5  # seconds
        #self.timer = self.create_timer(timer_period, self.timer_callback)
        self.data_to_publish = 'I am on the surface' 

    def depth_callback(self, msg):
        self.get_logger().info('Surfacing mode | Current depth: %s' % msg.pose.pose.position.z)
        if msg.pose.pose.position.z < 9: # on the surface (oscillating between 6.5 and 8.5)
            self.publish_data()
            poruka = String()
            poruka.data = '1'
            if msg.pose.pose.position.z < 7.5: #not to be instant so that the publishing can happen
                self.publisher_freedom.publish(poruka) # can drown again
    
    def full_frame_callback(self, msg):
        self.data_to_publish = msg
        poruka = String()
        poruka.data = '0'
        self.publisher_freedom.publish(poruka) # received full frame message with information of all floaters
                                            # cant be drown, beggining surfacing
        self.get_logger().info('Received message: "%s"' % msg.data)
        

    def publish_data(self):
        msg = String()
        msg.data = str(self.data_to_publish)
        self.get_logger().info('Geocall mode | Publishing: "%s"' % msg.data)
        self.publisher_.publish(msg)


def main(args=None):
    rclpy.init(args=args)

    geofloater_node = GeoCaller()

    rclpy.spin(geofloater_node)

    # Destroy the node explicitly
    # (optional - otherwise it will be done automatically
    # when the garbage collector destroys the node object)
    geofloater_node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()

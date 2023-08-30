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
from std_msgs.msg import String, Float32MultiArray


class SurfacingController(Node):

    def __init__(self):
        super().__init__('surfacing_node')
        self.publisher_1 = self.create_publisher(Float32MultiArray, 'floater1/volume_disp', 10)
        self.publisher_2 = self.create_publisher(Float32MultiArray, 'floater2/volume_disp', 10)
        self.publisher_3 = self.create_publisher(Float32MultiArray, 'floater3/volume_disp', 10)
        self.subscriptionfloater1 = self.create_subscription(
        	PoseWithCovarianceStamped,
        	'floater1/depth',
        	self.depth_callback1,
        	10
        )
        self.subscriptionfloater2 = self.create_subscription(
        	PoseWithCovarianceStamped,
        	'floater2/depth',
        	self.depth_callback2,
        	10
        )
        self.subscriptionfloater3 = self.create_subscription(
        	PoseWithCovarianceStamped,
        	'floater3/depth',
        	self.depth_callback3,
        	10
        )          	
        self.subscriptionfreefloater1 = self.create_subscription(
        	String,
        	'floater1/freetodrown', # topic that tells if the floater1 isnt surfacing
        	self.free_floater1,
        	10
        )    
        self.subscriptionfreefloater2 = self.create_subscription(
        	String,
        	'floater2/freetodrown', # topic that tells if the floater2 isnt surfacing
        	self.free_floater1,
        	10
        ) 
        self.subscriptionfreefloater3 = self.create_subscription(
        	String,
        	'floater3/freetodrown', # topic that tells if the floater3 isnt surfacing
        	self.free_floater1,
        	10
        )     	
        # can be drown at the begging
        self.free_floater1 = 1 
        self.free_floater2 = 1 
        self.free_floater3 = 1 
        #timer_period = 0.5  # seconds
        #self.timer = self.create_timer(timer_period, self.timer_callback)
        self.data_to_publish1 = [30] # change for 50 for a working script
        self.data_to_publish2 = [30] # change for 50 for a working script
        self.data_to_publish3 = [30] # change for 50 for a working script
################################################################################
###################      SELF REGULATING AT DEPTH SCRIPTS  #####################
################################################################################

    def depth_callback1(self, msg):
        if msg.pose.pose.position.z < 20: # max. depth for finding larvAE
            #self regulating at depth: 30
            self.data_to_publish1 = [5] # going down up to depth of 30
            self.publish_data1()
            self.get_logger().info('Drowning mode(floater:1)')
        else:
            self.data_to_publish1 = [30] #going up
            self.publish_data1()
            self.get_logger().info('Balancing mode(floater:1)')
            
    def depth_callback2(self, msg):
        if msg.pose.pose.position.z < 20: # max. depth for finding larvAE
            #self regulating at depth: 30
            self.data_to_publish2 = [5] # going down
            self.publish_data2()
            #self.get_logger().info('Drowning mode(floater:2)')
        else:
            self.data_to_publish2 = [30] #going up
            self.publish_data2()
            #self.get_logger().info('Balancing mode(floater:2)')
            
    def depth_callback3(self, msg):
        if msg.pose.pose.position.z < 20: # max. depth for finding larvAE
            #self regulating at depth: 30
            self.data_to_publish3 = [5] # going down
            self.publish_data3()
            self.get_logger().info('Drowning mode(floater:3)')
        else:
            self.data_to_publish3 = [30] #going up
            self.publish_data3()
            self.get_logger().info('Balancing mode(floater:3)')
#################################################################################            
    def free_floater1(self, msg):
        #self.get_logger().info('Watching mode | Received: %s' % msg.data)
        try:
            extracted = [int(s) for s in msg.data.split() if s.isdigit()]
            if all(val > 0 for val in extracted):
                self.free_floater1 = 1 
            else:
            	self.free_floater1 = 0
            	poruka = Float32MultiArray(data=[50])
            	self.publisher_1.publish(poruka) #beggining surfacing
        except ValueError:
                self.get_logger().error('Unsuccesful data extraction with floater1/freetodrown')

    def free_floater2(self, msg):
        #self.get_logger().info('Watching mode | Received: %s' % msg.data)
        try:
            extracted = [int(s) for s in msg.data.split() if s.isdigit()]
            if all(val > 0 for val in extracted):
                self.free_floater2 = 1 
            else:
            	self.free_floater2 = 0
        except ValueError:
                self.get_logger().error('Unsuccesful data extraction with floater2/freetodrown')
                
    def free_floater3(self, msg):
        #self.get_logger().info('Watching mode | Received: %s' % msg.data)
        try:
            extracted = [int(s) for s in msg.data.split() if s.isdigit()]
            if all(val > 0 for val in extracted):
                self.free_floater3 = 1 
            else:
            	self.free_floater3 = 0
        except ValueError:
                self.get_logger().error('Unsuccesful data extraction with floater3/freetodrown')
################################################################################
###################      SELF REGULATING AT DEPTH publish  #####################
################################################################################		
    def publish_data1(self):
        if self.free_floater1 == 1:
            msg = Float32MultiArray(data=self.data_to_publish1)
            self.publisher_1.publish(msg)
            self.get_logger().info('(floater:1) | Publishing: "%s"' % msg.data)

    def publish_data2(self):
    	if self.free_floater2 == 1:
            msg = Float32MultiArray(data=self.data_to_publish2)
            self.publisher_2.publish(msg)
            #self.get_logger().info('(floater:2) | Publishing: "%s"' % msg.data)
        
    def publish_data3(self):
        if self.free_floater3 == 1:
            msg = Float32MultiArray(data=self.data_to_publish3)
            self.publisher_3.publish(msg)
            self.get_logger().info('(floater:3) | Publishing: "%s"' % msg.data)
        
################################################################################


def main(args=None):
    rclpy.init(args=args)

    surfacing_node = SurfacingController()

    rclpy.spin(surfacing_node)

    # Destroy the node explicitly
    # (optional - otherwise it will be done automatically
    # when the garbage collector destroys the node object)
    surfacing_node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()

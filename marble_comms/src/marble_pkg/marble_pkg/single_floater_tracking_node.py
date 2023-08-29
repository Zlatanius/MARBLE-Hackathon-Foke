# this node in ROS2 should track the count, location and sample and calculates the concentration and gradient
# the count is easy to track, we can just make the inference_node a publisher as well and make this node listen to its topic
# location can be tracked from another node where buoys can for now just publish their x y and z coordinates
# we could just get this from the gnss node for now! 
# that is until we find an algorithm to do that
# QUESTION: what does sample mean in the hackathon proposition?

# we can start by making the node listen to the count - that's done
# now, we should track locations from another node... ideally, now we could connect the simulator to these nodes
# this could be done using their grpc server thing
# for the ros nodes, we could just change the topics so that they match the topics for the floater


import rclpy
from rclpy.node import Node

from std_msgs.msg import UInt16
from sensor_msgs.msg import NavSatFix
import numpy as np

class SingleFloaterTrackingNode(Node):

    def __init__(self):
        super().__init__('tracking_node')
        self.subscription_count = self.create_subscription(
            UInt16,
            'count_topic',
            self.listener_callback_count,
            20)
        self.subscription_count 

        self.previous_floater_position = ()
        self.current_floater_position = ()
        self.previous_larvae_count = 0
        self.current_larvae_count = 0

        self.sample_count = 0

        self.concentration_list = []

        self.subscription_location = self.create_subscription(
            NavSatFix,
            '/floater/gnss',
            self.listener_callback_location,
            20)
        self.subscription_location

    def listener_callback_count(self, msg):
        self.previous_larvae_count = self.current_larvae_count
        self.current_larvae_count = msg.data
        self.sample_count = self.sample_count + 1
        self.get_logger().info('Current concentration: %s larvae/ml' % self.current_larvae_count)
        self.get_logger().info('Concentration calculated for sample number ' + str(self.sample_count))

        # after we get the larvae count, that's when we should look out for the position

        # when new larvae data is gathered, we perform the calculations
        # QUESTION: how do we store the concentrations? only the best ones and their locations or what exactly?

        if(self.current_floater_position != () and self.previous_floater_position != ()):
            diff_latitude = (self.current_floater_position[0] - self.previous_floater_position[0]) 
            diff_longitude = (self.current_floater_position[1] - self.previous_floater_position[1])  
            diff_altitude = (self.current_floater_position[2] - self.previous_floater_position[2]) 

            diff_concentration = self.current_larvae_count - self.previous_larvae_count

            gradient_latitude = float(diff_concentration) / np.abs(diff_latitude * 111.139)
            gradient_longitude = float(diff_concentration) / np.abs(diff_longitude * 111.139)
            gradient_altitude = float(diff_concentration) / np.abs(diff_altitude * 111.139)

            if(np.abs(gradient_latitude) > 0 and np.abs(gradient_latitude) < 5):
            # also here, in our case there will be 
            # no diff in latitude or longitude, that has to be fixed
                self.get_logger().info('Latitude component of gradient: %s larvae/meter' % str(gradient_latitude))
            if(np.abs(gradient_longitude) > 0 and np.abs(gradient_longitude) < 5):
                self.get_logger().info('Longitude component of gradient: %s larvae/meter' % str(gradient_longitude))
            if(np.abs(gradient_altitude) > 0 and np.abs(gradient_altitude) < 5):
                self.get_logger().info('Altitude component of gradient: %s larvae/meter' % str(gradient_altitude))

            if(diff_concentration != 0): # kad god ima ikakva promjena
                self.concentration_list.append((self.current_larvae_count, self.current_floater_position, self.sample_count))
                self.get_logger().info('Concentrations so far: ' + str(self.concentration_list))

    def listener_callback_location(self, msg):
        self.previous_floater_position = self.current_floater_position
        self.current_floater_position = (msg.latitude, msg.longitude, msg.altitude) 
        # this is only a quick fix until the actual location algorithms are implemented, just so we have a complete node
        self.get_logger().info('Data from GPS: %s' % str(self.current_floater_position))

        # we need to keep track of the direction of motion
        # for altitude it is clear, if we move downward, there is an inc
        # this condition is not good, we need to fix it
        # because none of this text is currently being displayed

        # how do we store the information?

        # gradients in terms of location can be calculated for the x, y and z axis separately 
        # just the difference between two last evaluated concentrations divided by the difference between two positions 
        # on x, y and z axis

        # since the info is being delivered in terms of latitude, longitude and altitude, there needs to be some kind 
        # of conversion enabled
        # QUESTION: the conversion between meters and latitude/longitude differences is just that we have to multiply the 
        # differences by 111.139, does that go for altitude as well?

        # also, we need to make this so that it takes the coordinates when the larvae are detected, not before
        # we are just going to read out the last available info and combine it, i think it makes sense


def main(args=None):
    rclpy.init(args=args)
    tracking_node = SingleFloaterTrackingNode()
    rclpy.spin(tracking_node)
    tracking_node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()


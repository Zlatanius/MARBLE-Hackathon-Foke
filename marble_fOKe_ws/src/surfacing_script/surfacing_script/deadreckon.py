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
from sensor_msgs.msg import Imu
from std_msgs.msg import String, Float32MultiArray


class DeadReckon(Node):

    def __init__(self):
        super().__init__('dreckon_node')
        self.publisher_ = self.create_publisher(Float32MultiArray, 'localization', 10)
        self.subscription = self.create_subscription(
        	Imu,
        	'floater/imu', 
        	self.imu_callback,
        	10
        )           	
        self.subscription
        #timer_period = 0.5  # seconds
        #self.timer = self.create_timer(timer_period, self.imu_callback)
        self.data_to_publish = [0, 0, 0]
        self.x = 0
        self.y = 0
        self.z = 0
        #self.data_to_publish = [45.03319189676756
#, 15.072478695032604, -2.6739288509954804] # pocetne koordinate floatera

    def imu_callback(self, msg): 
        self.get_logger().info('DeadReck mode | LinSpeed(x): %s' % msg.linear_acceleration.x)
        self.get_logger().info('DeadReck mode | LinSpeed(y): %s' % msg.linear_acceleration.y)
        self.get_logger().info('DeadReck mode | LinSpeed(z): %s' % msg.linear_acceleration.z)
        self.x = self.x + msg.linear_acceleration.x*0.5
        self.y = self.y + msg.linear_acceleration.y*0.5
        self.z = self.z + msg.linear_acceleration.z*0.5
        self.data_to_publish = [self.x, self.y, self.z]
        #self.data_to_publish = self.data_to_publish + [msg.linear_acceleration.x*0.5; msg.linear_acceleration.y*0.5; msg.linear_acceleration.z*0.5]

        self.publish_data()

    def publish_data(self):
        msg = Float32MultiArray(data=self.data_to_publish)
        self.publisher_.publish(msg)
        self.get_logger().info('Geocall mode | Publishing: "%s"' % msg.data)


def main(args=None):
    rclpy.init(args=args)

    dreckon_node = DeadReckon()

    rclpy.spin(dreckon_node)

    # Destroy the node explicitly
    # (optional - otherwise it will be done automatically
    # when the garbage collector destroys the node object)
    dreckon_node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()

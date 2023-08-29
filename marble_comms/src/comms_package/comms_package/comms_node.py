#!/usr/bin/env python
import numpy as np
import rclpy
from rclpy.node import Node
from std_msgs.msg import String
from sensor_msgs.msg import NavSatFix

R = 6378e3  # Radius of the earth in metres


class CommsNode(Node):
    def __init__(self):
        super().__init__('comms_node')
        # create a publisher that publishes an array of strings to the topic "comms_topic"
        self.publisher = self.create_publisher(String, 'comms_topic', 10)
        self.last_full_frame_publisher = self.create_publisher(
            String, '/comms_topic/last_full_frame', 10)
        self.self_position_subscriber = self.create_subscription(
            NavSatFix, '/floater1/gnss', self.gnss_callback, 10)
        self.nex_position_subscriber = self.create_subscription(
            NavSatFix, '/floater2/gnss', self.gnss_callback, 10)
        self.data_subscriber = self.create_subscription(
            String, '/comms_topic/data', self.data_callback, 10)
        # self.create_timer(1.0, self.timer_callback)
        self.latitude = 0
        self.longitude = 0
        self.altitude = 0
        self.next_latitude = 0
        self.next_longitude = 0
        self.next_altitude = 0
        self.longitude_rad = 0
        self.latitude_rad = 0
        self.next_longitude_rad = 0
        self.next_latitude_rad = 0
        self.current_frame = ''

    def gnss_callback(self, msg):
        caller_id = msg.header.frame_id
        strings = caller_id.split("/", 2)
        caller_id = strings[0]
        if caller_id == "floater1":
            self.latitude = msg.latitude
            self.longitude = msg.longitude
            self.altitude = msg.altitude

            self.longitude_rad = self.longitude * np.pi / 180
            self.latitude_rad = self.latitude * np.pi / 180

            self.get_logger().info('My coordinattes: %f, %f, %f, %s' %
                                   (msg.latitude, msg.longitude, msg.altitude, caller_id))
            # self.get_logger().info('My coordinattes: %f, %f, %s' %
            #                        (self.self_x_coord, self.self_y_coord, caller_id))
        else:
            self.next_latitude = msg.latitude
            self.next_longitude = msg.longitude
            self.next_altitude = msg.altitude

            self.next_longitude_rad = self.next_longitude * np.pi / 180
            self.next_latitude_rad = self.next_latitude * np.pi / 180

            self.get_logger().info('Next floater coordinattes: %f, %f, %f, %s' %
                                   (msg.latitude, msg.longitude, msg.altitude, caller_id))
            # self.get_logger().info('My coordinattes: %f, %f, %s' %
            #                        (self.next_x_coord, self.next_y_coord, caller_id))
        self.get_logger().info("Distance between floaters: %f" % (2 * R * np.arcsin(np.sqrt(np.sin((self.next_latitude_rad-self.latitude_rad)/2)
                                                                                            ** 2+np.cos(self.latitude_rad)*np.cos(self.next_latitude_rad)*np.sin((self.next_longitude_rad-self.longitude_rad)/2)**2))))
        # Haversine formula for distance between two points on a sphere

    def timer_callback(self):
        # Replace with your actual string array
        string_array = ["string1", "string2", "string3"]
        msg = String()
        # Convert the array to a single string
        msg.data = ' '.join(string_array)
        self.publisher.publish(msg)
        self.get_logger().info('Publishing: "%s"' % msg.data)

    def data_callback(self, msg):
        data_split = msg.data.split(",", 1)
        self.current_frame = self.current_frame + msg.data + ','
        if (data_split[0] == "3"):
            msg.data = self.current_frame
            self.last_full_frame_publisher.publish(msg)
        self.get_logger().info('Received: "%s"' % self.current_frame)


def main(args=None):
    rclpy.init(args=args)
    comms_node = CommsNode()
    rclpy.spin(comms_node)
    rclpy.shutdown()


if __name__ == '__main__':
    main()

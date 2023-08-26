#!/usr/bin/env python
import rclpy
from rclpy.node import Node
from std_msgs.msg import String


class CommsNode(Node):
    def __init__(self):
        super().__init__('comms_node')
        # create a publisher that publishes an array of strings to the topic "comms_topic"
        self.publisher = self.create_publisher(String, 'comms_topic', 10)
        self.create_timer(1.0, self.timer_callback)

    def timer_callback(self):
        # Replace with your actual string array
        string_array = ["string1", "string2", "string3"]
        msg = String()
        # Convert the array to a single string
        msg.data = ''.join(string_array)
        self.publisher.publish(msg)


def main(args=None):
    rclpy.init(args=args)
    comms_node = CommsNode()
    rclpy.spin(comms_node)
    rclpy.shutdown()


if __name__ == '__main__':
    main()

#!/usr/bin/env python
import rclpy
from rclpy.node import Node

class CommsNode(Node):
    def __init__(self):
        super().__init__('comms_node')
        self.get_logger().info("Comms node started")

def main(args=None):
    rclpy.init(args=args)
    comms_node = CommsNode()
    rclpy.spin(comms_node)
    rclpy.shutdown()

if __name__ == '__main__':
    main()
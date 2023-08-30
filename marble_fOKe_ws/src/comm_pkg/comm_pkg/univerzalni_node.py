#!/usr/bin/env python3
import numpy as np
import rclpy
from rclpy.node import Node
from custom_msgs.msg import CommsMessage


class UniversalFloaterNode(Node):
    def __init__(self):
        super().__init__('universal_node')
        # neka bude manje od minute npr
        self.create_timer(10, self.timer_callback)
        self.counter_ = 0
        self.subscriber_ = self.create_subscription(
            CommsMessage, '/marble_pkg/from_cls_to_comms', self.theme_callback, 10)
        self.publisher_ = self.create_publisher(
            CommsMessage, '/comms_topic/last_full_frame', 10)  # last frame publisher
        self.message_array = []  # promijeniti samo na 10 kad bude 10 floatera
        self.message_theme_array = []  # isto

    def timer_callback(self):  # ja ovdje rjesavam sve u jednom callbacku
        if self.counter_ == 3:  # ovdje poslije ici do 10

            for message in self.message_array:
                self.publisher_.publish(message)

            self.counter_ = 1
        else:
            if (len(self.message_array) == 3):
                # ovo kad se popuni lista
                self.message_array[self.counter_ -
                                   1] = self.message_theme_array[self.counter_ - 1]
            else:
                self.message_array.append(
                    self.message_theme_array[self.counter_])

            self.counter_ += 1

    # bitno je da se publish radi ne na n-ti nego na n+1. interval radi slanja onom floateru koji je najblizi povrsini

    def theme_callback(self, msg):
        if (len(self.message_theme_array) == 3):

            # ovo kad je popunjen niz inicijalno vec pa se mijenjanju samo vrijednosti
            self.message_theme_array[msg.floater_id - 1] = msg
        else:
            self.message_theme_array.append(msg)


def main(args=None):
    rclpy.init(args=args)
    universal_floater_node = UniversalFloaterNode()
    rclpy.spin(universal_floater_node)
    rclpy.shutdown()


if __name__ == '__main__':
    main()

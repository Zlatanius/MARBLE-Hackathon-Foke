import rclpy
from rclpy.node import Node

from custom_msgs.msg import CountWithFloaterInfo, LocationWithFloaterInfo, CommsMessage
import numpy as np
from std_msgs.msg import String
import re

class TrackingNode(Node):

    def __init__(self):
        super().__init__('tracking_node')
        self.subscription_count = self.create_subscription(
            CountWithFloaterInfo,
            'count_topic',
            self.listener_callback_count,
            20)
        self.subscription_count 

        self.floater_tracking_dict = {}
        self.last_known_concentration = {}

        self.subscription_location_1 = self.create_subscription(
            LocationWithFloaterInfo,
            'location_topic',
            self.listener_callback_location,
            20)
        
        self.subscription_location_1

        self.subscription_location_2 = self.create_subscription(
            LocationWithFloaterInfo,
            'location_topic',
            self.listener_callback_location,
            20)
        
        self.subscription_location_2

        self.subscription_location_3 = self.create_subscription(
            LocationWithFloaterInfo,
            'location_topic',
            self.listener_callback_location,
            20)
        
        self.subscription_location_3

        self.publisher_to_comms = self.create_publisher(CommsMessage, '/marble_pkg/from_cls_to_comms', 30)

    def publish_message_to_comms(self, msg): 
        new_msg = CommsMessage()
        temp = re.search(r'\d+', str(msg.floater_info))
        floater_id = int(temp.group())

        new_msg.floater_id = floater_id
        new_msg.concentration = self.floater_tracking_dict[msg.floater_info][0]
        new_msg.latitude = float(self.floater_tracking_dict[msg.floater_info][2][0])
        new_msg.longitude = float(self.floater_tracking_dict[msg.floater_info][2][1])
        new_msg.altitude = float(self.floater_tracking_dict[msg.floater_info][2][2])

        self.publisher_to_comms.publish(new_msg)

    def print_status(self, msg):
        self.get_logger().info('Floater name: ' + str(msg.floater_info))
        self.get_logger().info("Current concentration: " + \
                                   str(self.floater_tracking_dict[msg.floater_info][0]))
        self.get_logger().info("Previous concentration: " + \
                                   str(self.floater_tracking_dict[msg.floater_info][1]))
        self.get_logger().info("Current location: " + \
                                   str(self.floater_tracking_dict[msg.floater_info][2]))
        self.get_logger().info("Previous location: " + \
                                   str(self.floater_tracking_dict[msg.floater_info][3]))
        self.get_logger().info("Sample number: " + \
                                   str(self.floater_tracking_dict[msg.floater_info][4]))
        
        # ovo bi trebalo publishati u formatu koji njima treba
        # odgovarajuci topic je /marble_pkg/from_cls_to_comms
    
        
    def listener_callback_count(self, msg):
        if(msg.floater_info in self.floater_tracking_dict):

            new_list = [msg.larvae_count, self.floater_tracking_dict[msg.floater_info][0], \
                        self.floater_tracking_dict[msg.floater_info][2], self.floater_tracking_dict[msg.floater_info][3], \
                            self.floater_tracking_dict[msg.floater_info][4]+1]
            
            self.floater_tracking_dict.update({msg.floater_info: new_list})
            self.internal_callback(msg)

        else:
            # if not, we should create all the entries we need
            self.floater_tracking_dict[msg.floater_info] = [msg.larvae_count, 0, (0, 0, 0), (0, 0, 0), 1]
            self.last_known_concentration[msg.floater_info] = 0
            self.publish_message_to_comms(msg)
        # 

    def listener_callback_location(self, msg):
        if(msg.floater_info in self.floater_tracking_dict):
            if((msg.latitude, msg.longitude, msg.altitude) !=  self.floater_tracking_dict[msg.floater_info][2]):

                new_list = [self.floater_tracking_dict[msg.floater_info][0], self.floater_tracking_dict[msg.floater_info][1], \
                            (msg.latitude, msg.longitude, msg.altitude), self.floater_tracking_dict[msg.floater_info][2], \
                                self.floater_tracking_dict[msg.floater_info][4]]
                
                self.floater_tracking_dict.update({msg.floater_info: new_list})
                self.internal_callback(msg)

        else:
            self.floater_tracking_dict[msg.floater_info] = [0, 0, (msg.latitude, msg.longitude, msg.altitude), \
                                                            (msg.latitude, msg.longitude, msg.altitude), 0]
            self.last_known_concentration[msg.floater_info] = 0
            self.publish_message_to_comms(msg)


    def internal_callback(self, msg):

        self.publish_message_to_comms(msg)

        if(self.floater_tracking_dict[msg.floater_info][0] != \
            self.floater_tracking_dict[msg.floater_info][1] and self.floater_tracking_dict[msg.floater_info][0] != \
                self.last_known_concentration[msg.floater_info]): 

            # da ne bismo imali duplih ispisa za istu koncentracijsku promjenu radi vise lokacija
            # koje se ocitavaju, treba dodati jos jedan uslov koji samo biljezi da li je data koncentracija
            # vec u last_known_concentration na neki nacin
            # i one uslove oko gradijenata, koji sada mogu biti mnogo veci

            self.print_status(msg)

            current_floater_location = self.floater_tracking_dict[msg.floater_info][2]
            
            previous_floater_location = self.floater_tracking_dict[msg.floater_info][3]

            diff_latitude = (current_floater_location[0] - previous_floater_location[0]) 
            diff_longitude = (current_floater_location[1] - previous_floater_location[1])   
            diff_altitude = (current_floater_location[2] - previous_floater_location[2]) 

            diff_concentration = self.floater_tracking_dict[msg.floater_info][0]\
                  - self.floater_tracking_dict[msg.floater_info][1]
            
            self.last_known_concentration.update({msg.floater_info: self.floater_tracking_dict[msg.floater_info][0]})

            if(diff_latitude != 0):
                gradient_latitude = float(diff_concentration) / np.abs(diff_latitude * 111.139)
            else:
                gradient_latitude = 0
            
            if(diff_longitude != 0):
                gradient_longitude = float(diff_concentration) / np.abs(diff_longitude * 111.139)
            else:
                gradient_longitude = 0

            if(diff_altitude != 0):
                gradient_altitude = float(diff_concentration) / np.abs(diff_altitude * 111.139)
            else:
                gradient_altitude = 0

            if(np.abs(gradient_latitude) > 0 and np.abs(gradient_latitude) < 1000):
            # also here, in our case there will be 
            # no diff in latitude or longitude, that has to be fixed
                self.get_logger().info('Latitude component of gradient: %s larvae/meter' % str(gradient_latitude))
            if(np.abs(gradient_longitude) > 0 and np.abs(gradient_longitude) < 1000):
                self.get_logger().info('Longitude component of gradient: %s larvae/meter' % str(gradient_longitude))
            if(np.abs(gradient_altitude) > 0 and np.abs(gradient_altitude) < 1000):
                self.get_logger().info('Altitude component of gradient: %s larvae/meter' % str(gradient_altitude))


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
    tracking_node = TrackingNode()
    rclpy.spin(tracking_node)
    tracking_node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
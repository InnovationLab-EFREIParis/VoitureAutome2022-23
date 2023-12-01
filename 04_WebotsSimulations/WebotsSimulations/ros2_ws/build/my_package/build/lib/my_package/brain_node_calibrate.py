import rclpy
from rclpy.node import Node
from std_msgs.msg import String
from std_msgs.msg import Bool
from rclpy.action import ActionClient
from interfaces.action import DriverAction
from rclpy.action import ActionServer
from ament_index_python.packages import get_package_share_directory
import pathlib
from os import walk

import numpy as np

import csv

import os

from interfaces.action import DriverAction


class BrainNode(Node):
    """
        This class helps you test the behaviour of the car by defining simple commands in self.activity_profile
    """
    def __init__(self):
        super().__init__('brain_node')
        self.isConnected = False
        self.isRaceOn = False
        self.subscriber_connexion = self.create_subscription(Bool, 'IsConnected', self.getMessageConnexion, 10)
        self.subscriber_race = self.create_subscription(Bool, 'IsRaceOn', self.getMessageRace, 10)

        self._action_driver_server = ActionServer(
            self,
            DriverAction,
            'driverAction',
            self.execute_callback)

        self.cpt_call = 0
        self.min_range = 0.15
        self.aeb_lidar_threshold = 0.025
        self.aperture_tight_front_half_angle_deg = 45

        packageRep = get_package_share_directory('my_package')
        configPath = str(pathlib.Path(os.path.join(packageRep, 'config')))
        
        with open(os.path.join(configPath,"calibrate_activity_profiles.csv"), 'r') as file:
            csvreader = csv.reader(file)
            rows = [row for row in csvreader][1:]

        self.get_logger().info(str(rows))

        self.activity_profile = [{'name':row[0],'duration':int(row[1]),'speed':float(row[2]),'steering':float(row[3])} for row in rows]

        self.get_logger().info(str(self.activity_profile))

        self.cum_timing = np.cumsum(np.array(list(map(lambda x:x['duration'],self.activity_profile))))

        self.get_logger().info(str("Successfully created a brain node with Calibration driving policy"))

    def execute_callback(self, goal_handle):
        #self.get_logger().info('Executing goal...')
        lidar_scan = goal_handle.request.instruction.lidar_scan
        
        result = DriverAction.Result()

        #############################################

        timing_list = self.cum_timing - self.cpt_call
        try:
            res = next(x for x, val in enumerate(timing_list)
                                  if val > 0.)
        except:
            res = None

        if not res is None:
            profile = self.activity_profile[res]
            if timing_list[res]==profile['duration'] and self.isRaceOn:
                self.get_logger().info(f"#{self.cpt_call} - Executing activity '{profile['name']}' for {profile['duration']} steps | speed: {profile['speed']} steering:{profile['steering']}")
            
            steeringCommand = profile['steering']
            speedCommand = profile['speed']
        
        else :
            self.get_logger().info(f"All activity executed")
            steeringCommand = 0
            speedCommand = 0



        #security 
        full_lidar = np.array(lidar_scan.tolist())

        full_lidar[~np.isfinite(full_lidar)] = self.min_range
        
        full_lidar = (full_lidar/10).tolist()
        angular_resolution_deg = 360 / len(full_lidar)
        angular_resolution_rad = 2 * np.pi / len(full_lidar)
        aperture_tight_front = int(self.aperture_tight_front_half_angle_deg / angular_resolution_deg)
        lidar_tight_front = full_lidar[-aperture_tight_front:] + full_lidar[:aperture_tight_front + 1]
        if np.quantile(lidar_tight_front,q=0.4) < self.aeb_lidar_threshold :
            self.get_logger().info(f"BRAKING AT STEP {self.cpt_call}")
            steeringCommand = 0
            speedCommand = 0


        if(self.isRaceOn and self.isConnected):
            result.result.instruction.speed = float(speedCommand)
            result.result.instruction.steering_angle = float(steeringCommand)
            self.cpt_call += 1

        else:
            result.result.instruction.speed = float(0)
            result.result.instruction.steering_angle = float(0)


        #############################################
        feedback_msg = DriverAction.Feedback()
        goal_handle.publish_feedback(feedback_msg)

        goal_handle.succeed()
        
        return result

    def getMessageRace(self, message: Bool):
        if(message.data):
            self.isRaceOn = True
        else:
            self.isRaceOn = False

    def getMessageConnexion(self, message: Bool):
        if(message.data):
            self.isConnected = True
        else:
            self.isConnected = False

def main(args=None):
    rclpy.init(args=args)

    brain_node = BrainNode()

    rclpy.spin(brain_node)

    # Destroy the node explicitly
    # (optional - otherwise it will be done automatically
    # when the garbage collector destroys the node object)
    brain_node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()

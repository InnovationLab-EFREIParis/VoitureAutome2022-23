import rclpy
from rclpy.node import Node
from std_msgs.msg import String
from std_msgs.msg import Bool
from rclpy.action import ActionClient
from interfaces.action import DriverAction
from rclpy.action import ActionServer
from interfaces.msg import MonAckermannDrive
from sensor_msgs.msg import LaserScan
from interfaces.msg import ClientCommand

from ament_index_python.packages import get_package_share_directory
import pathlib
from os import walk

import numpy as np

import csv

import os


class BrainNode(Node):
    """
        This brain nodes allow to take the control of the car from the client.
    """
    def __init__(self):
        super().__init__('brain_node')
        self.isConnected = False
        self.isRaceOn = False
        self.subscriber_connexion = self.create_subscription(Bool, 'IsConnected', self.getMessageConnexion, 10)
        self.subscriber_race = self.create_subscription(Bool, 'IsRaceOn', self.getMessageRace, 10)

        self.subscriber_race = self.create_subscription(ClientCommand, 'ClientCommand', self.command_callback, 1)
        self.publisher_connexion = self.create_publisher(MonAckermannDrive, 'BrainDrivingCommand', 1)
        # self._action_driver_server = ActionServer(
        #     self,
        #     DriverAction,
        #     'driverAction',
        #     self.execute_callback)

        self.subscriber_lidar = self.create_subscription(LaserScan, 'LidarBrain', self.execute_callback, 1)

        self.min_range = 0.15
        self.aeb_lidar_threshold = 0.025 #0.025
        self.aperture_tight_front_half_angle_deg = 45

        self.command = ClientCommand()
        self.command.up = False
        self.command.down = False
        self.command.right = False
        self.command.left = False

        self.cpt_left, self.cpt_right, self.cpt_fwd,self.cpt_retro = 0, 0, 0, 0

        self.angle,self.speed = 0,0

        self.get_logger().info(str("Successfully created a brain node with Manual driving policy"))

    def command_callback(self,message):
        self.command = message

    def execute_callback(self, lidar_scan):

        #############################################

        if self.command.up:
            self.speed += 0.1
        elif self.command.down:
            self.speed -= 0.1
        else:
            self.speed /= 4

        if self.command.right:
            self.angle += 0.3
        elif self.command.left:
            self.angle -= 0.3
        else:
            self.angle = 0

        #self.command.up = False
        #self.command.down = False
        #self.command.right = False
        #self.command.left = False

        self.speed = max(min(self.speed,20),-20)
        self.angle = max(min(self.angle,0.27),-0.27)

        if self.speed < 0.1  and self.speed > -0.1:
            self.speed = 0

        if self.angle < 0.01  and self.angle > -0.01:
            self.angle = 0


        steeringCommand = self.angle
        speedCommand = self.speed
        #self.get_logger().info(f"angle {self.angle} | speed : {self.speed} | ")

        #security 
        '''
        full_lidar = np.array(lidar_scan.tolist())

        full_lidar[~np.isfinite(full_lidar)] = self.min_range
        
        full_lidar = (full_lidar/10).tolist()
        angular_resolution_deg = 360 / len(full_lidar)
        angular_resolution_rad = 2 * np.pi / len(full_lidar)
        aperture_tight_front = int(self.aperture_tight_front_half_angle_deg / angular_resolution_deg)
        lidar_tight_front = full_lidar[-aperture_tight_front:] + full_lidar[:aperture_tight_front + 1]
        if np.quantile(lidar_tight_front,q=0.4) < self.aeb_lidar_threshold and speedCommand >= 0:
            self.get_logger().info(f"BRAKING")
            speedCommand = 0
        '''

        #self.get_logger().info(f"angle {steeringCommand} | speed : {speedCommand}")
        msg = MonAckermannDrive()

        if(self.isRaceOn and self.isConnected):
            msg.speed = float(speedCommand)
            msg.steering_angle = float(steeringCommand)

        else:
            msg.speed = float(0)
            msg.steering_angle = float(0)


        #############################################

        self.publisher_connexion.publish(msg)
        
        # return result

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

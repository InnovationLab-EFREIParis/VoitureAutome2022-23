import rclpy
from rclpy.node import Node
from std_msgs.msg import Bool
from interfaces.msg import MonAckermannDrive
from sensor_msgs.msg import LaserScan
import numpy as np
from .aeb import BasicAEB

import time


class BrainNode(Node):

    def __init__(self):
        super().__init__('brain_node')
        self.isConnected = False
        self.isRaceOn = False
        self.subscriber_connexion = self.create_subscription(Bool, 'IsConnected', self.getMessageConnexion, 10)
        self.subscriber_race = self.create_subscription(Bool, 'IsRaceOn', self.getMessageRace, 10)

        self.publisher_connexion = self.create_publisher(MonAckermannDrive, 'BrainDrivingCommand', 1)
        
        self.subscriber_lidar = self.create_subscription(LaserScan, 'LidarBrain', self.execute_callback, 1)

        ## TO parameterized
        safety_bubble_r = 0.029 * 10#0.029
        aperture_half_angle = 75
        disparity_threshold = 0.8
        aperture_tight_front_half_angle_deg = 49
        aeb_ttc_threshold = 0.5
        aeb_lidar_threshold = .022

        ### CONFIG ###
        self.safety_bubble_r = safety_bubble_r

        self.aperture_half_angle = aperture_half_angle
        self.disparity_threshold = disparity_threshold
        self.aperture_tight_front_half_angle_deg = aperture_tight_front_half_angle_deg
        self.aeb_ttc_threshold = aeb_ttc_threshold
        self.aeb_lidar_threshold = aeb_lidar_threshold
        self.aeb_retro_speed = -3.16587354 #very weird speed to get an AEB signature. Pretty ugly but it works :)

        self.speed_profile = {'dist_threshold':[0.5,1.2,2.0,15.],'speed':[0.5,1.2,1.6,2.5]}

        self.aeb = BasicAEB()

        self.max_steering_angle = 0.25

        self.get_logger().info(str("Successfully created a brain node with MTD driving policy"))

    def execute_callback(self, lidar_scan):
        lidar_scan = lidar_scan.ranges
        #############################################
        t0 = time.time()
        lidar = np.array(lidar_scan.tolist())


        min_front_dist = lidar.min()

        id = lidar.tolist().index(min_front_dist)

        if id < len(lidar)/2:
            speedCommand = 0.5
            steeringCommand = -self.max_steering_angle 
        else:
            speedCommand = 0.5
            steeringCommand = self.max_steering_angle 

        half_angle_deg = 75
        angular_resolution_deg = 75*2/len(lidar) #A MODIFIER EN ACCORD


        ######
        # 
        # 
        # 
        lidar = np.array(lidar_scan.tolist())


        #TODO A CHANGER CETTE MERDE HARDCODÉ HORRIBLE ALERTE ALERTE
        half_angle_deg = -75
        half_angle_rad = -75 * np.pi/180
        angular_resolution_deg = 75*2/len(lidar)
        angular_resolution_rad = angular_resolution_deg * np.pi/180



        # Initialized with a value because if the original value of a point is lower than all the rest than it must stay true
        virtuals = [np.array(lidar)]
        for i in range(len(lidar) - 1):
            if abs(lidar[i] - lidar[i + 1]) > self.disparity_threshold:  # check if it's a disparity

                # is the disparity left to right or right to left ?
                idx_obstacle = i if lidar[i] - lidar[i + 1] < 0 else i + 1

                virtual_lidar = np.array(lidar)

                # Compute the distance for safety bubble filtering
                dists = [2 * lidar[idx_obstacle] * abs(np.sin(abs(idx_obstacle - j) * angular_resolution_rad / 2))
                         for j in range(len(lidar))]
                mask = [j <= self.safety_bubble_r for j in dists]

                # All lidar points in a certain area are set to the value of the disparity point
                virtual_lidar[mask] = lidar[idx_obstacle]
                virtuals.append(virtual_lidar)

        if len(virtuals) == 1:
            virtual_lidar = np.array(lidar)
        else:
            virtual_lidar = np.stack(virtuals, axis=1)
            virtual_lidar = np.min(virtual_lidar, axis=1)

        virtual_lidar = virtual_lidar.tolist()


        # Compute the angle of the goal both in radiant and degrees.
        idx_goal = virtual_lidar.index(max(virtual_lidar))





        angle_goal_deg =  half_angle_deg + idx_goal * angular_resolution_deg
        angle_goal_rad =  half_angle_rad + idx_goal * angular_resolution_rad

        self.get_logger().info("num discrepancy:" + str(len(virtuals)-1))
        self.get_logger().info("ratio:" + str((np.array(virtual_lidar)==lidar).sum()/len(lidar)))


        # print("Angle GOAL : ", angle_goal_deg)
        # print("Angle GOAL RAD: ", angle_goal_rad)

        aperture_tight_front = int((-half_angle_deg - self.aperture_tight_front_half_angle_deg) / angular_resolution_deg)

        lidar_tight_front = lidar[aperture_tight_front:-aperture_tight_front]
        
        
        # self.get_logger().info(f"size tight {len(lidar_tight_front)} | aperture {aperture_tight_front} | size lidar {len(lidar)}")

        # print("---TTC FRONT", ttc_tight_front)

        direction = np.sign(-angle_goal_deg)
        steeringCommandAEB= direction * min(self.max_steering_angle, np.abs(angle_goal_rad) * 1.4)
        # 
        # ###

        aperture_tight_front = int((-half_angle_deg - self.aperture_tight_front_half_angle_deg) / angular_resolution_deg)

        lidar_tight_front = lidar[aperture_tight_front:-aperture_tight_front]
        
        self.get_logger().info(str(len(lidar_tight_front)))


        direction = np.sign(steeringCommand)

        speedCommandAEB, steeringCommandAEB,is_braking = self.aeb.check(speedCommand, steeringCommandAEB, lidar_tight_front,
                                                       direction)
        
        
        if speedCommandAEB < 0:
            self.get_logger().info(f"EMERGENCY BREAKING")
            speedCommand = speedCommandAEB
            steeringCommand= steeringCommandAEB

        msg = MonAckermannDrive()
        if(self.isRaceOn and self.isConnected):
            msg.speed = float(speedCommand)
            msg.steering_angle = float(steeringCommand)
        else:
            msg.speed = float(0)
            msg.steering_angle = float(0)

        self.publisher_connexion.publish(msg)



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

    brain_node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()

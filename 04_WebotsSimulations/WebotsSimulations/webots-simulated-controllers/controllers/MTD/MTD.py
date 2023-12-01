import os

import numpy as np


import sys
sys.path.append("../")
from car_logic import CarLogic
import json
from scipy.spatial.transform import Rotation as Rotation
from numpy import exp, abs, angle


class MTD(CarLogic):
    """
        The Mind The Disparity algorithm.
    """
    def __init__(self,path_to_trajectory=None,
                 plot_list=[],
                 record_list = ('steering_command','lidar_range_image','speed_command','car_position','lidar_point_cloud',
                                'slam_absolute_point_cloud','slam_absolute_car_position','virtual_lidar_range_image'),
                 safety_bubble_r = 0.029,
                 aperture_half_angle = 75,
                 disparity_threshold = 0.08,
                 aperture_tight_front_half_angle_deg=45,
                 aeb_ttc_threshold=0.5,
                 aeb_lidar_threshold = .022
                 ):
        """

        :param path_to_trajectory: path to a trajectory .json file. If None default spawning values are used.
        :param plot_list:
        :param record_list:
        :param safety_bubble_r: Size of the safety bubble used around detected disparities
        :param aperture_half_angle: half angle of the front lidar view used for MTD
        :param disparity_threshold: distance threshold used to detect disparities
        :param aperture_tight_front_half_angle_deg:  tight front lidar view half angle. Used for AEB
        :param aeb_ttc_threshold:
        :param aeb_lidar_threshold:
        """
        super().__init__( path_to_trajectory=path_to_trajectory,plot_list=plot_list,record_list=record_list)

        # Size of the safety bubble around the walls
        self.safety_bubble_r = safety_bubble_r

        self.aperture_half_angle = aperture_half_angle
        self.disparity_threshold = disparity_threshold
        self.aperture_tight_front_half_angle_deg = aperture_tight_front_half_angle_deg
        self.aeb_ttc_threshold = aeb_ttc_threshold
        self.aeb_lidar_threshold = aeb_lidar_threshold
        self.aeb_retro_speed = -3.16587354 #very weird speed to get an AEB signature. Pretty ugly but it works :)

        self.speed_profile = {'ttc_threshold':[0.2,0.9,1.5],'speed':[0.5,1,3,6]}


        ## Look at configuration
        # speed_profile () | aperture_half_angle (75) |  aperture_tight_front_half_angle_deg (45)
        if 'speed_profile' in self.dict_params.keys():
            self.speed_profile = self.dict_params['speed_profile']

        if 'aperture_half_angle' in self.dict_params.keys():
            self.aperture_half_angle = self.dict_params['aperture_half_angle']

        if 'aperture_tight_front_half_angle_deg' in self.dict_params.keys():
            self.aperture_tight_front_half_angle_deg = self.dict_params['aperture_tight_front_half_angle_deg']

        if 'safety_bubble_r' in self.dict_params.keys():
            self.safety_bubble_r = self.dict_params['safety_bubble_r']

    def drive(self):

        full_lidar = self.get_normalized_lidar_range_image().tolist()

        angular_resolution_deg = 360/len(full_lidar)
        angular_resolution_rad = 2*np.pi / len(full_lidar)

        aperture = int(self.aperture_half_angle / angular_resolution_deg)

        lidar = full_lidar[-aperture:] + full_lidar[:aperture+1]

        # Initialized with a value because if the original value of a point is lower than all the rest than it must stay true
        virtuals = [np.array(lidar)]
        for i in range(len(lidar)-1):
            if abs(lidar[i] - lidar[i + 1]) > self.disparity_threshold: # check if it's a disparity

                # is the disparity left to right or right to left ?
                idx_obstacle = i if lidar[i] - lidar[i + 1] < 0 else i+1

                virtual_lidar = np.array(lidar)

                # Compute the distance for safety bubble filtering
                dists = [2 * lidar[idx_obstacle] * abs(np.sin(abs(idx_obstacle - j) * angular_resolution_rad / 2))
                         for j in range(len(lidar))]
                mask = [j <= self.safety_bubble_r for j in dists]

                # All lidar points in a certain area are set to the value of the disparity point
                virtual_lidar[mask] = lidar[idx_obstacle]
                virtuals.append(virtual_lidar)

        if len(virtuals)==1:
            virtual_lidar = np.array(lidar)
        else:
            virtual_lidar = np.stack(virtuals,axis=1)
            virtual_lidar = np.min(virtual_lidar,axis=1)


        virtual_lidar = virtual_lidar.tolist()


        virtual_full_lidar = full_lidar.copy()
        virtual_full_lidar[-aperture:] = virtual_lidar[-aperture:]
        virtual_full_lidar[:aperture+1] = virtual_lidar[:aperture+1]
        self.record_kv_episode_log( "virtual_lidar_range_image", virtual_full_lidar)




        # Compute the angle of the goal both in radiant and degrees.
        idx_goal = virtual_lidar.index(max(virtual_lidar))
        angle_goal_deg = (idx_goal - aperture)*angular_resolution_deg
        angle_goal_rad = (idx_goal - aperture)*angular_resolution_rad

        # print("Angle GOAL : ", angle_goal_deg)
        # print("Angle GOAL RAD: ", angle_goal_rad)



        aperture_tight_front = int(self.aperture_tight_front_half_angle_deg / angular_resolution_deg)


        lidar_tight_front = full_lidar[-aperture_tight_front:] + full_lidar[:aperture_tight_front + 1]



        # Compute the forward speed
        speed_vector_absolute = self.get_speed_vector()
        rotation = np.reshape(self.car.getOrientation(), (3, 3))


        speed_vector_relative = rotation.T @ np.array(speed_vector_absolute)


        vx = speed_vector_relative[0]
        # print("VX:", vx)

        # use forward speed to compute a Time To Collision (TTC). This assume that obstacle are still, which is wrong.
        lidar_speed = np.array([vx * np.cos(i * angular_resolution_rad) for i in range(len(full_lidar))])
        lidar_speed[lidar_speed < 0] = 0
        ttc = 10 * np.array(full_lidar) / lidar_speed
        ttc_tight_front = ttc[-aperture_tight_front:].tolist() + ttc[:aperture_tight_front + 1].tolist()

        # print("---TTC FRONT", ttc_tight_front)

        direction = np.sign(angle_goal_deg)
        steeringCommand = direction * min(self.max_steering_angle,np.abs(angle_goal_rad)*1.8)
        speedCommand = self.ttc_to_speed(np.quantile(ttc_tight_front,q=0.7))

        speedCommand, steeringCommand = self.aeb.check(speedCommand, steeringCommand, full_lidar, aperture_tight_front,direction)

        self.setSpeedCommand(speedCommand)
        self.setSteeringCommand(steeringCommand)


    def ttc_to_speed(self, min_ttc):
        for i,ttc_thresh in enumerate(self.speed_profile["ttc_threshold"]):
            if min_ttc <= ttc_thresh:
                return self.speed_profile["speed"][i]
        return self.speed_profile["speed"][-1]




def main():

    print(os.getcwd())
    path_to_trajectory = r"../../worlds/trajectories/Long_Bai_new--0835-3001.json"


    # List of information to be recorded by the driver
    record_list = ('steering_command','lidar_range_image','speed_command','car_position','lidar_point_cloud',
                                'slam_absolute_point_cloud','slam_absolute_car_position','virtual_lidar_range_image')

    carController = MTD( plot_list=[], record_list=record_list) #path_to_trajectory=path_to_trajectory

    print("It's lights out and away we go !")

    for _ in range(20000):
        carController.step()
    print("Ending...")

    # with open(r"../../logs/JSON_run_debug/dataFTGNew.json", 'w', encoding='utf-8') as f:
    #     json.dump(carController.full_logs, f, ensure_ascii=False, indent=4)
if __name__ == '__main__':
    main()


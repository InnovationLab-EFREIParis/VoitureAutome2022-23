import os

import numpy as np


import sys
sys.path.append("../")
from car_logic import CarLogic
import json
from scipy.spatial.transform import Rotation as Rotation
from numpy import exp, abs, angle


class MinimalController(CarLogic):
    """
        An example of a basic driving logic implemented on top of the CarLogic Class.
    """
    def __init__(self,path_to_trajectory=None,
                 plot_list=[],
                 record_list = [],
                 safety_bubble_r = 0.029,
                 aperture_half_angle = 75,
                 disparity_threshold = 0.08,
                 aperture_tight_front_half_angle_deg=45,
                 aeb_ttc_threshold=1.4,
                 aeb_lidar_threshold = .022,
                 rot_value=[-0.000257, 0.000618, 1, -0.784],
                 pos_value=[1.5, 3.74, 0.0195182],
                 ):
        super().__init__( path_to_trajectory=path_to_trajectory,plot_list=plot_list,record_list=record_list,rot_value =rot_value,pos_value =pos_value)

        self.safety_bubble_r = safety_bubble_r
        self.aperture_half_angle = aperture_half_angle
        self.disparity_threshold = disparity_threshold
        self.aperture_tight_front_half_angle_deg = aperture_tight_front_half_angle_deg
        self.aeb_ttc_threshold = aeb_ttc_threshold
        self.aeb_lidar_threshold = aeb_lidar_threshold
        self.aeb_retro_speed = -8.16587354 #very weird speed to get an AEB signature. Pretty ugly but it works :)


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


        # print('LIDAR READING:',lidar)
        # print("NUMBER DISPARITIES",len(virtuals))
        # print(f"DISPARITIES IDX: { [ f'{i:.0f}' for i in [ (idx - aperture)*angular_resolution_deg for idx in disparities]]} (degres)")
        # print("VIRTUAL LIDAR DIFF: ", virtual_lidar-np.array(lidar))

        virtual_lidar = virtual_lidar.tolist()


        virtual_full_lidar = full_lidar.copy()
        virtual_full_lidar[-aperture:] = virtual_lidar[-aperture:]
        virtual_full_lidar[:aperture+1] = virtual_lidar[:aperture+1]
        self.record_kv_episode_log( "virtual_lidar_range_image", virtual_full_lidar)




        # Compute the angle of the goal both in radiant and degrees.
        idx_goal = virtual_lidar.index(max(virtual_lidar))
        angle_goal_deg = (idx_goal - aperture)*angular_resolution_deg
        angle_goal_rad = (idx_goal - aperture)*angular_resolution_rad

        print("Angle GOAL : ", angle_goal_deg)
        print("Angle GOAL RAD: ", angle_goal_rad)



        aperture_tight_front = int(self.aperture_tight_front_half_angle_deg / angular_resolution_deg)
        lidar_tight_front = full_lidar[-aperture_tight_front:] + full_lidar[:aperture_tight_front + 1]

        # Compute the forward speed
        speed_vector_absolute = self.get_speed_vector()
        rotation = np.reshape(self.car.getOrientation(), (3, 3))
        speed_vector_relative = rotation.T @ np.array(speed_vector_absolute)
        vx = speed_vector_relative[0]
        print("VX:", vx)

        # use forward speed to compute a Time To Collision (TTC). This assume that obstacle are still, which is wrong.
        lidar_speed = np.array([vx * np.cos(i * angular_resolution_rad) for i in range(len(full_lidar))])
        lidar_speed[lidar_speed < 0] = 0
        ttc = 10 * np.array(full_lidar) / lidar_speed
        ttc_tight_front = ttc[-aperture_tight_front:].tolist() + ttc[:aperture_tight_front + 1].tolist()

        print("---TTC FRONT", ttc_tight_front)



        direction = np.sign(angle_goal_deg)
        steeringCommand = direction * min(self.max_steering_angle,np.abs(angle_goal_rad)*1.8)
        speedCommand = self.ttc_to_speed(np.quantile(ttc_tight_front,q=0.4))

        ## DEV REMOVE THIS PART FOR CRASH TEST

        speedCommand = 150
        steeringCommand = 0



        # print("QUANTILE TTC FRONT: ",np.quantile(ttc_tight_front,q=0.3))
        # print("QUANTILE LIDAR FRONT: ",np.quantile(lidar_tight_front,q=0.4))
        # if np.quantile(ttc_tight_front,q=0.18) < self.aeb_ttc_threshold or np.quantile(lidar_tight_front,q=0.4) < self.aeb_lidar_threshold :
        #     print("============AEB  BREAKING NOWWWWWWWWWWWWWWWWWWWWWWWW==============\n\n\n\n")
        #     speedCommand = self.aeb_retro_speed
        #     # steeringCommand = -self.max_steering_angle * direction
        #
        #
        # ## Oscillating AEB is a problem, here we do AEB for at lest x simulation step (will need to do that timing wise)
        # buffer_aeb_binary_mask = [1 if cmd == self.aeb_retro_speed else 0 for cmd in self.speedCommand_buffer]
        # print("BUFFER MASK", buffer_aeb_binary_mask)
        # if sum(buffer_aeb_binary_mask[-19:]) > 0 and buffer_aeb_binary_mask[-20] == 0 and buffer_aeb_binary_mask[-1]==1:
        #     speedCommand = self.aeb_retro_speed
        #     # steeringCommand = -self.max_steering_angle * direction
        #
        # if vx < 0:
        #     speedCommand = -0.001

        self.setSpeedCommand(speedCommand)
        self.setSteeringCommand(steeringCommand)


    def ttc_to_speed(self, min_ttc):
        if min_ttc <= 0.2:
            return 0.5
        elif min_ttc <= 0.9:
            return 1
        elif min_ttc <= 1.5:
            return 3
        else:
            return 6



def main():

    print(os.getcwd())



    record_list = ()

    rot_value = [0,0,1,3.14159]
    pos_value = [5.7992, -0.0320365, 0.04]
    carController = MinimalController( plot_list=[], record_list=record_list,rot_value =rot_value,pos_value =pos_value)

    print("It's lights out and away we go !")
    for i in range(2):
        carController.reset()
        for _ in range(1000):
            carController.step()
        print("Reseting at random position")
    print("Ending...")

if __name__ == '__main__':
    main()


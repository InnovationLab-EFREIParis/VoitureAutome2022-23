import numpy as np


class MTD():
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

        # Size of the safety bubble around the walls
        self.safety_bubble_r = safety_bubble_r

        self.aperture_half_angle = aperture_half_angle
        self.disparity_threshold = disparity_threshold
        self.aperture_tight_front_half_angle_deg = aperture_tight_front_half_angle_deg
        self.aeb_ttc_threshold = aeb_ttc_threshold
        self.aeb_lidar_threshold = aeb_lidar_threshold
        self.aeb_retro_speed = -3.16587354 #very weird speed to get an AEB signature. Pretty ugly but it works :)

        self.speed_profile = {'ttc_threshold':[0.2,0.9,1.5],'speed':[0.5,1,3,6]}


    def drive(self):

        full_lidar = np.random.rand(100).tolist()


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





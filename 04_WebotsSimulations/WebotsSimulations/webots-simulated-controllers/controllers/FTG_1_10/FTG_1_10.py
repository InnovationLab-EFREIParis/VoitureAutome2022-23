import os

import numpy as np


import sys
sys.path.append("../")
from car_logic import CarLogic
import json

class MinimalController(CarLogic):
    """
        An example of a basic driving logic implemented on top of the CarLogic Class.
    """
    def __init__(self,path_to_trajectory=None,plot_list=[]):
        super().__init__( path_to_trajectory=path_to_trajectory,plot_list=plot_list)

    def drive(self):

        safety_bubble_r = 0.030


        aperture_half_angle = 70 #(deg)
        aperture = 13 # 5 for 36

        full_lidar = self.get_normalized_lidar_range_image().tolist()

        angular_resolution_deg = 360/len(full_lidar)

        aperture = int(aperture_half_angle / angular_resolution_deg)

        lidar = full_lidar[-aperture:] + full_lidar[:aperture+1]
        print("APERTURE: ",aperture)
        print("TOTAL WIDTH LIDAR:", len(lidar))
        print("LIDAR: ", lidar)


        closest_dist = min(lidar)
        closest_idx = lidar.index(closest_dist)

        phi = 2*np.pi/len(full_lidar)

        print("CLOSEST DOST: ",closest_dist)
        print("dist idx: ", [abs(i-closest_idx) for i in  range(len(lidar))])

        dists = [2 * closest_dist * abs(np.sin(abs(i-closest_idx) * phi/2))
            for i in range(len(lidar))]
        print("Idx closest: ", closest_idx)
        print("Dists: ", dists)

        mask = [ i <= safety_bubble_r for i in dists]

        print("MASK: ", mask)

        lidar_bubbled = np.array(lidar)
        lidar_bubbled[mask] = 0
        print("LIDAR BUBBLED: ",lidar_bubbled)

        max_streak = 0
        streak = 0
        start_streak = 0
        for i,v in enumerate(lidar_bubbled):

            if v != 0.:
                if streak > 0:
                    streak +=1
                    if max_streak <= streak:
                        start_max_streak = start_streak
                        max_streak = streak
                else:
                    streak = 1
                    start_streak = i
            else:
                if streak >= max_streak:
                    max_streak = streak
                    start_max_streak = start_streak
                    streak = 0

        print(start_max_streak," ",max_streak+start_max_streak)

        lidar_bubbled = lidar_bubbled.tolist()
        idx_goal = lidar_bubbled.index(max(lidar_bubbled[start_max_streak:max_streak+start_max_streak+1]))


        print("IDEX GOAL: ", idx_goal)

        if idx_goal - aperture == 0:
            self.setSpeedCommand(2)
            self.setSteeringCommand(0.)
        elif idx_goal - aperture < 0:
            self.setSpeedCommand(0.5)
            self.setSteeringCommand(-0.4)
        else:
            self.setSpeedCommand(0.5)
            self.setSteeringCommand(0.4)

        print("Y lidar DEV: ", list(map(lambda x: x.y, self.lidar.getPointCloud())))



def main():

    print(os.getcwd())
    path_to_trajectory = r"../../worlds/trajectories/Circuit-trajectory.json"

    carController = MinimalController(path_to_trajectory =path_to_trajectory,plot_list=[])

    print("It's lights out and away we go !")
    for i in range(2):
        carController.reset()
        for _ in range(10000):
            carController.step()
        print("Reseting at random position")
    print("Ending...")
    print(carController.full_logs)
    with open(r"F:\Data\Maximilien\Projects\experiment-AI\toTransfer\WebotsSimulations\reinforcement-learning-trainers\logs\JSON_run_debug\dataLuc.json", 'w', encoding='utf-8') as f:
        json.dump(carController.full_logs, f, ensure_ascii=False, indent=4)
if __name__ == '__main__':
    main()


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

        id_balise = self.get_balise()

        self.update_advancement(id_balise)
        self.update_travelled_distance()
        xy_lidar = list(map(lambda x: (x.x, x.y), self.lidar.getPointCloud()))
        y_lidar = list(map(lambda x: x.y, self.lidar.getPointCloud()))

        dist = list(map(lambda p: p[0] ** 2 + p[1] ** 2, xy_lidar))
        front_dist = np.array(dist[-8:] + dist[:8])
        min_front_dist = front_dist[np.isfinite(front_dist)].min()
        id = dist.index(min_front_dist)

        if id in [0, 1, len(dist), len(dist) - 1]:
            self.setSpeedCommand(-0.5)
            self.setSteeringCommand(-0.1)
        elif y_lidar[id] < 0:
            self.setSpeedCommand(0.5)
            self.setSteeringCommand(-0.4)
        else:
            self.setSpeedCommand(0.5)
            self.setSteeringCommand(0.4)


def main():

    path_to_trajectory = r"../../worlds/trajectories/Circuit-trajectory.json"

    carController = MinimalController(path_to_trajectory =path_to_trajectory,plot_list=[])

    print("It's lights out and away we go !")
    for i in range(2):
        carController.reset()
        for _ in range(10000):
            carController.step()
        print("Reseting at random position")
    print("Ending...")

    with open(r"..\logs\JSON_run_debug\exampleLogs.json", 'w', encoding='utf-8') as f:
        json.dump(carController.full_logs, f, ensure_ascii=False, indent=4)

if __name__ == '__main__':
    main()
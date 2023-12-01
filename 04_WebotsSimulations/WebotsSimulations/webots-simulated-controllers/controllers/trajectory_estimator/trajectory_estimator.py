"""Voiture autonome avec utilisation d'un
LIDAR sur WEBOTS
Auteur : Chrysanthe et Jessica
"""

import numpy as np
import random
import time
import matplotlib.pyplot as plt
import json
import datetime
import os.path as osp
import sys
sys.path.append("../")
from car_logic import CarLogic


# --------------GYM----------------------------

class CarController(CarLogic):
    def __init__(self):
        print("Initialisating the Webots/Gym environnement...")
        super().__init__()  # Objet héritant la classe Driver

        self.trajectories = {'rotations':[],'positions':[]}
        self.num_laps = 0
        self.goal_num_laps = 1

        self.INITIAL_trans = self.car.getPosition()
        self.INITIAL_rot = self.car.getField("rotation").getSFRotation()

    def respawn(self,speedCommand=0,steeringCommand=0):

        x,y,z = self.INITIAL_trans
        INITIAL_trans = [x + random.uniform(-0.05,0.05), y+ random.uniform(-0.05,0.05), z]
        INITIAL_rot = self.INITIAL_rot
        self.trans_champs.setSFVec3f(INITIAL_trans)
        self.rot_champs.setSFRotation(INITIAL_rot)

        time.sleep(0.3)
        self.current_advancement = set()
        self.current_positions = []
        self.current_rotations = []

    # Remise à 0 pour l'environnement GYM
    def reset(self):
        super().reset()
        self.trajectories['positions'].append(self.current_positions)
        self.trajectories['rotations'].append(self.current_rotations)



    def step(self):

        self.current_positions.append(self.car.getPosition())
        self.current_rotations.append(self.car.getField("rotation").getSFRotation())

        ##check tour
        balise = self.capteur_balise.getValue()

        if balise > 700:
            id = self.get_balise_id()
            if id not in self.current_advancement:
                self.current_advancement.add(id)
                if len(self.current_advancement) >= len(self.balises):
                    self.num_laps +=1
                    if self.num_laps + 1 > self.goal_num_laps:
                        self.trajectories['positions'].append(self.current_positions)
                        self.trajectories['rotations'].append(self.current_rotations)
                        # self.reset()
                        return False
                    self.reset()
                else:
                    print(f"Balise {id} passée")


        ## Conduite

        xy_lidar = list(map(lambda x: (x.x, x.y), self.lidar.getPointCloud()))
        y_lidar = list(map(lambda x: x.y, self.lidar.getPointCloud()))

        dist = list(map(lambda p: p[0] ** 2 + p[1] ** 2, xy_lidar))
        # front_dist = np.array(dist[-8:] + dist[:8])
        front_dist = np.array(dist[-8:] + dist[:8])

        max_front_dist = front_dist[np.isfinite(front_dist)].min()
        id = dist.index(max_front_dist)

        if id in [0]:
            super().setCruisingSpeed(0.5)
            super().setSteeringAngle(0.)

        elif y_lidar[id] < 0:
            super().setCruisingSpeed(0.5)
            super().setSteeringAngle(0.4)
        else:
            super().setCruisingSpeed(0.5)
            super().setSteeringAngle(-0.4)



        super().step()

        return True


# ----------------Programme principal--------------------
def main():
    t = datetime.datetime.now()
    t = t.strftime('-%H%M-%d%m')
    map_name = "Long_Bai_new"
    path_to_traj = osp.join("../../worlds/trajectories",f"{map_name}-{t}.json")


    carController = CarController()
    carController.respawn()


    for _ in range(15000):
        running = carController.step()

        if not running:
            break
    print("Fin du roulage :)")


    traj_1_position = carController.trajectories['positions'][0]
    traj_1_rotation = carController.trajectories["rotations"][0]


    rotations = []
    positions = []
    for i in range(10,len(traj_1_position),20):
        rotations.append(traj_1_rotation[i])
        positions.append(traj_1_position[i])

    x_traj = list(map(lambda x: x[0], positions))
    y_traj = list(map(lambda x: x[1], positions))
    plt.scatter(x_traj, y_traj)
    plt.show()

    print(len(rotations))
    with open(path_to_traj, 'w') as f:
        f.write(json.dumps({'positions':positions,'rotations':rotations}))

    #     a = json.loads(f.read())

if __name__ == '__main__':
    main()


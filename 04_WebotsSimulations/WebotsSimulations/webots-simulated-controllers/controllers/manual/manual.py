import os

import numpy as np


import sys
sys.path.append("../")
from car_logic import CarLogic
import json
from collections import deque
import keyboard


class ManualController(CarLogic):
    """
        An example of a basic driving logic implemented on top of the CarLogic Class.
    """
    def __init__(self,path_to_trajectory=None,plot_list=[]):
        super().__init__( path_to_trajectory=path_to_trajectory,plot_list=plot_list)

        basicTimeStep = int(super().getBasicTimeStep())
        sensorTimeStep = 4 * basicTimeStep

        self.keyboard = super().getKeyboard()
        self.keyboard.enable(sensorTimeStep)

        self.speed = 0
        self.angle = 0

        buffer_size = 60

        self.forward_buffer = deque([0 for i in range(buffer_size)], maxlen=buffer_size)

        self.right_buffer = deque([0 for i in range(buffer_size)], maxlen=buffer_size)
        self.left_buffer = deque([0 for i in range(buffer_size)], maxlen=buffer_size)



        print("Cliquer sur la vue 3D pour commencer")
        print("m pour mode manuel, a pour mode auto, n pour stop, l pour affichage données lidar")
        print("en mode manuel utiliser les flèches pour accélérer, freiner et diriger")

    def drive(self):

        if keyboard.is_pressed('up'):
            self.cpt_fwd += 1
        else:
            self.cpt_fwd = 0

        if keyboard.is_pressed('left'):
            self.cpt_left += 1
        else:
            self.cpt_left = 0


        if keyboard.is_pressed('right'):
            self.cpt_right += 1
        else:
            self.cpt_right = 0

        if keyboard.is_pressed('down'):
            self.cpt_retro += 1
        else:
            self.cpt_retro = 0

        if keyboard.is_pressed(' '):
            super().setBrakeIntensity(1.0)
        else:
            super().setBrakeIntensity(0.)

        if self.cpt_right!=0:
            direction = 1
            cpt_angle = self.cpt_right

        elif self.cpt_left !=0:
            direction = -1
            cpt_angle = self.cpt_left
        else:
            direction = 0
            cpt_angle = 0

        self.speed = max(min(self.cpt_fwd - self.cpt_retro,60),-20)*8/60
        angle = min(0.285,cpt_angle*0.285/15)
        self.angle = direction * angle

        self.setSpeedCommand(self.speed)
        self.setSteeringCommand(self.angle)

def main():

    print(os.getcwd())

    carController = ManualController(plot_list=[])

    print("It's lights out and away we go !")

    for _ in range(100000):
        carController.step()

    print("Off..")

if __name__ == '__main__':
    main()


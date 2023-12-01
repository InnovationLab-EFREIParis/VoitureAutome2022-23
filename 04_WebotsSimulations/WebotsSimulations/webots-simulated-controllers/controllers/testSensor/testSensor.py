from vehicle import Driver
from controller import Lidar
from controller import Field
from controller import Supervisor

import sys
sys.path.append("../")
from car_logic import CarLogic

class SensorTest(CarLogic):
    def __init__(self):
        print('Initialisation')
        super().__init__()
        basicTimeStep = int(super().getBasicTimeStep())
        self.sensorTime = basicTimeStep // 4

        # Lidar
        self.lidar = Lidar("lidar")

        # Capteur LIDAR
        self.lidar.enable(self.sensorTime)
        self.lidar.enablePointCloud()

        # Paramètre de la voiture (position, etc..)
        self.car = super().getFromDef("vehicle")

        self.capteur_avant = super().getDevice('front_center_sensor')
        self.capteur_gauche = super().getDevice('side_left_sensor')
        self.capteur_droite = super().getDevice('side_right_sensor')
        self.capteur_avant.enable(self.sensorTime)
        self.capteur_gauche.enable(self.sensorTime)
        self.capteur_droite.enable(self.sensorTime)

        self.back_sensor = super().getDevice('back_center_sensor')

        self.back_sensor.enable(self.sensorTime)

        self.touch_sensor_front = super().getDevice('touch_sensor_front')
        self.touch_sensor_front.enable(self.sensorTime)

        self.touch_sensor_back = super().getDevice('touch_sensor_back')
        self.touch_sensor_back.enable(self.sensorTime)
        self.touch_sensor_left = super().getDevice('touch_sensor_left')
        self.touch_sensor_left.enable(self.sensorTime)
        self.touch_sensor_right = super().getDevice('touch_sensor_right')
        self.touch_sensor_right.enable(self.sensorTime)

        print('working: ', self.touch_sensor_front.getValue())

    def printSensors(self):
        front = self.capteur_avant.getValue()
        back = self.back_sensor.getValue()
        right = self.capteur_droite.getValue()
        left = self.capteur_gauche.getValue()

        front_touch = self.touch_sensor_front.getValue()


        print(f"Capteur avant  :{front:.1f}")
        print(f"Capteur arriere:{back:.1f}")
        print(f"Capteur droite  :{right:.1f}")
        print(f"Capteur gauche:{left:.1f}")
        print(f"Touch Front:{front_touch}")
        print(f"Touch back:{self.touch_sensor_back.getValue()}")
        print(f"Touch left:{self.touch_sensor_left.getValue()}")
        print(f"Touch right:{self.touch_sensor_right.getValue()}")


        super().step()
def main():
    carController = SensorTest()
    while True:
        carController.printSensors()

if __name__ == '__main__':
    main()
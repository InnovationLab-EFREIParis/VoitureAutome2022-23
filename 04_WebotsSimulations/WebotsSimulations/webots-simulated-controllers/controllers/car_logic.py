import numpy as np
import random
import sys
import json
import os.path as osp

sys.path.append("../utils/")
from trajectory import load_trajectory
from collections import deque
from dummy_slam import DummySLAM
from aeb import BasicAEB


# Webots classes
from vehicle import Driver
from controller import Lidar
from controller import Field
from controller import Supervisor
from controller import InertialUnit
from controller import Speaker



# --------------GYM----------------------------

class CarLogic(Driver):
    """
        Abstract class handling recurrent driving logic and logging.

        One should create a class inherited from CarLogic and implement a method drive() that takes arbitrary input and
        uses the `setSpeedCommand()` and `setSteeringCommand()` to control the car.
        A minimal working example is available at `minimalController/minimalController.py`

        The class is far from perfect, be careful !
    """

    def __init__(self,
                 reset_delay=12,
                 record_list = ('steering_command','lidar_range_image','speed_command','car_position','lidar_point_cloud',
                                'slam_absolute_point_cloud','slam_absolute_car_position'),
                 plot_list=('slam'),
                 path_to_trajectory=None,
                 rot_value=[0, 0, 1, 2.61799],
                 pos_value=[-1.38855, -6.67598, 0.04],
                 record_period = 0.32,
                 max_steering_angle = 0.278):




        print(f'Initialisation of CarLogic with args : {sys.argv}')

        if len(sys.argv) >= 4:
            self.dict_params = eval(sys.argv[3])
            self.def_name = sys.argv[1]
            self.path_to_save = sys.argv[2]

        else:
            self.dict_params = dict()
            self.path_to_save = None
            self.def_name = ""


        super().__init__()  # Objet héritant la classe Driver

        basicTimeStep = int(super().getBasicTimeStep())

        self.sensorTime = basicTimeStep // 4
        print(f"SensorTime : {self.sensorTime:.4f} ms")
        print("SUPERVISOR:",self.getSupervisor())
        # Lidar
        self.lidar = Lidar("lidar")

        #IMU
        self.imu = super().getDevice("inertial unit")
        print("imu debut")
        self.imu = InertialUnit("inertial unit")
        self.imu.enable(self.sensorTime)
        print("IMU: ",self.imu)

        # Capteur LIDAR
        self.lidar.enable(self.sensorTime) # Realistic time : int((1 / 10) * 1e3)
        self.lidar.enablePointCloud()
        self.len_lidar = self.lidar.getHorizontalResolution()
        print("LIDAR SIZE:", self.len_lidar)

        self.angular_resolution_deg = 360 / self.len_lidar
        self.angular_resolution_rad = 2 * np.pi / self.len_lidar

        # Paramètre de la voiture (position, etc..)

        self.max_steering_angle = max_steering_angle


        # print("SJDNK :",super().getSelected())
        # self.car = super().getSelf()
        # self.car = super().getFromDef("TT02")
        #
        # print(self.car.getField("translation"))

        self.car = super().getFromDef("TT02")
        self.trans_champs = self.car.getField("translation")
        self.rot_champs = self.car.getField("rotation")

        self.reset_delay = reset_delay

        #distance

        self.last_position = None
        self.travelled_distance = 0

        # Logging & plotting (don't use plotting)
        self.record_list = record_list
        self.init_full_logs()
        self.t_last_record = 0.
        self.record_period = record_period

        self.plot_list = plot_list


        # Default commands
        self.init_empty_buffer()
        self.setSpeedCommand(0, rec=False)
        self.setSteeringCommand(0,rec= False)


        # Capteur de balise
        self.init_balises()

        self.slam = DummySLAM()
        self.aeb = BasicAEB(self)


        self.init_spawn(path = path_to_trajectory, rot_value=rot_value, pos_value=pos_value)





    def init_empty_buffer(self, buffer_size=40):
        """

        :param buffer_size:
        :return:
        """
        self.steeringCommand_buffer = deque([0. for i in range(buffer_size)], maxlen=buffer_size)
        self.speedCommand_buffer = deque([0. for i in range(buffer_size)], maxlen=buffer_size)
        self.velocity_buffer = deque([0. for i in range(buffer_size)], maxlen=buffer_size)

    def record_kv_episode_log(self,key,value):
        """
        Add the value to the corresponding temporary key list.
        """


        if key in self.record_list and (super().getTime() - self.t_last_record >= self.record_period or super().getTime() == self.t_last_record ):

            if super().getTime() not in self.episode_log_buffer.keys():
                self.episode_log_buffer[super().getTime()] = {}
            self.t_last_record = super().getTime()
            self.episode_log_buffer[super().getTime()][key] = value


    def reset_n_write_log(self):
        """

        TODO: Problem here if some value is not recorded in certain episods ()
        TODO: write to disk every x iterations (around 40) to prevent data issues
        """
        self.full_logs.append(self.episode_log_buffer)

        self.episode_log_buffer = {}

    def init_full_logs(self):
        """
            helper function to initialize the log tracking system
        :return:
        """
        self.full_logs = []
        self.episode_log_buffer = {}

    def init_balises(self):
        """
            DEPRECATED - useful when implementing lap reward.
        """

        self.capteur_balise = super().getDevice('capteur_balise')
        self.capteur_balise.enable(self.sensorTime)
        balises = []
        loop = True
        i = 1
        while loop:
            balise = self.getFromDef(f'Balise({i})')

            if balise is None:
                break
            coord = balise.getPosition()
            balises.append((coord[0], coord[1]))
            i += 1
        self.balises = balises
        self.current_advancement = set()

        print('balises: ',self.balises)

    def init_spawn(self,rot_value,pos_value,path=None): #TODO: horrible one, change that
        if path:
            print(path)
            traj = load_trajectory(path)
            self.spawn_position = traj['positions']
            self.spawn_rotation = traj['rotations']
        else:
            self.spawn_position = pos_value
            self.spawn_rotation = rot_value

    # Remise à 0
    def respawn(self,speedCommand=0,steeringCommand=0):
        """
            Respawn can be random or fixed depending on how self.spawn_position was defined.
        """
        if not isinstance(self.spawn_position[0], list):
            xp,yp,zp = self.spawn_position
            xr, yr, zr,kr = self.spawn_rotation
        else:
            k = random.randint(0,len(self.spawn_position)-1)
            xp, yp, zp = self.spawn_position[k]
            xr, yr, zr, kr = self.spawn_rotation[k]

        INITIAL_trans = [xp + random.uniform(-0.05,0.05),yp + random.uniform(-0.05,0.05),zp]
        INITIAL_rot =  [xr,yr,zr,kr]

        self.trans_champs.setSFVec3f(INITIAL_trans)
        self.rot_champs.setSFRotation(INITIAL_rot)
        self.car.setVelocity([0,0,0,0,0,0])
        self.current_advancement = set()

        self.setSteeringCommand(steeringCommand)
        self.setSpeedCommand(speedCommand)

    def reset(self, speedCommand=0, steeringCommand=0):
        """
            Reset the car and call the respawn function
        """
        self.reset_n_write_log()
        self.respawn(speedCommand=speedCommand,steeringCommand=steeringCommand)
        for i in range(self.reset_delay):
            super().step()
        x,y,_ = self.car.getPosition()
        self.last_position = (x,y)
        self.init_empty_buffer()

    def setSpeedCommand(self,speed_command, rec=True):
        """
            Set the speed command of the car. Record the value if needed
        """
        super().setCruisingSpeed(speed_command)

        self.speedCommand = speed_command
        self.speedCommand_buffer.append(speed_command)
        if rec:
            self.record_kv_episode_log('speed_command',speed_command)


    def setSteeringCommand(self,steeringCommand, rec=True):
        """
            Set the steering command of the car. Record the value if needed
        """
        super().setSteeringAngle(steeringCommand)
        self.steeringCommand = steeringCommand
        self.steeringCommand_buffer.append(steeringCommand)
        if rec:
            self.record_kv_episode_log('steering_command',steeringCommand)

    def get_square_speed(self):
        """
            Get the squared speed of the car
        :return:
        """
        return (np.array(self.car.getVelocity()[:3])**2).sum()

    def get_speed_vector(self,normalized = False):
        """
            Get the speed vector of the car along x y z.
        :param normalized:
        :return:
        """
        if normalized:
            return (np.array(self.car.getVelocity()[:3])+1)/2
        else:
            return np.array(self.car.getVelocity()[:3])

    def get_normalized_lidar_range_image(self):
        """
            Return the lidar range image with value between 0 and 1. inf values are set to 1.
        """
        tableau = self.lidar.getRangeImage()
        etat = np.divide(np.array(tableau), 10)
        etat[~np.isfinite(etat)] = 1
        self.record_kv_episode_log('lidar_range_image', etat.tolist())

        return etat

    def get_xy_lidar(self):
        xy_lidar = list(map(lambda x: (x.x, x.y), self.lidar.getPointCloud()))
        self.record_kv_episode_log('lidar_point_cloud', xy_lidar)
        return xy_lidar

    def update_travelled_distance(self):
        """
        A recorder for the total travelled distance. Also usefull to update last position
        """
        x,y,_ = self.car.getPosition()
        self.record_kv_episode_log('car_position', (x,y))
        xp,yp = self.last_position
        self.travelled_distance += np.sqrt((x-xp)**2+(y-yp)**2)
        self.last_position = (x,y)

    def get_collision(self):
        """
        Test if a collision has a happenned
        :return:
        """
        if len(self.car.getContactPoints()) != 0:

            return True

        return False


    def check_bug(self):
        """
        Verify if something strange is happening physic wise. If so, return True to reset the simulation.
        :return:
        """
        x, y, _ = self.car.getPosition()
        xp, yp = self.last_position
        bug_threshold = 20
        if np.sqrt((x-xp)**2+(y-yp)**2) > bug_threshold:
            return True

        bug_velocity_threshold = 40 #TODO: parametrize this at class level

        if (np.array(self.car.getVelocity()[:3])**2).sum()>bug_velocity_threshold:
            return True
        return False

    def get_balise(self):
        """
        DEPRECATED - useful when implementing lap reward.
        """
        balise = self.capteur_balise.getValue()
        if balise > 700:
            return self.get_balise_id()
        return None

    def update_advancement(self, id):
        """
        DEPRECATED - useful when implementing lap reward.
        """
        if not id is None and id not in self.current_advancement:
            self.current_advancement.add(id)
            if len(self.current_advancement) >= len(self.balises):
                self.current_advancement = set()



                if self.path_to_save:
                    with open(osp.join(self.path_to_save, self.def_name+ ".json"), 'w', encoding='utf-8') as f:
                        json.dump(self.full_logs, f, ensure_ascii=False, indent=4)

                lap_field = self.car.getField("numlap")

                lap_field.setSFInt32(lap_field.getSFInt32() + 1)
                return True
            else:
                # print(f"Balise {id} passée")
                return True
        return False

    def render(self, mode="human", close=False):
        pass

    def get_balise_id(self):
        """
        DEPRECATED - useful when implementing lap reward.
        """
        car_pos = self.car.getPosition()
        dist = list(map(lambda x: (x[0]-car_pos[0])**2 + (x[1]-car_pos[1])**2, self.balises))
        return dist.index(min(dist))


    def plot(self):
        if "slam" in self.plot_list:
            self.slam.plot_map()


    def update_slam(self):
        self.slam.append_measure(absolute_position=self.car.getPosition(), lidar_point_cloud=self.lidar.getPointCloud(),
                                 imu_quaternion=self.imu.getQuaternion(),
                                 lidar_range_map=self.get_normalized_lidar_range_image())
        self.record_kv_episode_log('slam_absolute_point_cloud', self.slam.get_last_absolute_measure())
        self.record_kv_episode_log('slam_absolute_car_position', self.slam.get_position())



    def step(self):
        """
        Return True if lap over else False
        """
        self.drive()
        self.plot()
        super().step()
        self.update_slam()

        id = self.get_balise()
        if not id is None:
            if self.update_advancement(id):
                if self.current_advancement == 0:
                    return True
        return False



def main():
    pass

if __name__ == '__main__':
    main()


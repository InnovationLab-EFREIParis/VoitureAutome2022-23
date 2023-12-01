"""Voiture autonome avec utilisation d'un
LIDAR sur WEBOTS
Auteur : Chrysanthe et Jessica
"""

import numpy as np
import random
import itertools
import gym
import time
import os
import os.path as osp
import datetime


from stable_baselines3 import PPO
from stable_baselines3.common.env_checker import check_env
from stable_baselines3.common.callbacks import EvalCallback, StopTrainingOnNoModelImprovement

import sys
sys.path.append("../")
from car_logic import CarLogic

sys.path.append("../utils/")
from trajectory import load_trajectory
from utils import linear_schedule


# --------------GYM----------------------------

# Création de l'environnement GYM
class WebotsGymEnvironment(CarLogic, gym.Env):
    def __init__(self,reset_delay=6,path_to_trajectory=None):
        print('Initialisation')
        super().__init__(reset_delay=reset_delay,path_to_trajectory=path_to_trajectory)  # Objet héritant la classe Driver

        #Defining the available values for speed and steering angle
        self.speeds = [1.,0.5,0.2]
        self.steering_angles = (-0.4,-0.2,-0.1,0.0,0.1,0.2,0.4)

        #Creating all the possible combinations of actions
        self.actions = []
        for e in itertools.product(*[self.speeds,self.steering_angles]):
            self.actions.append(e)

        # self.actions += [(0.,0.)]
        print(self.actions)

        self.action_space = gym.spaces.Discrete(len(self.actions))  # actions disponibles

        min = np.zeros(self.lidar.getNumberOfPoints()+1+1+1) #Lidar information + current speed + current commands (2)
        max = np.ones(self.lidar.getNumberOfPoints()+1+1+1)


        self.observation_space = gym.spaces.Box(min, max, dtype=np.float32)  # Etat venant du LIDAR


    # Vérification de l'état de la voiture
    def observe(self):
        try:
            etat = self.get_normalized_lidar_range_image()
        except:  # En cas de non retour lidar
            print("Pas de retour du lidar")
            etat = np.zeros(self.lidar.getNumberOfPoints())


        etat = np.concatenate((etat, np.array([self.get_square_speed()/10, self.speedCommand , (self.steeringCommand-min(self.steering_angles))/(max(self.steering_angles)- min(self.steering_angles)) ])))

        return np.array(etat).astype('float32')

    def reset(self):
        super().reset(speedCommand=0, steeringCommand = 0)
        obs = self.observe()
        return obs

    # Fonction pour detection de collision et attribution des récompenses
    def evaluer(self):
        if self.get_collision():
            return -10, True
        if self.check_bug():
            print("Physic anomaly detected")
            return -30, True

        x,y,_ = self.car.getPosition()
        xp, yp = self.last_position
        return np.sqrt((x-xp)**2+(y-yp)**2),False

    # Fonction pour déplacer la voiture
    def drive(self, action):
        specs = self.actions[action]
        self.setSteeringCommand(specs[1])
        self.setSpeedCommand(specs[0])

    # Fonction step de l'environnement GYM
    def step(self, action):
        self.drive(action)
        super().step()

        obs = self.observe()

        reward, done = self.evaluer()
        self.update_travelled_distance()

        return obs, reward, done, {}

    # Fonction render de l'environnement GYM
    def render(self, mode="human", close=False):
        pass

# ----------------Programme principal--------------------
def main():
    path_to_trajectory = r"F:\Data\Maximilien\Projects\experiment-AI\toTransfer\WebotsSimulations\reinforcement-learning-trainers\worlds\trajectories\MultiTrackEasy_1--1303-1312.json"

    env = WebotsGymEnvironment(path_to_trajectory =path_to_trajectory)
    check_env(env)

    logdir = "../../logs/"

    t = datetime.datetime.now()
    t = t.strftime('-%H%M-%d%m')
    logdir = osp.join(logdir,"PPO_SR_Random_Spawn_New_map"+ t)
    logdir_tensorboard = osp.join(logdir,"tb_log")

    logdir_model = osp.join(logdir,"best_model")
    os.makedirs(logdir_model)

    # Définition modèle avec paramètre par défaut
    model = PPO('MlpPolicy', env,
                n_steps=256,
                ent_coef=0.01,
                n_epochs=5,
                batch_size=32,
                learning_rate=linear_schedule(3e-3),
                verbose=1,
                tensorboard_log=logdir_tensorboard)


    stop_train_callback = StopTrainingOnNoModelImprovement(max_no_improvement_evals=3, min_evals=5, verbose=1)
    eval_callback = EvalCallback(env, eval_freq=1e5,best_model_save_path=logdir_model,
                             log_path=logdir_tensorboard, callback_after_eval=stop_train_callback, verbose=1)

    # Entrainnement
    model.learn(total_timesteps=3*1e6, callback=eval_callback)
    print("Model Trained")

    obs = env.reset()

    for _ in range(1000000):
        # Prédiction pour séléctionner une action à partir de l'observation
        action, _states = model.predict(obs, deterministic=True)
        obs, reward, done, info = env.step(action)
        print("Good Lap captain")
        if done:
            obs = env.reset()


if __name__ == '__main__':
    main()


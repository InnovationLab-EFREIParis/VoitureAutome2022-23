import os.path as osp
import sys
# sys.path.append("../PPO_Shaped_Reward/")
# from PPO_Shaped_Reward import WebotsGymEnvironment

sys.path.append("../PPO_SR_Random_Spawn/")
from PPO_SR_Random_Spawn import WebotsGymEnvironment


from stable_baselines3 import PPO
from stable_baselines3.common.env_checker import check_env

def main():
    path_to_trajectory = r"F:\Data\Maximilien\Projects\experiment-AI\toTransfer\WebotsSimulations\reinforcement-learning-trainers\worlds\trajectories\MultiTrackHard_track1--1537-1112.json"

    path_to_logs = r"F:\Data\Maximilien\Projects\experiment-AI\toTransfer\WebotsSimulations\reinforcement-learning-trainers\logs"

    name_exp = "PPO_SR_RS_HR_highway_param-2104-1201" #"PPO_shaped_reward-1735-0212"
    path_to_model = osp.join(path_to_logs,name_exp,"best_model/best_model.zip")

    model = PPO.load(path_to_model)

    env = WebotsGymEnvironment(path_to_trajectory=path_to_trajectory)
    check_env(env)

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
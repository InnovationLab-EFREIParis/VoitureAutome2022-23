import os
import os.path as osp
import datetime
import time
import random
# from stable_baselines3 import PPO
import matplotlib.pyplot as plt
import numpy as np

from runMTD import MTD

def run(exec,model=None):
    lidar_data = np.array([random.random() for i in range(36)])
    lidar_data[~np.isfinite(lidar_data)] = 1

    lidar_data = lidar_data.tolist()
    obs = lidar_data + [random.random() for i in range(3)]

    model.predict(obs, deterministic=True)

def runMTD(driver):
    driver.drive()



def benchmark_driver(path_to_save,num_iters=4000):
    driver = MTD()
    ts = []
    ts_prc = []
    for i in range(num_iters):
        t0 = time.perf_counter()
        t0_prc = time.process_time()

        runMTD(driver)

        t1 = time.perf_counter()
        t1_prc = time.process_time()

        ts.append((t0,t1))
        ts_prc.append((t0_prc,t1_prc))
    bench2disk(ts[2:],ts_prc[2:],path_to_save)


def benchmark_model(exec,path_to_model, path_to_save, num_iters=1000):
    model = PPO.load(path_to_model)
    ts = []
    ts_prc = []
    for i in range(num_iters):
        t0 = time.perf_counter()
        t0_prc = time.process_time()

        run(exec, model=model)

        t1 = time.perf_counter()
        t1_prc = time.process_time()

        ts.append((t0,t1))
        ts_prc.append((t0_prc,t1_prc))
    bench2disk(ts[2:],ts_prc[2:],path_to_save)


def bench2disk(ts,ts_prc,path_to_save):
    dur = list(map(lambda x : x[1]-x[0],ts))

    dur_prc = list(map(lambda x: x[1] - x[0], ts_prc))
    fps = list(map(lambda x : 1/(x[1]-x[0]),ts))

    smooth_n_plot(dur, "Duration", path_to_save=path_to_save, ylabel="Duration (s)", N=15)
    smooth_n_plot(dur_prc, "Process duration", path_to_save=path_to_save, ylabel="Process duration (s)", N=15)
    smooth_n_plot(fps, "FPS", path_to_save=path_to_save, ylabel="FPS", N=15)


    ## FPS plot



def smooth_n_plot(data,name,path_to_save,ylabel,N=15):

    plt.plot(data)
    data_smoothed = np.convolve(data, np.ones(N) / N, mode='valid')
    plt.plot(data_smoothed)

    min_dur = min(data)
    plt.plot([min_dur for i in data_smoothed], color="r", linestyle='dotted')

    median_dur = np.median(data)
    plt.plot([median_dur for i in data_smoothed], color="orange", linestyle='dotted')

    plt.xlabel("Iteration")
    plt.ylabel("Time (s)")
    plt.legend()
    plt.savefig(osp.join(path_to_save, f'{name}.png'))
    plt.clf()


if __name__ == "__main__":
    name_bench = "a_test_MTD"
    path_to_save = r"results"
    exec_list = ["rl"]
    # path_to_model = r"C:\Users\diabo\Desktop\EfreiCode\M2\EngineeringProject\ExperimentAI\toTransfer\WebotsSimulations\reinforcement-learning-trainers\logs\PPO_rl_with_baseline-1232-2911\PPO_1\Voiture_autonome_Webots_PPO.zip"
    t = datetime.datetime.now()
    pathSave = osp.join(path_to_save,name_bench + f"-{t.hour}{t.minute}-{t.second}")
    os.mkdir(pathSave)
    print(pathSave)
    # benchmark(exec_list, path_to_model,path_to_save= pathSave)
    benchmark_driver(path_to_save=pathSave)
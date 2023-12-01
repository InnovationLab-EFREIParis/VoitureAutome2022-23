import numpy as np
import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation
import pandas as pd
import matplotlib
matplotlib.use('TkAgg')
import json

def read_logs(path):
    df = pd.read_json(path)

    with open(path, 'r') as f:
        data = json.load(f)

    data = data[1:]

    cols = ['steering_command','lidar_range_image','speed_command','car_position','lidar_point_cloud',
                          'slam_absolute_point_cloud','slam_absolute_car_position','virtual_lidar_range_image']

    dataList = []
    for i, episode in enumerate(data):
        for time,measures in episode.items():
            print(time)
            tmp = [i,time]
            for col in cols:
                if col in measures.keys():
                    tmp.append(measures[col])
                else:
                    tmp.append(None)

            dataList.append(tmp)
    df = pd.DataFrame(dataList,columns=['num_episode','timestamp'] + cols)

    df['slam_absolute_car_position_x'] = df['slam_absolute_car_position'].apply(lambda x: x[0] if not x is None else None)

    df['slam_absolute_car_position_y'] = df['slam_absolute_car_position'].apply(lambda x: x[1] if not x is None else None)

    df['car_position_x'] = df['car_position'].apply(lambda x: x[0] if not x is None else None)

    df['car_position_y'] = df['car_position'].apply(lambda x: x[1] if not x is None else None)

    return df

def slam_xy_extractor(df):
    xs = []
    ys = []
    for i in df.index:
        df.loc[i]
        xs += [x[0] for x in df.loc[i]]
        ys += [x[1] for x in df.loc[i]]

    return xs,ys

def polar_lidar(df):
    fig = plt.figure(figsize = (12,8))
    fig.tight_layout()

    # POLAR LIDAR
    ax1 = fig.add_subplot(2, 2, 1,projection='polar')
    ax1.set_rlim(0, 0.35)
    scat = ax1.scatter([], [])

    ## SLAM
    axMap = fig.add_subplot(2, 2, 2)

    axMap.axis('scaled')
    line_wall, = axMap.plot([],[], '*k', markersize=2)
    line_trajectory_gt, = axMap.plot([],[], '-r', label="GT trajctory")
    line_trajectory_slam, = axMap.plot([],[], '-b',label = 'SLAM trajectory')
    line_car_position, = axMap.plot([],[], '.r',label = 'Car position',markersize=4)
    axMap.set(xlim=[-1, 9], ylim=[-7, 2])
    axMap.legend()

    # POLAR VIRTUAL LIDAR
    ax_virtual = fig.add_subplot(2, 2, 3,projection='polar')
    ax_virtual.set_rlim(0, 0.35)
    scat_virtual = ax_virtual.scatter([], [])


    # Define the update function for the animation
    def update(num):
        print(num)
        new_data = df.iloc[num]["lidar_range_image"]
        angles = np.linspace(0, 2 * np.pi, len(new_data))
        scat.set_offsets(np.column_stack((angles, new_data)))

        print(df.iloc[num])
        if True:
            new_data = df.iloc[num]["virtual_lidar_range_image"]
            angles = np.linspace(0, 2 * np.pi, len(new_data))
            scat_virtual.set_offsets(np.column_stack((angles, new_data)))


        # x,y = slam_xy_extractor(df.iloc[:num]['slam_absolute_point_cloud'])
        # line_wall.set_xdata(x)
        # line_wall.set_ydata(y)
        #
        # line_trajectory_gt.set_xdata(df.iloc[:num]['slam_absolute_car_position_x'])
        # line_trajectory_gt.set_ydata(df.iloc[:num]['slam_absolute_car_position_y'])
        #
        # line_trajectory_slam.set_xdata(df.iloc[:num]['car_position_x'])
        # line_trajectory_slam.set_ydata(df.iloc[:num]['car_position_y'])
        #
        # line_car_position.set_xdata(df.iloc[num]['slam_absolute_car_position_x'])
        # line_car_position.set_ydata(df.iloc[num]['slam_absolute_car_position_y'])

        return [scat] + [line_wall]

    # Create the animation
    ani = FuncAnimation(fig, update, frames=range(0, df.shape[0]), repeat=False,interval=8)
    plt.show()



def main(path):
    df = read_logs(path)
    polar_lidar(df.loc[(df.num_episode==0)].dropna(subset="lidar_range_image"))

if __name__ == '__main__':

    path_to_log = r'F:\Data\Maximilien\Projects\experiment-AI\toTransfer\WebotsSimulations\reinforcement-learning-trainers\logs\JSON_run_debug\dataFTGNew.json'

    main(path_to_log)
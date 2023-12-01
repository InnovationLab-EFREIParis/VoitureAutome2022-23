


import numpy as np
import matplotlib.pyplot as plt
from IPython import get_ipython
# get_ipython().run_line_magic('matplotlib', 'qt')
from controller import Robot, Camera, Display
import cv2
from scipy.spatial.transform import Rotation as Rotation


# Display {
#   SFInt32 width  64   # [1, inf)
#   SFInt32 height 64   # [1, inf)
# }

# -0.16 0.005 0.09

class DummySLAM():

    def __init__(self, noise_odometry = 0.2, noise_lidar = 0., init_plot=False):
        self.noise_odometry = noise_odometry
        self.noise_lidar = noise_lidar
        self.car_positions = []
        self.lidar_distance_threshold = 0.09 #Lidar get less accurate with distance. We can set a treshold above which we don't record the value


        # Contain the lidar map. Can get very big fast TODO: clean out at the end of a lap.
        self.lidar_absolute_measurement = []


        # Initialize plotting variables
        if init_plot:
            self.fig = plt.figure()
            self.line1, = plt.plot((2,2), (4,5), '*k')  # so that we can update data later
            self.line_traj, = plt.plot((2,2), (4,5), '-r')  # so that we can update data later




    def append_measure(self,absolute_position,lidar_point_cloud, imu_quaternion,lidar_range_map):
        trans_x, trans_y = -0.16, 0.0
        trans = np.array([[trans_x,trans_y,0.09]])

        noisy_position = absolute_position # TODO: add noise

        lidar_point_cloud = np.array(list(map(lambda x: [x.x,x.y,x.z],lidar_point_cloud)))
        idx = lidar_range_map <= self.lidar_distance_threshold

        STR = Rotation.from_quat(imu_quaternion)

        # print("ABS POS BEFORE: ",noisy_position)
        noisy_position = (np.array(noisy_position) - STR.apply(trans))[0]
        # print("ABS POS AFTER: ",noisy_position)

        self.car_positions.append(noisy_position[:2].tolist())

        lidar_point_cloud = np.array(lidar_point_cloud)[idx]

        global_points = []
        for RelativeCloudPoint in lidar_point_cloud:
            Point2 = STR.apply(RelativeCloudPoint)
            global_points.append((np.array(Point2) + np.array(noisy_position))[:2].tolist())

        self.lidar_absolute_measurement.append(global_points)

    def get_position(self):
        return self.car_positions[-1]

    def get_last_absolute_measure(self):
        return self.lidar_absolute_measurement[-1]

    def plot_current_view(self):
        pass

    def plot_map(self):

        x,y = self.get_absolute_x_y()
        # update data
        self.line1.set_ydata(y)
        self.line1.set_xdata(x)
        ax = plt.gca()
        ax.axis('equal')
        ax.set(xlim=[min(x),max(x)], ylim=[min(y),max(y)])

        ax.set(xlim=[-1,7], ylim=[-7,2])


        xp = [i[0] for i in self.car_positions]
        yp = [i[1] for i in self.car_positions]

        self.line_traj.set_ydata(yp)
        self.line_traj.set_xdata(xp)


        # redraw the canvas
        self.fig.canvas.draw()

        # convert canvas to image
        img = np.fromstring(self.fig.canvas.tostring_rgb(), dtype=np.uint8,
                            sep='')
        img = img.reshape(self.fig.canvas.get_width_height()[::-1] + (3,))

        img = cv2.cvtColor(img, cv2.COLOR_RGB2BGR)
        # display image with opencv or any operation you like
        cv2.imshow("plot", img)
        k = cv2.waitKey(33) & 0xFF




    def get_absolute_x_y(self):
        x = [z[0] for sub in self.lidar_absolute_measurement for z in sub]
        y = [z[1] for sub in self.lidar_absolute_measurement for z in sub]
        return x,y







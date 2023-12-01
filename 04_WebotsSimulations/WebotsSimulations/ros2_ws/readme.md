# ROS2 foxy workspace

This folder contains the ROS project.  

## Prerequisites
-Have an Ubuntu 20.04.5 LTS machine
-Have ROS2 foxy installed on it
## Installation
Download this workspace and check in ros2_ws/src wether the webots_ros2 folder is empty or not.
If it is empty follow [this](https://github.com/cyberbotics/webots_ros2/wiki/Linux-Installation-Guide) installation procedure in our ros2_ws folder.
# Run the project
1. cd to the ros2_ws folder
2. Run the init_launch.sh to start the car program:
```bash
./init_launch.sh
```
3. On the same network, launch the client app with:
```bash
source /opt/ros/foxy/setup.bash
```
```bash
source install/local_setup.bash
```
```
ros2 launch client client_launch.py
```
# Some explanations about the project
We have followed the micro-services architecture principle to create our differents ros nodes.
In the src folder are located 3 packages:

-interfaces: an interface to create new ros objects (actions, services and messages)

-my_package: the core project, in the launch folder is described how to project is launched. In "my_package" sub-folder is described the differents nodes.

-webots_ros2: allow to control webots objects with ros


*not finished...*



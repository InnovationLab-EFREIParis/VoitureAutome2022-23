# Webots Simulations

This folder contains different Webots simulations.  

## Resources
## Webots
Nice tutorials to learn how to use [Webots](https://cyberbotics.com/doc/guide/tutorials?tab-language=python)
Following these will make you save a lot of time.

## Stable-baselines 3 and RL

Stable-baselines 3 is a python library that provide many useful implementation of SOTA reinforcement learning algorithm.
It's documentation features a nice [set of information](https://stable-baselines3.readthedocs.io/en/master/guide/rl_tips.html) to start doing RL experiments that works.

## Example project for the Race

[TODO]


## Important code in this repo

#### car_logic.py
Contains the `CarLogic` class that provide a solid base for a car controlled with the `Driver` library of Webots. 

# How to run the ROS2 project ?

1. Install ROS2 foxy following [this tutorial](https://docs.ros.org/en/foxy/Installation.html)
2. Pull the project in WSL2 or an Linux machine and ```cd /path/to/experiment-AI/toTransfer/WebotsSimulations/ros2_ws```
3. Run the following commands inside ros2_ws:
    ```source /opt/ros/foxy/setup.bash```
    ```. install/setup.bash```
    ```colcon build```
4. Run the launch file: ```ros2 launch py_car launch.py```
5. To open rqt_graph, run the following commands: ```source /opt/ros/foxy/setup.bash``` and ```rqt_graph```

## Webots
![](../ressources/gifs/tuto_webots_small.gif)
## TODO
- [ ] Changer les messages `is_race_on` et `is_connected` en un unique message "`run`". Rassembler la logique de ce message dans le noeud communication.
- [ ] Driver dynamique (implique de changer un fichier .rdf ?)

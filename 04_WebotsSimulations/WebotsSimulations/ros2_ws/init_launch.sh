#!/bin/bash

DIR=$PWD
echo "Quel noeud brain voulez-vous utiliser?"
read brain_node

gnome-terminal --tab --title="ROS" -e "bash -c 'source /opt/ros/foxy/setup.bash; sudo apt install python3-pip python3-rosdep python3-colcon-common-extensions; sudo rosdep init && rosdep update; rosdep install --from-paths src --ignore-src --rosdistro foxy; rosdep install -y -r -q --from-paths src --ignore-src --rosdistro foxy; sudo colcon build; source install/local_setup.bash; ros2 launch my_package robot_launch.py brain_node:='$brain_node'; exec bash'" \
--tab --title="FREE" -e "bash -c 'source /opt/ros/foxy/setup.bash; source install/local_setup.bash; exec bash'" \
--tab --title="RQT_GRAPH" -e "bash -c 'source /opt/ros/foxy/setup.bash; rqt_graph; exec bash'" \
--tab --title="RVIZ" -e "bash -c 'source /opt/ros/foxy/setup.bash; rviz2; exec bash'"
import os
import pathlib
import launch
import time
from launch_ros.actions import Node
from launch import LaunchDescription
from launch.substitutions import LaunchConfiguration
from launch.actions import DeclareLaunchArgument
from ament_index_python.packages import get_package_share_directory


def generate_launch_description():

    client = Node(
        package='client',
        executable='client_node',
    )

    app = Node(
        package='client',
        executable='app',
    )
    

    return LaunchDescription([
        client,
        app
    ])
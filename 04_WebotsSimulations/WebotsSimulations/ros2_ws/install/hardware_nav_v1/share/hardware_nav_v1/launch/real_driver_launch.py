import os
import pathlib
import launch
from launch_ros.actions import Node
from launch import LaunchDescription
from launch.substitutions import LaunchConfiguration
from launch.actions import DeclareLaunchArgument
from launch.substitutions.path_join_substitution import PathJoinSubstitution
from ament_index_python.packages import get_package_share_directory
import launch_ros.actions


def generate_launch_description():
        # servo = Node(
        #         package='hardware_nav_v1',
        #         executable='servo',
        #     )
        
        # motor = Node(
        #         package='hardware_nav_v1',
        #         executable='motor',
        #     )
        
        driver = Node(
                package='hardware_nav_v1',
                executable='driver',
            )
        
        # lidar = Node(
        #         package='sllidar_ros2',
        #         executable='sllidar_a3_launch',
        #         parameters = [{'serial_port': '/dev/ttyUSB1'}],
        #     )
        
        lidar = Node(
            package='sllidar_ros2',
            executable='sllidar_node',
            name='sllidar_node',
            parameters=[{'channel_type':'serial',
                         'serial_port': '/dev/ttyUSB0', 
                         'serial_baudrate': 256000, 
                         'frame_id': "laser_frame",
                         'inverted': False, 
                         'angle_compensate': True, 
                         'scan_mode': 'Standard'}])

        
        tf = Node(
            package='tf2_ros',
            executable='static_transform_publisher',
            arguments = ['0', '0', '0', '0', '0', '0', 'world', 'laser_frame']
        )

        tf2 = Node(
            package='tf2_ros',
            executable='static_transform_publisher',
            arguments = ['0', '0', '0', '0', '0', '0', 'world', 'frame_preprocessed']
        )

        return LaunchDescription([
            #servo,
            #motor,
            driver,
            lidar,
            tf,
            tf2
        ])
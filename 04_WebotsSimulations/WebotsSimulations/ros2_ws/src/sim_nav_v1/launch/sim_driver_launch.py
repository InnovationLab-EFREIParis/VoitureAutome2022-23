import os
import pathlib
import launch
import time
from launch_ros.actions import Node
from launch import LaunchDescription
from webots_ros2_driver.webots_launcher import WebotsLauncher, Ros2SupervisorLauncher
from webots_ros2_driver.utils import controller_url_prefix
from launch.substitutions import LaunchConfiguration
from launch.actions import DeclareLaunchArgument
from launch.substitutions.path_join_substitution import PathJoinSubstitution
from ament_index_python.packages import get_package_share_directory
import launch_ros.actions



def generate_launch_description():
        
        package_dir = get_package_share_directory('sim_nav_v1')
        robot_description = pathlib.Path(os.path.join(package_dir, 'resource', 'my_robot.urdf')).read_text()


        my_robot_driver = Node(
            package='webots_ros2_driver',
            executable='driver',
            remappings=[('/my_robot/lidar' , '/scan')],
            output='screen',
            additional_env={'WEBOTS_CONTROLLER_URL': controller_url_prefix() + 'my_robot'},
            parameters=[
                {'robot_description': robot_description},
            ]
        )

        ros2_supervisor = Ros2SupervisorLauncher()

        reset_handler = launch.actions.RegisterEventHandler(
            event_handler=launch.event_handlers.OnProcessExit(
                target_action=ros2_supervisor,
                on_exit=my_robot_driver,
            )
        )

        webots = WebotsLauncher(
            world=os.path.join(package_dir, 'worlds', 'my_world.wbt')
        )

        return LaunchDescription([
            my_robot_driver,
            reset_handler,
            webots,
            ros2_supervisor,
            launch.actions.RegisterEventHandler(
                event_handler=launch.event_handlers.OnProcessExit(
                    target_action=webots,
                    on_exit=[
                        launch.actions.UnregisterEventHandler(
                            event_handler=reset_handler.event_handler
                        ),
                        launch.actions.EmitEvent(event=launch.events.Shutdown())
                    ],
                )
            )
        ])
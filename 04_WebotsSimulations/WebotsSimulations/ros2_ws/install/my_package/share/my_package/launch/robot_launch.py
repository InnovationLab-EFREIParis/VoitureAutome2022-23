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
    isSimulation = input("Are you starting a simulation? (y/n): ")
    while(isSimulation != 'y' and isSimulation != 'n'):
        print("Incorrect answer")
        isSimulation = input("Are you starting a simulation? (y/n): ")

    ######################SLAM#######################################
    '''
    #test TF2
    config = os.path.join(
        get_package_share_directory('my_package'),
        'config', 'my_robot.tf2')

    tf2_publisher = launch_ros.actions.Node(
        package='tf2_ros',
        executable='static_transform_publisher',
        arguments=['0', '0', '0.5', '0', '0', '0', 'base_link', 'lidar']
    )

    tf2_publisher2 = launch_ros.actions.Node(
        package='tf2_ros',
        executable='static_transform_publisher',
        arguments=['0', '0', '0', '0', '0', '0', 'base_link', 'map']
    )

    #fin test TF2
    '''
    ######################END OF SLAM################################

    ######################Starting a simulation######################
    if(isSimulation == 'y'):
        driverPackage = get_package_share_directory('sim_nav_v1')
        driverPath = str(pathlib.Path(os.path.join(driverPackage, 'launch', 'sim_driver_launch.py')))

        include_child_launch = launch.actions.IncludeLaunchDescription(launch.launch_description_sources.PythonLaunchDescriptionSource(driverPath))


        brain_node = LaunchConfiguration('brain_node')

        brain_node_launch_arg = DeclareLaunchArgument(
            'brain_node',
            default_value='brain_node'
        )

        brain = Node(
                package='my_package',
                executable=brain_node,
            )

        communication = Node(
                package='my_package',
                executable='communication_node',
            )
        
        lidar_preprocessing = Node(
                package='my_package',
                executable='lidar_preprocessing'
            )

        return LaunchDescription([
            brain_node_launch_arg,
            brain,
            communication,
            lidar_preprocessing,
            include_child_launch,
        ])
    ######################Starting for real######################
    else:
        driverPackage = get_package_share_directory('hardware_nav_v1')
        driverPath = str(pathlib.Path(os.path.join(driverPackage, 'launch', 'real_driver_launch.py')))

        include_child_launch = launch.actions.IncludeLaunchDescription(launch.launch_description_sources.PythonLaunchDescriptionSource(driverPath))

        brain_node = LaunchConfiguration('brain_node')

        brain_node_launch_arg = DeclareLaunchArgument(
            'brain_node',
            default_value='brain_node'
        )

        brain = Node(
                package='my_package',
                executable=brain_node,
            )

        communication = Node(
                package='my_package',
                executable='communication_node',
            )
        lidar_preprocessing = Node(
            package='my_package',
            executable='lidar_preprocessing',
            )
        
        # plotter = Node(
        #         package='my_package',
        #         executable='plotter_node',
        #     )

        return LaunchDescription([
            brain_node_launch_arg,
            brain,
            communication,
            lidar_preprocessing,
            #plotter,
            include_child_launch
        ])
from setuptools import setup

package_name = 'my_package'
data_files = []
data_files.append(('share/ament_index/resource_index/packages', ['resource/' + package_name]))
data_files.append(('share/' + package_name + '/launch', ['launch/robot_launch.py']))
data_files.append(('share/' + package_name + '/config', ['config/mapper_params_online_async.yaml']))
data_files.append(('share/' + package_name + '/config', ['config/calibrate_activity_profiles.csv']))
data_files.append(('share/' + package_name, ['package.xml']))


setup(
    name=package_name,
    version='0.0.0',
    packages=[package_name],
    data_files=data_files,
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='user',
    maintainer_email='user.name@mail.com',
    description='TODO: Package description',
    license='TODO: License declaration',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'brain_node = my_package.brain_node:main',
            'communication_node = my_package.communication_node:main',
            'brain_node_MTD = my_package.brain_node_MTD:main',
            'brain_node_minimal = my_package.brain_node_minimal:main',
            'brain_node_calibrate = my_package.brain_node_calibrate:main',
            'brain_node_manual = my_package.brain_node_manual:main',
            'lidar_preprocessing = my_package.lidar_preprocessing:main',
            'plotter_node = my_package.plotter_node:main',
            'brain_node_MTD_no_preprocessing = my_package.brain_node_MTD_no_preprocessing:main',
            'brain_node_simple_backup = my_package.brain_node_simple_backup:main'


        ],
    },
)
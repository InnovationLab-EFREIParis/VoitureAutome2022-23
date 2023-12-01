from setuptools import setup

package_name = 'sim_nav_v1'
data_files = []
data_files.append(('share/ament_index/resource_index/packages', ['resource/' + package_name]))
data_files.append(('share/' + package_name + '/launch', ['launch/sim_driver_launch.py']))
data_files.append(('share/' + package_name + '/resource', ['resource/my_robot.urdf']))
data_files.append(('share/' + package_name + '/config', ['config/my_robot.tf2']))
data_files.append(('share/' + package_name + '/worlds', ['worlds/my_world.wbt']))
data_files.append(('share/' + package_name + '/protos', ['protos/TT02.proto']))
data_files.append(('share/' + package_name + '/protos', ['protos/016.2-Carrosserie realiste.stl']))
data_files.append(('share/' + package_name + '/protos', ['protos/TT02Wheel.proto']))
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
            'my_robot_driver = sim_nav_v1.my_robot_driver:main',
        ],
    },
)
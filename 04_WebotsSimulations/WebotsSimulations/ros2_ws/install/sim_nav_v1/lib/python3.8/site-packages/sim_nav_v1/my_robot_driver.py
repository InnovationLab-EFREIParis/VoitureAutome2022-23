from asyncio import sleep
import rclpy
from interfaces.msg import MonAckermannDrive
from rclpy.action import ActionClient
from rclpy.action.client import ClientGoalHandle
from std_msgs.msg import Bool
from interfaces.action import DriverAction
from interfaces.msg import DrivingInstruction
from sensor_msgs.msg import LaserScan
from asyncio import Future
from collections import deque



class MyRobotDriver:
    def init(self, webots_node, properties):
        self.__robot = webots_node.robot
        self._current_goal_future = None


        
        rclpy.init(args=None)
        self.__node = rclpy.create_node('my_robot_driver')

        #experimental
        self.__node.create_subscription(MonAckermannDrive, 'cmd_ackermann', self.__cmd_ackermann_callback, 1)
        self.__node.create_subscription(LaserScan, 'LidarScanPreprocessed', self.__cmd_scan_callback, 1)
        #

        self.subscriber_ = self.__node.create_subscription(Bool, 'IsConnected', self.getMessageConnexion, 10)
        self.subscriber_race = self.__node.create_subscription(Bool, 'IsRaceOn', self.getMessageRace, 10)

        self._action_client = ActionClient(self.__node, DriverAction, 'driverAction')

    def send_goal(self, goal_msg):
        self._action_client.wait_for_server()

        self._send_goal_future = self._action_client.send_goal_async(goal_msg)

        self._send_goal_future.add_done_callback(self.goal_response_callback)

    def goal_response_callback(self, future):
        goal_handle = future.result()
        if not goal_handle.accepted:
            self.__node.get_logger().info('Goal rejected :(')
            return

        #self.__node.get_logger().info('Goal accepted :)')

        self._current_goal_future = goal_handle.get_result_async()
        self._current_goal_future.add_done_callback(self.get_result_callback)

    def get_result_callback(self, future):
        result = future.result().result
        self.__robot.setCruisingSpeed(result.result.instruction.speed)
        self.__robot.setSteeringAngle(result.result.instruction.steering_angle)
        

    def getMessageRace(self, message: Bool):
        if(message.data):
            self.isRaceOn = True
        else:
            self.isRaceOn = False

    def getMessageConnexion(self, message: Bool):
        if(message.data):
            self.isConnected = True
        else:
            self.isConnected = False

    def __cmd_ackermann_callback(self, message):
        self.__robot.setCruisingSpeed(message.speed)
        self.__robot.setSteeringAngle(message.steering_angle)

    def __cmd_scan_callback(self, message):
        goal_msg = DriverAction.Goal()
        goal_msg.instruction = DrivingInstruction()
        goal_msg.instruction.lidar_scan = message.ranges

        self.send_goal(goal_msg)
    
    def init_empty_buffer(self, buffer_size=40):
        """

        :param buffer_size:
        :return:
        """
        self.steeringCommand_buffer = deque([0. for i in range(buffer_size)], maxlen=buffer_size)
        self.speedCommand_buffer = deque([0. for i in range(buffer_size)], maxlen=buffer_size)

    def init_spawn(self,rot_value,pos_value,path=None): #TODO: horrible one, change that
        if path:
            print(path)
            traj = load_trajectory(path)
            self.spawn_position = traj['positions']
            self.spawn_rotation = traj['rotations']
        else:
            self.spawn_position = pos_value
            self.spawn_rotation = rot_value

    def respawn(self,speedCommand=0,steeringCommand=0):
        """
            Respawn can be random or fixed depending on how self.spawn_position was defined.
        """
        if not isinstance(self.spawn_position[0], list):
            xp,yp,zp = self.spawn_position
            xr, yr, zr,kr = self.spawn_rotation
        else:
            k = random.randint(0,len(self.spawn_position)-1)
            xp, yp, zp = self.spawn_position[k]
            xr, yr, zr, kr = self.spawn_rotation[k]

        INITIAL_trans = [xp + random.uniform(-0.05,0.05),yp + random.uniform(-0.05,0.05),zp]
        INITIAL_rot =  [xr,yr,zr,kr]

        self.trans_champs.setSFVec3f(INITIAL_trans)
        self.rot_champs.setSFRotation(INITIAL_rot)
        self.__robot.setVelocity([0,0,0,0,0,0])

        self.__robot.setCruisingSpeed(speedCommand)
        self.__robot.setSteeringAngle(steeringCommand)

    def step(self):
        rclpy.spin_once(self.__node, timeout_sec=0)
        if self._current_goal_future is not None:
            rclpy.spin_until_future_complete(self.__node, self._current_goal_future)
            self._current_goal_future = None

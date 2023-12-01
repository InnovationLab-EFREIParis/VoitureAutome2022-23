import rclpy
from rclpy.node import Node
from std_msgs.msg import String
from std_msgs.msg import Bool
from rclpy.action import ActionClient
from interfaces.action import DriverAction
from rclpy.action import ActionServer
import numpy as np
from .aeb import BasicAEB


from interfaces.action import DriverAction


class BrainNode(Node):

    def __init__(self):
        super().__init__('brain_node')
        self.isConnected = False
        self.isRaceOn = False
        self.subscriber_connexion = self.create_subscription(Bool, 'IsConnected', self.getMessageConnexion, 10)
        self.subscriber_race = self.create_subscription(Bool, 'IsRaceOn', self.getMessageRace, 10)

        self._action_driver_server = ActionServer(
            self,
            DriverAction,
            'driverAction',
            self.execute_callback)

        self.max_steering_angle = 0.278

        self.get_logger().info(str("Successfully created a brain node with minimal driving policy"))

    def execute_callback(self, goal_handle):
        #self.get_logger().info('Executing goal...')
        lidar_scan = goal_handle.request.instruction.lidar_scan
        
        result = DriverAction.Result()

        #############################################
        full_lidar = lidar_scan.tolist()
        
        front_dist = np.array(full_lidar)
        
        min_front_dist = front_dist[np.isfinite(front_dist)].min()
        id = front_dist.tolist().index(min_front_dist)

        if id < len(front_dist)/2:
            speedCommand = 0.5
            steeringCommand = -self.max_steering_angle 
        else:
            speedCommand = 0.5
            steeringCommand = self.max_steering_angle 


        if(self.isRaceOn and self.isConnected):
            result.result.instruction.speed = float(speedCommand)
            result.result.instruction.steering_angle = float(steeringCommand)
        else:
            result.result.instruction.speed = float(0)
            result.result.instruction.steering_angle = float(0)


        #############################################
        feedback_msg = DriverAction.Feedback()
        goal_handle.publish_feedback(feedback_msg)

        goal_handle.succeed()
        
        return result

    def dist_to_speed(self, min_ttc):
        for i, ttc_thresh in enumerate(self.speed_profile["dist_threshold"]):
            if min_ttc <= ttc_thresh:
                return self.speed_profile["speed"][i]
        return self.speed_profile["speed"][-1]


    def getMessageRace(self, message: Bool):
        print(message.data)
        if(message.data):
            self.isRaceOn = True
        else:
            self.isRaceOn = False

    def getMessageConnexion(self, message: Bool):
        print(message.data)
        if(message.data):
            self.isConnected = True
        else:
            self.isConnected = False

def main(args=None):
    rclpy.init(args=args)

    brain_node = BrainNode()

    rclpy.spin(brain_node)

    # Destroy the node explicitly
    # (optional - otherwise it will be done automatically
    # when the garbage collector destroys the node object)
    brain_node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()

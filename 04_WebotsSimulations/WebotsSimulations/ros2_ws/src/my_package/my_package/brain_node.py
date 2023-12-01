import rclpy
from rclpy.node import Node
from std_msgs.msg import String
from std_msgs.msg import Bool
from rclpy.action import ActionClient
from interfaces.action import DriverAction
from rclpy.action import ActionServer
import numpy as np



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
        self.get_logger().info(str("Successfully created a brain node with STUPID driving policy"))

    def execute_callback(self, goal_handle):
        #self.get_logger().info('Executing goal...')
        lidar_scan = goal_handle.request.instruction.lidar_scan
        result = DriverAction.Result()

        #############################################

        safety_bubble_r = 0.030


        aperture_half_angle = 70 #(deg)
        aperture = 13 # 5 for 36

        full_lidar = lidar_scan.tolist()

        angular_resolution_deg = 360/len(full_lidar)

        aperture = int(aperture_half_angle / angular_resolution_deg)

        lidar = full_lidar[-aperture:] + full_lidar[:aperture+1]
        print("APERTURE: ",aperture)
        print("TOTAL WIDTH LIDAR:", len(lidar))
        print("LIDAR: ", lidar)


        closest_dist = min(lidar)
        closest_idx = lidar.index(closest_dist)

        phi = 2*np.pi/len(full_lidar)

        print("CLOSEST DOST: ",closest_dist)
        print("dist idx: ", [abs(i-closest_idx) for i in  range(len(lidar))])

        dists = [2 * closest_dist * abs(np.sin(abs(i-closest_idx) * phi/2))
            for i in range(len(lidar))]
        print("Idx closest: ", closest_idx)
        print("Dists: ", dists)

        mask = [ i <= safety_bubble_r for i in dists]

        print("MASK: ", mask)

        lidar_bubbled = np.array(lidar)
        lidar_bubbled[mask] = 0
        print("LIDAR BUBBLED: ",lidar_bubbled)

        max_streak = 0
        streak = 0
        start_streak = 0
        for i,v in enumerate(lidar_bubbled):

            if v != 0.:
                if streak > 0:
                    streak +=1
                    if max_streak <= streak:
                        start_max_streak = start_streak
                        max_streak = streak
                else:
                    streak = 1
                    start_streak = i
            else:
                if streak >= max_streak:
                    max_streak = streak
                    start_max_streak = start_streak
                    streak = 0

        print(start_max_streak," ",max_streak+start_max_streak)

        lidar_bubbled = lidar_bubbled.tolist()
        idx_goal = lidar_bubbled.index(max(lidar_bubbled[start_max_streak:max_streak+start_max_streak+1]))


        print("IDEX GOAL: ", idx_goal)

        if(self.isRaceOn and self.isConnected):
            if idx_goal - aperture == 0:
                result.result.instruction.speed = float(2)
                result.result.instruction.steering_angle = float(0)
            elif idx_goal - aperture < 0:
                result.result.instruction.speed = float(0.5)
                result.result.instruction.steering_angle = float(-0.4)
            else:
                result.result.instruction.speed = float(0.5)
                result.result.instruction.steering_angle = float(0.4)
        else:
            result.result.instruction.speed = float(0)
            result.result.instruction.steering_angle = float(0)

        
        '''
        if(self.isRaceOn and self.isConnected):
            result.result.instruction.speed = float(speedCommand)
            result.result.instruction.steering_angle = float(steeringCommand)
        else:
            result.result.instruction.speed = float(0)
            result.result.instruction.steering_angle = float(0)
        '''
        #############################################
        

        feedback_msg = DriverAction.Feedback()
        goal_handle.publish_feedback(feedback_msg)

        goal_handle.succeed()
        
        return result

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

    #############################################
    def ttc_to_speed(self, min_ttc):
        if min_ttc <= 0.2:
            return 0.5
        elif min_ttc <= 0.9:
            return 1
        elif min_ttc <= 1.5:
            return 3
        else:
            return 6
    #############################################

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
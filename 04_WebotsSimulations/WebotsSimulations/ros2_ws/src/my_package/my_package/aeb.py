import numpy as np
from collections import deque


class BasicAEB():
    """
        Autonomous Emergency Brake Module

        Needs (or optionnal):
        - tight_front_lidar *
        - distance_sensor_front
        - distance_sensor_back

    """

    def __init__(self,
                 aeb_ttc_threshold=0.50,
                 aeb_lidar_threshold=.32,#0.3
                 status="on"
                 ):

        self.status = status

        self.aeb_ttc_threshold = aeb_ttc_threshold
        self.aeb_lidar_threshold = aeb_lidar_threshold
        self.aeb_retro_speed = -3.16587354 #very weird speed to get an AEB signature. Pretty ugly but it works :)
        self.max_steering_angle = 0.278
        buffer_size = 40 #40
        self.speedCommand_buffer = deque([0. for i in range(buffer_size)], maxlen=buffer_size)

    def check(self,speedCommand,steeringCommand,lidar_tight_front,direction):
        """
            Forward throught the AEB.
        """
        self.speedCommand_buffer.append(speedCommand)
        # No operation if aeb is desactivated.
        if self.status == "off":
            return speedCommand,steeringCommand

        ## TODO : need to be adapted because we don't have speed anymore
        is_braking = False

        if np.quantile(lidar_tight_front,q=0.3) < self.aeb_lidar_threshold :
            speedCommand = self.aeb_retro_speed
            steeringCommand = -self.max_steering_angle * direction
            is_braking = True

        ## Oscillating AEB is a problem, here we do AEB for at lest x simulation step (will need to do that timing wise)
        buffer_aeb_binary_mask = [1 if cmd == self.aeb_retro_speed else 0 for cmd in self.speedCommand_buffer]
        if sum(buffer_aeb_binary_mask[-19:]) > 0 and buffer_aeb_binary_mask[-20] == 0 and buffer_aeb_binary_mask[-1]==1:
            speedCommand = self.aeb_retro_speed
            steeringCommand = -self.max_steering_angle * direction
            is_braking = True

        return speedCommand, steeringCommand, is_braking

    def activate(self):
        self.status = "on"

    def desactivate(self):
        self.status = "off"

    def get_status(self):
        return self.status
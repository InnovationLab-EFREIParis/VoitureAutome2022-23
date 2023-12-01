import numpy as np



class BasicAEB():
    """
        Autonomous Emergency Brake Module

        Needs (or optionnal):
        - tight_front_lidar *
        - distance_sensor_front
        - distance_sensor_back

    """

    def __init__(self,
                 controller,
                 aeb_ttc_threshold=0.5,
                 aeb_lidar_threshold=.022,
                 status="on"
                 ):

        self.status = status

        self.controller = controller
        self.aeb_ttc_threshold = aeb_ttc_threshold
        self.aeb_lidar_threshold = aeb_lidar_threshold
        self.aeb_retro_speed = -3.16587354 #very weird speed to get an AEB signature. Pretty ugly but it works :)

    def check(self,speedCommand,steeringCommand,full_lidar,aperture_tight_front,direction):
        """
            Forward throught the AEB.
        """

        # No operation if aeb is desactivated.
        if self.status == "off":
            return speedCommand,steeringCommand

        lidar_tight_front = full_lidar[-aperture_tight_front:] + full_lidar[:aperture_tight_front + 1]

        speed_vector_absolute = self.controller.get_speed_vector()
        rotation = np.reshape(self.controller.car.getOrientation(), (3, 3))

        speed_vector_relative = rotation.T @ np.array(speed_vector_absolute)


        vx = speed_vector_relative[0]

        # use forward speed to compute a Time To Collision (TTC). This assume that obstacle are still, which is wrong.
        lidar_speed = np.array([vx * np.cos(i * self.controller.angular_resolution_rad) for i in range(self.controller.len_lidar)])
        lidar_speed[lidar_speed < 0] = 0
        ttc = 10 * np.array(full_lidar) / lidar_speed
        ttc_tight_front = ttc[-aperture_tight_front:].tolist() + ttc[:aperture_tight_front + 1].tolist()

        if np.quantile(ttc_tight_front,q=0.3) < self.aeb_ttc_threshold or np.quantile(lidar_tight_front,q=0.4) < self.aeb_lidar_threshold :
            speedCommand = self.aeb_retro_speed
            steeringCommand = -self.controller.max_steering_angle * direction


        ## Oscillating AEB is a problem, here we do AEB for at lest x simulation step (will need to do that timing wise)
        buffer_aeb_binary_mask = [1 if cmd == self.aeb_retro_speed else 0 for cmd in self.controller.speedCommand_buffer]
        if sum(buffer_aeb_binary_mask[-19:]) > 0 and buffer_aeb_binary_mask[-20] == 0 and buffer_aeb_binary_mask[-1]==1:
            speedCommand = self.aeb_retro_speed
            steeringCommand = -self.controller.max_steering_angle * direction

        return speedCommand, steeringCommand

    def activate(self):
        self.status = "on"

    def desactivate(self):
        self.status = "off"

    def get_status(self):
        return self.status
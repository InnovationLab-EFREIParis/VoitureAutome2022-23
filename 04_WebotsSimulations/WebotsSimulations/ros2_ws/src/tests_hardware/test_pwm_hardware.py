from rpi_hardware_pwm import HardwarePWM
import time

angle_gauche = 6.5
angle_droite = 8.5
angle_centre= 7.5

pwm_prop = HardwarePWM(pwm_channel=0, hz=50)
pwm_dir = HardwarePWM(pwm_channel=1, hz=50)
pwm_prop.start(7.5)
pwm_dir.start(angle_centre)

time.sleep(1)
pwm_prop.change_duty_cycle(7.8)
pwm_dir.change_duty_cycle(angle_droite)

time.sleep(2)
pwm_prop.change_duty_cycle(8.2)
pwm_dir.change_duty_cycle(angle_gauche)

time.sleep(2)
pwm_prop.stop()
pwm_dir.stop()
print("PWM arrêtées")
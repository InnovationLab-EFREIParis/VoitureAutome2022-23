import RPi.GPIO as GPIO
import time

GPIO.setmode(GPIO.BCM)
GPIO.setup(12, GPIO.OUT)

pwm = GPIO.PWM(12, 50)
pwm.start(0)

def set_angle(angle):
    duty_cycle = (angle / 18) + 2
    GPIO.output(12, True)
    pwm.ChangeDutyCycle(duty_cycle)

while True:
    test_angle = int(input("angle: "))
    set_angle(test_angle)

pwm.stop()
GPIO.cleanup()
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
    time.sleep(1)
    GPIO.output(12, False)
    pwm.ChangeDutyCycle(0)

print("marche avant allez la")
time.sleep(1)
for angle in range(90, 0, -1):
    set_angle(angle)
    if angle == 70:
        set_angle(45)
        time.sleep(1)
    time.sleep(0.1)

print("Stop")
set_angle(90)
time.sleep(4)

print("marche arriere sa mere allez la")
time.sleep(1)
for angle in range(90, 180, 1):
    set_angle(angle)
    if angle == 110:
        set_angle(135)
        time.sleep(1)
    time.sleep(0.1)

pwm.stop()
GPIO.cleanup()

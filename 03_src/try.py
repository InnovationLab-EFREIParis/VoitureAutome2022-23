import RPi.GPIO as GPIO
import time

'''
this code is not fully fuctionnal and its main purpose is to show the common instructions 
that might be used during this project
'''

GPIO.setmode(GPIO.BCM) '''
we we et the board to use the low level pins names
'''

#in order to generate a PWM we have to choose a specific GPIO pin able to generate PWM

GPIO.setup(12, GPIO.OUT)# here we setup the pin 12 as an output



signal = GPIO.PWM(12, 1000) #we create a PWM signal object aby giving it the pin name and its frequency



signal.start(10) #at the begining we start our pwm signal

signal.ChangeDutyCycle(75) #if we want to change our PWM duty cycle during while it's running

signal.stop()#if we want to kill the pwm signal on that pin


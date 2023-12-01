#!/usr/bin/env python3
#-- coding: utf-8 --
import RPi.GPIO as GPIO
import time


#Set function to calculate percent from angle
def angle_to_percent (angle) :
    if angle > 180 or angle < 0 :
        return False

    start = 2.5
    end = 12.5
    ratio = (end - start)/180 #Calcul ratio from angle to percent

    angle_as_percent = angle * ratio

    return start + angle_as_percent


GPIO.setmode(GPIO.BCM) #Use Board numerotation mode
GPIO.setwarnings(False) #Disable warnings

#Use pin 12 for PWM signal
pwm_gpio = 12
frequence = 50
GPIO.setup(pwm_gpio, GPIO.OUT)
pwm = GPIO.PWM(pwm_gpio, frequence)
skip = 0.5
while True :
            
      # milieu
      pwm.start(angle_to_percent(30))
      time.sleep(skip)
      #droite
      pwm.ChangeDutyCycle(angle_to_percent(60))
      time.sleep(skip)
      
      pwm.start(angle_to_percent(30))
      time.sleep(skip)
      #gauche
      pwm.ChangeDutyCycle(angle_to_percent(0))
      time.sleep(skip)

#Close GPIO & cleanup
pwm.stop()
GPIO.cleanup()

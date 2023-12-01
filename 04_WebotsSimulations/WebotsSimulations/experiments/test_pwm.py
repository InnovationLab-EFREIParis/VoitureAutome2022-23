import lgpio
import time



PIN_ID = 12

FREQ = 50


h = lgpio.gpiochip_open(0)

try:
    lgpio.tx_pwm(h,PIN_ID,FREQ,0)
    time.sleep(10)
    	
    lgpio.tx_pwm(h,PIN_ID,FREQ,7.5)
    time.sleep(10)

    lgpio.tx_pwm(h,PIN_ID,FREQ,9)
    time.sleep(10)

    lgpio.tx_pwm(h,PIN_ID,FREQ,7)
    time.sleep(10)

except:
    lgpio.tx_pwm(h,PIN_ID,FREQ,50)
    lgpio.gpiochip_close(h)


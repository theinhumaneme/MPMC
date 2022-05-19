# MOTION DETECTION AND LIGHT CONTROL

import RPi.GPIO as GPIO
from datetime import datetime
from time import sleep
# Set RaspberryPi to BOARD Mode
GPIO.setmode(GPIO.BOARD)

#Disable Warning Prompts
GPIO.setwarnings(False)

# Set IO pins
GPIO.setup(40,OUTPUT) #RELAY / LED
GPIO.setup(35,INPUT) # PIR SENSOR

while True:

    # Read DATA from PIRSensor
    movement = GPIO.input(35)

    # If No Motion Detected TurnOff LED/LIGHTS else TurnOn
    if (a == 0):
        GPIO.output(40,False)
    else:
        GPIO.output(40,True)
    time.sleep(0.5)
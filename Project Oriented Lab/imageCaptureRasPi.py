# EYEBLINK DETECTION AND CAPTURE IMAGE

import RPi.GPIO as GPIO
from picamera import PiCamera
from datetime import datetime
from time import sleep
# Set RaspberryPi to BOARD Mode
GPIO.setmode(GPIO.BOARD)

#Disable Warning Prompts
GPIO.setwarnings(False)

# Set IO pins
GPIO.setup(40,OUTPUT)
GPIO.setup(35,INPUT)

while True:

    # Read DATA from EyeBlinkSensor
    movement = GPIO.input(35)
    if (a == 0):

        #Create a generic filename
        filename = datetime.now().strftime("%Y %m %d_%H %M %S")

        #Attach JPEG file extension !! IMPORTANT
        camera.capture(f"./{filename}.jpg")

        #Attach MP4 file extension !! IMPORTANT

        #Record VIDEO for {{sleep}} time
        camera.start_recording(f"./{filename}.mp4")
        sleep(10)
        camera.stop_recording()
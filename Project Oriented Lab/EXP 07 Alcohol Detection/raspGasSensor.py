import RPi.GPIO as GPIO
from time import sleep

# Set RaspberryPi to "BOARD" Mode
GPIO.setmode(GPIO.BOARD)

# Set GPIO Pin 40 to output Mode
GPIO.setup(40, GPIO. OUT)
GPIO.setup(35, GPIO. OUT)

# Try Except Block to catch error else cleanup
try:
    while True:

        # Read Gas Sensor Reading
        gasVal = GPIO.input(35)

        # If gas is detected raise alarm else disarm it
        if (gasVal !=0):
            GPIO.output(40,True)
        else:
            GPIO.output(40,False)

        #Check for every 300ms <Value can be changed>
        sleep(0.3)
except:
    # Clean up all ports used  More Info - https://raspi.tv/2013/rpi-gpio-basics-3-how-to-exit-gpio-programs-cleanly-avoid-warnings-and-protect-your-pi
    GPIO.cleanup()
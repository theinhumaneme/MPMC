import RPi.GPIO as GPIO
from time import sleep

# Set RaspberryPi to "BOARD" Mode
GPIO.setmode(GPIO.BOARD)

# Set GPIO Pin 40 to output Mode
GPIO.setup(40, GPIO. OUT)
GPIO.setup(38, GPIO. OUT)

# Try Except Block to catch error else cleanup
try:
    while True:
        # Set GPIO pins to HIGH / True state
        GPIO.output(40, True)
        GPIO.output(38, True)

        # wait for 500ms
        sleep(0.5)
        # Set GPIO pins to HIGH / True state
        GPIO.output(40, False)
        GPIO.output(38, False)
        sleep(0.5)
except:
    # Clean up all ports used  More Info - https://raspi.tv/2013/rpi-gpio-basics-3-how-to-exit-gpio-programs-cleanly-avoid-warnings-and-protect-your-pi
    GPIO.cleanup()
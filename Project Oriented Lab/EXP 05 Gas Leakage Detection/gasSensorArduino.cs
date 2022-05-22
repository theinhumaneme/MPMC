// C++ code
//

// Arduino Experiment to interface MQ Series Gas sensor
#include <Servo.h>
// Initialize Servo <Window>
Servo window;
void setup()
{
 // Attach the Servo to pin 7
  window.attach(7);
  // Buzzer
  pinMode(2, OUTPUT);
  // MQ-Series Gas sensor
  pinMode(A0,INPUT);
  //Set baud rate
  Serial.begin(9600);
  // Set Servo to Position 0
  window.write(0); // --> Servo max value  -> [0 180]
}

void loop()
{
  // Read values from the Gas Sensor
  int i = analogRead(A0)
  Serial.println(i);
  // Gas sensor threshold to open windows
  // --> Change as per highest reading from sensor
``// --> Or as per required
  if (i >300){
    // Open Windows and trigger buzzer
    window.write(180);
  	digitalWrite(2,HIGH);
    delay(2000);
  }
  else{
    // close Windows and stop buzzer
    window.write(0);
   digitalWrite(2,LOW);
   delay(2000);
  }
}
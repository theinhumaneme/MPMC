#include "DHT.h"
#define DHTPIN 2
#define DHTTYPE DHT11

void setup(){
    pinMode(A0,INPUT);
    Serial.begin(9600);
    dht.begin();
}
void loop(){
    delay(2000);
    int a = analogRead(A0);
    Serial.println(a)

    // Read Values from DHT Sensor
    float humidity = dht.readHumidity();
    float temprature = dht.readTemprature();
    Serial.println(temprature);
    Serial.println(humidity);
    delay(2000)
}
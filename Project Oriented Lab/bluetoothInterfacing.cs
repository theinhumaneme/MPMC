void setup(){
    pinMode(7,OUTPUT);
    pinMode(8,OUTPUT);
    Serial.begin(9600);
    // pinMode(0,OUTPUT);
    // pinMode(1,INPUT);
}
void loop(){
    if (Serial.available() !=0){
        char command = Serial.read();
        if (char == '0'){
            Serial.println('OFF Command Received');
            digitalWrite(7,LOW);

        }
        else if (char == '1'){
            Serial.println('ON Command Received');
            digitalWrite(7,HIGH);
        }
    }
    else{
        Serial.println("BT is unAvailable");
    }
}
#include <ArduinoJson.h>
#include <Servo.h>

Servo ESC;
Servo servo;
bool _backward = true;

void setup() {
  Serial.begin(115200);
  ESC.attach(9,1000,2000);
  servo.attach(10); 
  pinMode(LED_BUILTIN, OUTPUT);
  sped(90);
  steer(45);
}

void loop() {
  if (Serial.available() > 0) {
    
    String message = Serial.readStringUntil('\n');

    // Convertir les bytes en JSON
    StaticJsonDocument<200> doc;
    DeserializationError error = deserializeJson(doc, message);

    if (error) {
      Serial.print("Erreur de parsing JSON : ");
      Serial.println(error.c_str());
    } else {
      steer(doc["servoSteer"]);
      sped(doc["motorSpeed"]);
    }
  }
}


void backward(int command) {
  ESC.write(command);
  delay(50);
  ESC.write(90);
  delay(50);
  ESC.write(command);
}

void sped(int command) {
  if(command >= 90) {
    if(command <= 100 and command > 90) {
      ESC.write(100);
    }
    else {
      ESC.write(command);
    }
    _backward = false;
  }
  else if(_backward == false) {
    backward(command);
    _backward = true;
  }
}

void steer(int command) {
  servo.write(command);
}

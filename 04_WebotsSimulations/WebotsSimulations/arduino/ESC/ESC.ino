#include <Servo.h>

Servo ESC;     // create servo object to control the ESC
int inputValue;

void setup() {
  // Attach the ESC on pin 9
  ESC.attach(9,1000,2000); // (pin, min pulse width, max pulse width in microseconds) 
  Serial.begin(9600);
}

void loop() {
  while (Serial.available() == 0) {} // Attendre que l'utilisateur entre une valeur
  inputValue = Serial.parseInt();
  Serial.parseInt();
  Serial.println(inputValue);
  ESC.write(inputValue);    // Send the signal to the ESC
  delay(2000);
  ESC.write(78);
  delay(100);
  ESC.write(90);
  delay(100);
  ESC.write(78);
  delay(1500);
  ESC.write(90);
}

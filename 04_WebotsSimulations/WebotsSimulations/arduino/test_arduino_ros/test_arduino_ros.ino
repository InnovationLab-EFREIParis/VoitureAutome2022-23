#include <ArduinoJson.h>

void setup() {
  Serial.begin(9600);
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
      // Extraire une valeur spécifique du JSON
      int value = doc["valeur"];

      Serial.print("La valeur extraite est : ");
      Serial.println(value);
    }
  }
}

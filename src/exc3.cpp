#include <Arduino.h>

#define LIGHT_SENSOR_PIN 33
#define LED_PIN 2

void setup() {
  Serial.begin(115200);
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  int rawValue = analogRead(LIGHT_SENSOR_PIN);

  Serial.print("raw=");
  Serial.println(rawValue);

  if (rawValue < 2000) {
    digitalWrite(LED_PIN, HIGH);
  } else {
    digitalWrite(LED_PIN, LOW);
  }

  delay(500);
}
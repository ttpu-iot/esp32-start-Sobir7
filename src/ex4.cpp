#include <Arduino.h>

#define LIGHT_SENSOR_PIN 33

#define LED_BLUE   14
#define LED_GREEN  27
#define LED_YELLOW 12
#define LED_RED    26

void setup() {
  Serial.begin(115200);

  pinMode(LED_BLUE, OUTPUT);
  pinMode(LED_GREEN, OUTPUT);
  pinMode(LED_YELLOW, OUTPUT);
  pinMode(LED_RED, OUTPUT);
  pinMode(LIGHT_SENSOR_PIN, INPUT);
}

void loop() {
  int value = analogRead(LIGHT_SENSOR_PIN);

  // Hammasini o‘chirib turamiz (faqat bittasi yonadi)


  if (value <= 1023) {
    digitalWrite(LED_BLUE, HIGH);
    digitalWrite(LED_GREEN, LOW);
    digitalWrite(LED_YELLOW, LOW);
    digitalWrite(LED_RED, LOW);
    Serial.println("band=BLUE");
  }
  else if (value <= 2047) {
    digitalWrite(LED_BLUE, LOW);
    digitalWrite(LED_GREEN, HIGH);
    digitalWrite(LED_YELLOW, LOW);
    digitalWrite(LED_RED, LOW);
    Serial.println("band=GREEN");
  }
  else if (value <= 3071) {
    digitalWrite(LED_BLUE, LOW);
    digitalWrite(LED_GREEN, LOW);
    digitalWrite(LED_YELLOW, HIGH);
    digitalWrite(LED_RED, LOW);
    Serial.println("band=YELLOW");
  }
  else {
    digitalWrite(LED_BLUE, LOW);
    digitalWrite(LED_GREEN, LOW);
    digitalWrite(LED_YELLOW, LOW);
    digitalWrite(LED_RED, HIGH);
    Serial.println("band=RED");
  }

  delay(500);
}
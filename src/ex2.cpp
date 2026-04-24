#include "Arduino.h"

#define BUTTON_PIN    25
#define GREEN_LED_PIN 27

bool greenState = false;     // LED state
bool lastButtonState = HIGH; // for detecting press

void setup(void) 
{
    pinMode(GREEN_LED_PIN, OUTPUT);
    pinMode(BUTTON_PIN, INPUT); // button to GND
    Serial.begin(115200);
}

void loop(void) 
{
    bool currentButtonState = digitalRead(BUTTON_PIN);

    // Detect button press (HIGH -> LOW)
    if (lastButtonState == HIGH && currentButtonState == LOW )

    {
        greenState = !greenState; // toggle LED

        digitalWrite(GREEN_LED_PIN, greenState);

        // Print ONLY when state changes
      
            Serial.println("GREEN=");
            Serial.println("greenState");

        delay(500); // simple debounce
    }

    lastButtonState = currentButtonState;
}
#include "Arduino.h"

#define BLUE_LED_PIN 14

void setup(void)
{
    pinMode(BLUE_LED_PIN, OUTPUT);   // Blue LED as output

    Serial.begin(115200);            // Start serial
}

void loop(void)
{
    if (Serial.available() > 0)      // Check if data received
    {
        char cmd = Serial.read();    // Read one character

        if (cmd == 'B')
        {
            digitalWrite(BLUE_LED_PIN, HIGH);
            Serial.println("BLUE=1");
        }
        else if (cmd == 'b')
        {
            digitalWrite(BLUE_LED_PIN, LOW);
            Serial.println("BLUE=0");
        }
    }
}
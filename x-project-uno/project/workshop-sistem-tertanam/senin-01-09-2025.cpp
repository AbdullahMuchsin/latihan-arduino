
//  a. PWM 1
#include <Arduino.h>

int pinLed = 5;

void setup()
{
    pinMode(pinLed, OUTPUT);
}

void loop()
{
    analogWrite(pinLed, 255);
    delay(200);
    analogWrite(pinLed, 128);
    delay(200);
    analogWrite(pinLed, 0);
    delay(200);
}

// b. PWM 2

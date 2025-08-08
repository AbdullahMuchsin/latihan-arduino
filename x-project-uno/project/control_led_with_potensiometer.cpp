#include <Arduino.h>

int resultPot = 0;

#define pinPot A0

void setup()
{
    Serial.begin(9600);
    pinMode(3, OUTPUT);
    pinMode(pinPot, INPUT);
}

void loop()
{
    resultPot = analogRead(pinPot);
    resultPot = map(resultPot, 0, 1023, 0, 255);
    Serial.println(resultPot);
    analogWrite(3, resultPot);

    delay(100);
}
#include <Arduino.h>

const int led[3] = {7, 6, 5};

void setup()
{
    for (int i = 0; i < 3; i++)
    {
        pinMode(led[i], OUTPUT);
    }
}

void loop()
{
    for (int i = 0; i < 2; i++)
    {
        digitalWrite(led[i], HIGH);
        delay(200);
        digitalWrite(led[i], LOW);
        delay(200);
    }
    for (int i = 2; i > 0; i--)
    {
        digitalWrite(led[i], HIGH);
        delay(200);
        digitalWrite(led[i], LOW);
        delay(200);
    }
}
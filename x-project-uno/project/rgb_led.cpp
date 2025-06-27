#include <Arduino.h>

const int red = 6;
const int green = 5;
const int blue = 3;

void changeColor(int fillRed, int fillGreen, int fillBlue)
{
    digitalWrite(red, fillRed);
    digitalWrite(green, fillGreen);
    digitalWrite(blue, fillBlue);
}

void setup()
{
    pinMode(red, OUTPUT);
    pinMode(green, OUTPUT);
    pinMode(blue, OUTPUT);
}

void loop()
{
    changeColor(255, 0, 0);
    delay(1000);
    changeColor(0, 255, 0);
    delay(1000);
    changeColor(0, 0, 255);
    delay(1000);
    changeColor(46, 200, 229);
    delay(1000);
    changeColor(255, 0, 247);
    delay(1000);
}

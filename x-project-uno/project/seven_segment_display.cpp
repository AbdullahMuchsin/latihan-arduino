#include <Arduino.h>
//                        a  b  c  d  e  f  g  dp
int pinSevenSegment[8] = {2, 3, 4, 5, 6, 7, 8, 9};

bool digit[10][7] = {
    {0, 0, 0, 0, 0, 0, 1}, // 0
    {1, 0, 0, 1, 1, 1, 1}, // 1
    {0, 0, 1, 0, 0, 1, 0}, // 2
    {0, 0, 0, 0, 1, 1, 0}, // 3
    {1, 0, 0, 1, 1, 0, 0}, // 4
    {0, 1, 0, 0, 1, 0, 0}, // 5
    {0, 1, 0, 0, 0, 0, 0}, // 6
    {0, 0, 0, 1, 1, 1, 1}, // 7
    {0, 0, 0, 0, 0, 0, 0}, // 8
    {0, 0, 0, 0, 1, 0, 0}  // 9
};

void setDisplay(int angka)
{
    for (int i = 0; i <= 6; i++)
    {
        digitalWrite(pinSevenSegment[i], digit[angka][i]);
    }
}

void setup()
{
    for (int i = 0; i <= 7; i++)
    {
        pinMode(pinSevenSegment[i], OUTPUT);
    }

    for (int i = 0; i <= 7; i++)
    {
        digitalWrite(pinSevenSegment[i], HIGH);
    }
}

void loop()
{
    setDisplay(0);
    delay(1000);
    setDisplay(1);
    delay(1000);
    setDisplay(2);
    delay(1000);
    setDisplay(3);
    delay(1000);
    setDisplay(4);
    delay(1000);
    setDisplay(5);
    delay(1000);
    setDisplay(6);
    delay(1000);
    setDisplay(7);
    delay(1000);
    setDisplay(8);
    delay(1000);
    setDisplay(9);
    delay(1000);
}
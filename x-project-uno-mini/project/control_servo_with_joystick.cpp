#include <Arduino.h>
#include <Servo.h>

Servo servo1, servo2;
const int x = A0, y = A1, sw = 5;
const int pinServo1 = 6, pinServo2 = 7;
int nilaiX, nilaiY, nilaiSW;

void setup()
{
    Serial.begin(9600);
    servo1.attach(pinServo1);
    servo2.attach(pinServo2);
    servo1.write(0);
    servo2.write(0);
    pinMode(sw, INPUT_PULLUP);
    pinMode(x, INPUT);
    pinMode(y, INPUT);
}

void loop()
{
    nilaiX = map(analogRead(x), 0, 1023, 0, 180);
    nilaiY = map(analogRead(y), 0, 1023, 0, 180);
    nilaiSW =  digitalRead(sw);

    servo1.write(nilaiX);
    servo2.write(nilaiY);

    Serial.println(nilaiSW);
}

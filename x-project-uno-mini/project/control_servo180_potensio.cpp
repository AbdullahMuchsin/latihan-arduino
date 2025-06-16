#include <Arduino.h>
#include <Servo.h>

Servo servo;

#define PIN_SERVO 5
int sudut;

const int pot = A0;
int hasilPot;

void setup()
{
    pinMode(pot, INPUT);
    servo.attach(PIN_SERVO);
    Serial.begin(9600);
}

void loop()
{
    hasilPot = analogRead(pot);
    sudut = map(hasilPot, 0, 1023, 180, 0);
    servo.write(sudut);

    Serial.println("Hasil Potensio : " + String(hasilPot) + " | Hasil Sudut : " + String(sudut));
}
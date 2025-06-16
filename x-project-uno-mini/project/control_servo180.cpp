#include <Arduino.h>
#include <Servo.h>

const int tombol1 = 5;
const int tombol2 = 6;

Servo servo;
int sudut = 0;

boolean statusTombol1 = false;
boolean statusTombol2 = false;

void setup()
{
    pinMode(tombol1, INPUT_PULLUP);
    pinMode(tombol2, INPUT_PULLUP);

    servo.attach(7);

    Serial.begin(9600);
}

void loop()
{
    statusTombol1 = digitalRead(tombol1);
    statusTombol2 = digitalRead(tombol2);

    if(statusTombol1 == HIGH && sudut < 180) {
        sudut++;
        servo.write(sudut);
    } else if (statusTombol2 == HIGH && sudut > 0) {
        sudut--;
        servo.write(sudut);
    }
    Serial.println(sudut);

}
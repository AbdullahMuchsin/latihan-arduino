#include <Arduino.h>
#include <Servo.h>

Servo myServo;
int servoPin = 9;

void setup()
{
    Serial.begin(9600);       // Aktifkan Serial Monitor
    myServo.attach(servoPin); // Hubungkan servo ke pin 9
    Serial.println("Servo Test Dimulai");
}

void loop()
{
    // Maju dari 0 ke 180
    for (int angle = 0; angle <= 180; angle++)
    {
        myServo.write(angle);
        Serial.print("Sudut: ");
        Serial.println(angle);
        delay(15); // waktu tunggu agar servo bisa bergerak
    }

    delay(500); // jeda sebentar di 180

    // Balik dari 180 ke 0
    for (int angle = 180; angle >= 0; angle--)
    {
        myServo.write(angle);
        Serial.print("Sudut: ");
        Serial.println(angle);
        delay(15);
    }

    delay(500); // jeda di posisi 0
}

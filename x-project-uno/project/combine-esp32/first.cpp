#include <Arduino.h>
#include <SoftwareSerial.h>

// Deklarasi Pin Sensor
int pinA0 = A0;
SoftwareSerial hujan(2, 3); // RX TX

int resultSensorHujan = 0;

void setup()
{
    Serial.begin(9600);
    hujan.begin(9600);
    pinMode(pinA0, INPUT);
}

void loop()
{
    resultSensorHujan = analogRead(pinA0);
    Serial.println(resultSensorHujan);
    hujan.println(resultSensorHujan);
    delay(1000);
}
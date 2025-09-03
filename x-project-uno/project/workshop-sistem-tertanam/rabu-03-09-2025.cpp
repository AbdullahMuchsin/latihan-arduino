#include <Arduino.h>

// Serial Monitor 1
int pinLed = 6;

void setup()
{
    pinMode(pinLed, OUTPUT);
    Serial.begin(9600);
}

void loop()
{
    digitalWrite(pinLed, HIGH);
    Serial.println("LED MENYALA");
    delay(100);
    digitalWrite(pinLed, LOW);
    Serial.println("LED PADAM");
    delay(100);
}

// Serial Monitor 2
int pinLed = 6;

void setup()
{
    pinMode(pinLed, OUTPUT);
    Serial.begin(9600);
    Serial.println("Masukkan 1 --> nyala atau 2 --> padam");
}

void loop()
{
    if (Serial.available())
    {
        int kondisi = Serial.parseInt();

        if (kondisi == 1)
        {
            digitalWrite(pinLed, HIGH);
            Serial.println("LED MENYALA");
        }

        if (kondisi == 2)
        {
            digitalWrite(pinLed, LOW);
            Serial.println("LED LOW");
        }
    }
}

//
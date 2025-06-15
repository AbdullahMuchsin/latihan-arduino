#include <Arduino.h>

const int ledKuning = 8;
const int ledHijau = 7;
const int ledMerah = 6;

const int tombol1 = 2;
const int tombol2 = 3;

int statusTombol1 = 0;
boolean statusLedKuning = false;

void setup()
{
   pinMode(ledKuning, OUTPUT);
   pinMode(ledHijau, OUTPUT);
   pinMode(ledMerah, OUTPUT);

   pinMode(tombol1, INPUT);
   pinMode(tombol2, INPUT);
}

void loop()
{
    statusTombol1 = digitalRead(tombol1);

    if(statusTombol1 == HIGH) {
        statusLedKuning = !statusLedKuning;
    }

    digitalWrite(ledKuning, statusLedKuning);
}
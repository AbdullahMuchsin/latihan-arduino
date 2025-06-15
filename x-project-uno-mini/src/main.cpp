#include <Arduino.h>

const int ledKuning = 8;
const int ledHijau = 7;
const int ledMerah = 6;

const int tombol1 = 2;
const int tombol2 = 3;

int statusTombol1 = 0;
int statusTombol2 = 0;
boolean statusLedKuning = true;
boolean statusLedHijau = true;
boolean statusLedMerah = true;

void setup()
{
   pinMode(ledKuning, OUTPUT);
   pinMode(ledHijau, OUTPUT);
   pinMode(ledMerah, OUTPUT);

   pinMode(tombol1, INPUT_PULLUP);
   pinMode(tombol2, INPUT);

   Serial.begin(9600);
}

void loop()
{
    statusTombol1 = digitalRead(tombol1);
    statusTombol2 = digitalRead(tombol2);
    Serial.println("----------------");
    Serial.println(statusTombol1);
    Serial.println(statusTombol2);
    Serial.println("----------------");

    if(statusTombol1 == LOW && statusTombol2 == LOW) {
        digitalWrite(ledHijau, HIGH);
        digitalWrite(ledKuning, HIGH);
        digitalWrite(ledMerah, HIGH);
    } else if (statusTombol1 == HIGH && statusTombol2 == LOW) {
        digitalWrite(ledHijau, LOW);
        digitalWrite(ledKuning, HIGH);
        digitalWrite(ledMerah, HIGH);
    } else if (statusTombol1 == LOW && statusTombol2 == HIGH) {
        digitalWrite(ledHijau, HIGH);
        digitalWrite(ledKuning, LOW);
        digitalWrite(ledMerah, HIGH);
    } else if (statusTombol1 == HIGH && statusTombol2 == HIGH) {
        digitalWrite(ledHijau, HIGH);
        digitalWrite(ledKuning, HIGH);
        digitalWrite(ledMerah, LOW);
    }

    delay(100);
}
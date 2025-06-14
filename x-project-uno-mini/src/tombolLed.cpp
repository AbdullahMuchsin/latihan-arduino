#include <Arduino.h>

const int led = 5;
const int tombol = 2;

int statusTombol = 0;
boolean statusLed = false;

void setup()
{
  pinMode(led, OUTPUT);
  pinMode(tombol, INPUT);
}

void loop()
{
  statusTombol = digitalRead(tombol);

  if (statusTombol == HIGH)
  {
    statusLed = !statusLed;
  }

  digitalWrite(led, statusLed);
  delay(100);
}
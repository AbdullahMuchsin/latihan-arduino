#include <Arduino.h>
#include <TimerOne.h>

int const ledKuning = 2;
int const ledHijua = 6;
int const button = 5;

void blinkKuning()
{
  if (digitalRead(button) == HIGH)
  {
    digitalWrite(ledKuning, HIGH);
  }
  else
  {
    digitalWrite(ledKuning, LOW);
  }
}

void setup()
{
  pinMode(ledHijua, OUTPUT);
  pinMode(ledKuning, OUTPUT);
  pinMode(button, INPUT);

  Timer1.initialize(1000);
  Timer1.attachInterrupt(blinkKuning);

  Serial.begin(9600);
}

void loop()
{
  for (int i = 0; i < 5; i++)
  {
    digitalWrite(ledHijua, HIGH);
    delay(1000);
    digitalWrite(ledHijua, LOW);
    delay(1000);
  }

  Serial.println("AMAN");
}
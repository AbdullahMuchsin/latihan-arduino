#include <Arduino.h>

const int pinSuara = A1;

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  int hasil = analogRead(pinSuara);
  
  Serial.print("Nilai Suara : ");
  Serial.println(hasil);
  delay(200);
}
#include <Servo.h>

int pinPotensio = A0;
int nilaiDerajat = 0;
Servo servo;

void setup() {
  Serial.begin(9600);
  servo.attach(8);
  pinMode(pinPotensio, INPUT);
}

void loop() {
  int nilaiPotensio = analogRead(pinPotensio);
  nilaiDerajat = map(nilaiPotensio, 0, 1023, 0, 180);
  Serial.println(nilaiPotensio);
  Serial.println(nilaiDerajat);
  servo.write(nilaiDerajat);
}

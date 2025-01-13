#include <NewPing.h>

NewPing sensor(8,9,30);

const int pinLed = 7;
const int pinBuz = 6;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(pinLed, OUTPUT);
  pinMode(pinBuz, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int nilaiSensor = sensor.ping_cm();
  Serial.println(nilaiSensor);

  if(nilaiSensor <= 10 && nilaiSensor != 0) {
    digitalWrite(pinLed, HIGH);
    delay(50);
    digitalWrite(pinLed, LOW);
    delay(50);
  } else {
    digitalWrite(pinLed, HIGH);
    digitalWrite(pinBuz, HIGH);
    delay(1000);
    digitalWrite(pinLed, LOW);
    digitalWrite(pinBuz, LOW);
    delay(1000);
  }
}

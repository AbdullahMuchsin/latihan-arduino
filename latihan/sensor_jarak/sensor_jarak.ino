#include <NewPing.h>

NewPing sensor(8,9,30);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int nilaiSensor = sensor.ping_cm();

  Serial.println(nilaiSensor);
}

int pinLed1 = 10;
int pinLed2 = 9;
int pinLed3 = 8;

void setup() {
  // put your setup code here, to run once:
  pinMode(pinLed1, OUTPUT);
  pinMode(pinLed2, OUTPUT);
  pinMode(pinLed3, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(pinLed1, HIGH);
  digitalWrite(pinLed2, LOW);
  digitalWrite(pinLed3, LOW);
  delay(3000);
  digitalWrite(pinLed1, LOW);
  digitalWrite(pinLed2, HIGH);
  digitalWrite(pinLed3, LOW);
  delay(500);
  digitalWrite(pinLed1, LOW);
  digitalWrite(pinLed2, LOW);
  digitalWrite(pinLed3, HIGH);
  delay(3000);
}

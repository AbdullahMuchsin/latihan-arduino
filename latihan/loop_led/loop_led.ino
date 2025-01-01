
int pinLed1 = 8;
int pinLed2 = 9;
int pinLed3 = 10;

int buttonR = 11;

void setup() {
  // put your setup code here, to run once:
  pinMode(pinLed1, OUTPUT);
  pinMode(pinLed2, OUTPUT);
  pinMode(pinLed3, OUTPUT);
  pinMode(buttonR, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(digitalRead(buttonR));
  for(int i = 0; i < 3; i++) {
    Serial.println(i);
    for(int j = 1000; j > 100; j--) {
      if(i == 0) {
        digitalWrite(pinLed1, HIGH);
        digitalWrite(pinLed2, LOW);
        digitalWrite(pinLed3, LOW);
      } else if(i == 1) {
        digitalWrite(pinLed1, LOW);
        digitalWrite(pinLed2, HIGH);
        digitalWrite(pinLed3, LOW);
      } else {
        digitalWrite(pinLed1, LOW);
        digitalWrite(pinLed2, LOW);
        digitalWrite(pinLed3, HIGH);
      }
      delay(j);
      if(i == 0) {
        digitalWrite(pinLed1, LOW);
      } else if(i == 1) {
        digitalWrite(pinLed2, LOW);
      } else {
        digitalWrite(pinLed3, LOW);
      }
      delay(j);

      j -= 50;
    }
  }
}

const int pinButton = 4;

void setup() {
  // put your setup code here, to run once:
  pinMode(pinButton, INPUT_PULLUP);
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  int buttonState = digitalRead(pinButton);

  if(buttonState == LOW){
    Serial.println("Button Ditekan");
  } else {
    Serial.println("Button Dilepas");
  }

  delay(500);
}

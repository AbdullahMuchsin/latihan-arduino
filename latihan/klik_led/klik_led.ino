const int pinLed = 8;
const int buttonPin = 7;  
int buttonState = 0;     

bool statusLed = false;

void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(pinLed, OUTPUT);
  
  Serial.begin(9600);
}

void loop() {
  buttonState = digitalRead(buttonPin);
  
  if (buttonState == HIGH) {
    Serial.println("Button pressed!");
    statusLed = !statusLed;
  } else {
    Serial.println("Button not pressed.");
  }

  digitalWrite(pinLed, statusLed);

  delay(200);
}

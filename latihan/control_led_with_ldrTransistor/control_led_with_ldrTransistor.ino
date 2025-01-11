int pinLdr = A0;
int pinLed = 8;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(pinLdr, INPUT);
  pinMode(pinLed, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int nilaiLdr = analogRead(pinLdr);
  Serial.println(nilaiLdr);

  if(nilaiLdr > 5) {
    digitalWrite(pinLed, LOW);
  } else {
    digitalWrite(pinLed, HIGH);
  }
}

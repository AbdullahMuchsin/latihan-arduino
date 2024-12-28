
const int pinLed = 13;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(pinLed, OUTPUT);
  Serial.println("Arduino siap dimulai");
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(pinLed, HIGH);
  Serial.println("Lampu led menyala");
  delay(1000);

  digitalWrite(pinLed, LOW);
  Serial.println("Lampu led mati");
  delay(1000);
}

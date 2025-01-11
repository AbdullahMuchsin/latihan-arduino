const int pinSS = 7;
const int pinLed = 6;

bool statusLed = false;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  pinMode(pinSS, INPUT);
  pinMode(pinLed, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int nilaiSuara = digitalRead(pinSS);
  Serial.println(nilaiSuara);

  if(nilaiSuara == 1) {
    statusLed = !statusLed;
  }

  digitalWrite(pinLed, statusLed);
}

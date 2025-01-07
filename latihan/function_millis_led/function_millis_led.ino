
unsigned long interval = 1000;
unsigned long nilaiAwal1 = 0;
unsigned long nilaiAwal2 = 0;

int pinLed1 = 8;
int pinLed2 = 9;

int statusLed1 = false;
int statusLed2 = false;

void setup() {
  Serial.begin(9600);
  pinMode(pinLed1, OUTPUT);
  pinMode(pinLed2, OUTPUT);
}

void loop() {
  unsigned long nilaiSekarang = millis();

  if(nilaiSekarang - nilaiAwal1 >= interval) {
    statusLed1 = !statusLed1;
    digitalWrite(pinLed1, statusLed1);
    nilaiAwal1 = nilaiSekarang;
  }

   if(nilaiSekarang - nilaiAwal2 >= (interval / 2)) {
    statusLed2 = !statusLed2;
    digitalWrite(pinLed2, statusLed2);
    nilaiAwal2 = nilaiSekarang;
  }
}

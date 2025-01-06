#include<BluetoothSerial.h>

BluetoothSerial SerialBT;

const int pinLed = 2;

void setup() {

  Serial.begin(115200);
  pinMode(pinLed, OUTPUT);

  if(!SerialBT.begin("Muchsin_Tech")) {
    Serial.println("Gagal terkoneksi");

    while(1);
  }

  Serial.println("Bluetooth siap terkoneksi");

}

void loop() {

  if(SerialBT.available() > 0) {
    char data = SerialBT.read();

    switch(data) {
      case '0' :
        digitalWrite(pinLed, LOW);
        break;
      case '1' :
        digitalWrite(pinLed, HIGH);
        break;
      default : 
        break;
    }
  }

}

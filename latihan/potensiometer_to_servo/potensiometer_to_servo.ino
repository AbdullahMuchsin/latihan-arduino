// Import Servo
#include <Servo.h>

// Inisialisasi Variabel
const int pinS = 7;
const int pon = A0;
int nilai;
int nilaiMap;

Servo servo;

void setup() {
  // Aktifkan Serial Monitor (9600)
  Serial.begin(9600);

  // Pin untuk Potensiometer
  pinMode(pon, INPUT);

  // Pin untuk servo
  servo.attach(pinS);
}

void loop() {

  // Ambil nilai potensiometer
  nilai = analogRead(pon);

  // Ubah batas nilai dari (0 -> 1023) Menjadi (0 -> 180)
  nilaiMap = map(nilai, 0, 1023, 0, 180);

  // Mengatur nilai servo  
  servo.write(nilaiMap);

  // Print nilai ke serial monitor
  Serial.println("Nilai     : " + String(nilai));
  Serial.println("Nilai Map : " + String(nilaiMap));

  delay(100);

}

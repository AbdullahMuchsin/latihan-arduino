#include <Servo.h>
#include <NewPing.h>

// Pin untuk sensor ultrasonik
#define TRIG_PIN 6
#define ECHO_PIN 5
#define MAX_DISTANCE 30 // Jarak maksimum (dalam cm) untuk sensor

// Inisialisasi library NewPing
NewPing sonar(TRIG_PIN, ECHO_PIN, MAX_DISTANCE);

// Pin dan konfigurasi servo
Servo myServo;
const int servoPin = 7;

// Jarak
int distance;
int servoAngle = 0;  // Posisi sudut servo
int step = 5;        // Besar langkah per gerakan

void setup() {
  // Inisialisasi servo
  myServo.attach(servoPin);
  myServo.write(servoAngle); // Mulai dari posisi 0 derajat
  
  // Serial monitor
  Serial.begin(9600);
}

void loop() {
  // Baca jarak menggunakan NewPing
  distance = sonar.ping_cm();

  // Cetak jarak ke serial monitor
  Serial.print("Jarak: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Logika untuk servo
  if (distance > 0 && distance < 15) { // Jika jarak valid dan kurang dari 15 cm
    Serial.println("Servo berhenti");
  } else if (distance >= 15 || distance == 0) { // Jika jarak lebih dari atau sama dengan 15 cm
    // Gerakan servo bolak-balik
    servoAngle += step;  // Tambah sudut servo
    if (servoAngle >= 180 || servoAngle <= 0) {
      step = -step; // Balik arah jika mencapai batas
    }
    myServo.write(servoAngle); // Perbarui posisi servo
    Serial.println("Servo bergerak");
  }

  delay(50); // Waktu tunda untuk gerakan servo yang lebih halus
}

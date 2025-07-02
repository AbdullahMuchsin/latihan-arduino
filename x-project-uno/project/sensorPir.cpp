#include <Arduino.h>

// Sensor PIR pin (kiri (Ground) - Tengah (Out / pin arduino) - kanan (VCC / 5V))

// Definisikan pin untuk sensor PIR
const int pirPin = 2; // Pin digital yang terhubung ke output sensor PIR

// Variabel untuk menyimpan status gerakan
int motionState = 0;

void setup()
{
    // Atur pin PIR sebagai INPUT
    pinMode(pirPin, INPUT);
    // Mulai komunikasi serial untuk melihat output
    Serial.begin(9600);
    Serial.println("Sensor PIR sedang dipantau...");
    Serial.println("---------------------------------");
}

void loop()
{
    // Baca nilai dari sensor PIR
    motionState = digitalRead(pirPin);

    // Jika gerakan terdeteksi (pin PIR HIGH)
    if (motionState == HIGH)
    {
        Serial.println("GERAKAN TERDETEKSI!");
    }
    else
    {
        Serial.println("Tidak ada gerakan.");
    }

    // Tambahkan sedikit delay agar tidak membanjiri Serial Monitor
    // dan memberi waktu bagi sensor untuk 'reset' jika Delay Time diatur pendek.
    delay(200); // Tunggu 0.5 detik
}
#include <WiFi.h>
#include <HTTPClient.h>

// Ganti sesuai jaringan WiFi kamu
const char* ssid = "RumahPojok1";
const char* password = "12312333";

// URL endpoint Laravel API kamu
const char* serverUrl = "http://192.168.18.26:8000/api/moisture"; // Ganti IP ini dengan IP Laravel server kamu

// API key dari tabel `devices` di Laravel
const char* apiKey = "device_123abc";

// Pin analog untuk soil sensor
#define SOIL_SENSOR_PIN 34

// Kalibrasi sensor (ubah sesuai hasil kalibrasi lapangan)
// Penting: Lakukan kalibrasi ini dengan hati-hati untuk mendapatkan akurasi terbaik!
// dryValue: Bacaan analog saat sensor di udara kering (nilai tertinggi)
// wetValue: Bacaan analog saat sensor terendam air atau di tanah sangat basah (nilai terendah)
const int dryValue = 3900; 
const int wetValue = 300; 

void setup() {
  Serial.begin(115200);
  delay(1000);

  Serial.print("Menghubungkan WiFi ke ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWiFi terhubung!");
  Serial.print("Alamat IP: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  // Membaca nilai analog dari sensor
  int sensorValue = analogRead(SOIL_SENSOR_PIN);

  // Menghitung persentase kelembapan
  // Perhitungan ini mengasumsikan:
  // - Nilai analog tinggi = tanah kering
  // - Nilai analog rendah = tanah basah
  // Memetakan nilai sensor dari (dryValue - wetValue) ke (0 - 100)%
  // Jika sensorValue sama dengan dryValue, moisturePercent akan 0% (kering)
  // Jika sensorValue sama dengan wetValue, moisturePercent akan 100% (basah)
  float moisturePercent = map(sensorValue, dryValue, wetValue, 0, 100);

  // Pastikan nilai persentase berada dalam rentang 0-100
  moisturePercent = constrain(moisturePercent, 0, 100);

  Serial.print("Nilai analog: ");
  Serial.print(sensorValue);
  Serial.print(" -> Moisture: ");
  Serial.print(moisturePercent, 1); // Tampilkan dengan 1 angka di belakang koma
  Serial.println(" %");

  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;

    http.begin(serverUrl);
    http.addHeader("Content-Type", "application/json");

    // Format data JSON
    String jsonData = "{\"moisture\":" + String(moisturePercent, 1) +
                      ",\"api_key\":\"" + apiKey + "\"}";

    Serial.print("Mengirim data: ");
    Serial.println(jsonData);

    int httpCode = http.POST(jsonData);
    String response = http.getString();

    Serial.print("HTTP Response code: ");
    Serial.println(httpCode);
    Serial.println("Response: " + response);

    http.end();
  } else {
    Serial.println("WiFi tidak terhubung. Mencoba menghubungkan ulang...");
    WiFi.reconnect(); // Coba hubungkan ulang jika terputus
  }

  delay(30000); // Tunggu 30 detik sebelum kirim ulang
}
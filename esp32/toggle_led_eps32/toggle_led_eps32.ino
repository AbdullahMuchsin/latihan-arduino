#include <WiFi.h>
#include <WebServer.h>

// Konfigurasi WiFi
const char* ssid = "wifi-name";  // Ganti dengan nama WiFi Anda
const char* password = "password-wifi";  // Ganti dengan password WiFi Anda

// Pin untuk LED
const int ledPin = 2;  // LED terhubung ke pin GPIO2

// Objek server
WebServer server(80);

bool aktif = false;

// Fungsi untuk menampilkan halaman web
void handleRoot() {
  String html = R"rawliteral(
  <!DOCTYPE html>
  <html>
  <head>
      <title>Kontrol LED</title>
      <style>
          body {
              font-family: Arial, sans-serif;
              text-align: center;
              margin-top: 50px;
          }
          button {
              padding: 10px 20px;
              font-size: 18px;
              margin: 10px;
              border: none;
              border-radius: 5px;
              cursor: pointer;
          }
          .on {
              background-color: #4CAF50;
              color: white;
          }
      </style>
  </head>
  <body>
      <h1>Kontrol LED ESP32</h1>
      <button class="on" onclick="window.location.href='/'">Klik</button>
  </body>
  </html>
  )rawliteral";

  if(aktif == false) {
    digitalWrite(ledPin, HIGH);
    aktif = true;
  } else {
    digitalWrite(ledPin, LOW);
    aktif = false;
  }

  server.send(200, "text/html", html);
}

void setup() {
  // Inisialisasi serial monitor
  Serial.begin(115200);

  // Inisialisasi LED
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);

  // Koneksi ke WiFi
  Serial.print("Menghubungkan ke WiFi");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }
  Serial.println("\nWiFi terhubung");
  Serial.println(WiFi.localIP());

  // Rute untuk server
  server.on("/", handleRoot);

  // Memulai server
  server.begin();
  Serial.println("Server dimulai");
}

void loop() {
  // Menangani permintaan klien
  server.handleClient();
}

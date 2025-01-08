#include <WiFi.h>
#include <WebServer.h>

// Konfigurasi WiFi
const char* ssid = "RumahPojok1"; // Ganti dengan nama WiFi Anda
const char* password = "12312333"; // Ganti dengan password WiFi Anda

// Konfigurasi pin LED
const int ledPin1 = 12; // GPIO12
const int ledPin2 = 13; // GPIO13

// Status LED
bool led1Status = false;
bool led2Status = false;

// Buat server web pada port 80
WebServer server(80);

// Halaman HTML responsif
String generateHTML() {
  String html = "<!DOCTYPE html><html>";
  html += "<head><title>ESP32 LED Control</title>";
  html += "<meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">";
  html += "<style>";
  html += "body { font-family: Arial, sans-serif; text-align: center; margin: 0; padding: 0; background: #f4f4f9; color: #333; }";
  html += ".container { padding: 20px; }";
  html += ".card { background: #fff; margin: 10px auto; padding: 20px; border-radius: 8px; box-shadow: 0 4px 6px rgba(0, 0, 0, 0.1); max-width: 400px; }";
  html += ".switch { position: relative; display: inline-block; width: 60px; height: 34px; }";
  html += ".switch input { opacity: 0; width: 0; height: 0; }";
  html += ".slider { position: absolute; cursor: pointer; top: 0; left: 0; right: 0; bottom: 0; background-color: #ccc; transition: 0.4s; border-radius: 34px; }";
  html += ".slider:before { position: absolute; content: ''; height: 26px; width: 26px; left: 4px; bottom: 4px; background-color: white; transition: 0.4s; border-radius: 50%; }";
  html += "input:checked + .slider { background-color: #2196F3; }";
  html += "input:checked + .slider:before { transform: translateX(26px); }";
  html += "</style>";
  html += "</head><body>";
  html += "<div class=\"container\">";
  html += "<h1>Kontrol LED ESP32</h1>";

  // Kontrol LED 1
  html += "<div class=\"card\">";
  html += "<p>GPIO12 - LED 1</p>";
  html += "<label class=\"switch\">";
  html += "<input type=\"checkbox\" onchange=\"toggleLED('led1')\" " + String(led1Status ? "checked" : "") + ">";
  html += "<span class=\"slider\"></span>";
  html += "</label>";
  html += "</div>";

  // Kontrol LED 2
  html += "<div class=\"card\">";
  html += "<p>GPIO13 - LED 2</p>";
  html += "<label class=\"switch\">";
  html += "<input type=\"checkbox\" onchange=\"toggleLED('led2')\" " + String(led2Status ? "checked" : "") + ">";
  html += "<span class=\"slider\"></span>";
  html += "</label>";
  html += "</div>";

  html += "</div>";

  // Tambahkan JavaScript
  html += "<script>";
  html += "function toggleLED(led) {";
  html += "  var xhr = new XMLHttpRequest();";
  html += "  xhr.open('GET', '/' + led + 'toggle', true);";
  html += "  xhr.send();";
  html += "}";
  html += "</script>";

  html += "</body></html>";
  return html;
}

// Handler untuk halaman utama
void handleRoot() {
  server.send(200, "text/html", generateHTML());
}

// Fungsi untuk toggle LED 1
void toggleLED1() {
  led1Status = !led1Status;
  digitalWrite(ledPin1, led1Status ? HIGH : LOW);
  server.send(200, "text/html", generateHTML());
}

// Fungsi untuk toggle LED 2
void toggleLED2() {
  led2Status = !led2Status;
  digitalWrite(ledPin2, led2Status ? HIGH : LOW);
  server.send(200, "text/html", generateHTML());
}

void setup() {
  // Konfigurasi pin LED
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);

  // Inisialisasi serial monitor
  Serial.begin(115200);

  // Hubungkan ke WiFi
  Serial.print("Menghubungkan ke WiFi...");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("Terhubung!");
  Serial.print("Alamat IP: ");
  Serial.println(WiFi.localIP());

  // Atur handler untuk endpoint
  server.on("/", handleRoot);
  server.on("/led1toggle", toggleLED1);
  server.on("/led2toggle", toggleLED2);

  // Mulai server
  server.begin();
  Serial.println("Server web dimulai!");
}

void loop() {
  // Tangani permintaan klien
  server.handleClient();
}

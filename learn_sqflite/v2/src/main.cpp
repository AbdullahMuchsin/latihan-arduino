#include <WiFi.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>

const char* ssid = "RumahPojok1";
const char* password = "12312333";

const char* serverUrl = "http://192.168.18.26:8000/api/moisture";

const char* apiKey = "device_123abc";

#define SOIL_SENSOR_PIN 34

const int dryValue = 4095;
const int wetValue = 2243;

void setup() {
  Serial.begin(115200);
  delay(1000);

  Serial.print("Menghungkan Wifi ke ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);

  while(WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.print("\nWifi Terhubung!");
  Serial.print("Alamat IP : ");
  Serial.println(WiFi.localIP());
}

void loop() {
  int sensorValue = analogRead(SOIL_SENSOR_PIN);

  float moisturePercent = map(sensorValue, dryValue, wetValue, 0, 100);

  moisturePercent = constrain(moisturePercent, 0, 100);

  Serial.print("Nilai Analog : ");
  Serial.print(sensorValue);
  Serial.print(" -> Moisture : ");
  Serial.print(moisturePercent, 1);
  Serial.println(" %");

  if(WiFi.status() == WL_CONNECTED) {
    HTTPClient http;

    http.begin(serverUrl);
    http.addHeader("Content-Type", "application/json");
    
    JsonDocument doc;

    doc["moisture"] = moisturePercent;
    doc["api_key"] = apiKey;

    String jsonData;
    serializeJson(doc, jsonData);

    Serial.print("Mengirim data : ");
    Serial.println(jsonData);

    int httpCode = http.POST(jsonData);
    String response = http.getString();

    Serial.print("Http Response Code : ");
    Serial.println(httpCode);
    Serial.println("Response : " + response );

    http.end();
  } else {
    Serial.println("WiFi tidak terhubung. Mencoba menghubungkan ulang...");
    WiFi.reconnect();
  }

  delay(5000);
}






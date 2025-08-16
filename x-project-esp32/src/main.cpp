#include <Arduino.h>
#include <WiFi.h>
#include <SPI.h>
#include <HTTPClient.h>
#include <MFRC522.h>

// SSID & Password WiFi
const char *ssid = "RumahPojok1";
const char *pass = "12312333";

// Host server (hanya IP, port nanti terpisah)
const char *host = "192.168.18.26";
const uint16_t port = 8080;

#define LED_PIN 2
#define BTN_PIN 4

// Sediakan variabel untuk RFID
#define SDA_PIN 5
#define RST_PIN 19

MFRC522 mfrc522(SDA_PIN, RST_PIN);

void setup()
{
    Serial.begin(115200);

    // Setting hostname & koneksi WiFi
    WiFi.mode(WIFI_STA);
    WiFi.setHostname("ESP-32");
    WiFi.begin(ssid, pass);

    // Cek koneksi WiFi
    Serial.print("Menghubungkan ke WiFi");
    while (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
        Serial.print(".");
    }

    Serial.println("\nWiFi Connected");
    Serial.print("IP Address : ");
    Serial.println(WiFi.localIP());

    pinMode(LED_PIN, OUTPUT);
    pinMode(BTN_PIN, INPUT_PULLUP);

    SPI.begin();
    mfrc522.PCD_Init();
    Serial.println("Dekatkan Kartu RFID Anda ke Reader");
    Serial.println("");
}

void loop()
{
    Serial.println(digitalRead(BTN_PIN));
    if (digitalRead(BTN_PIN) == 0)
    {
        // Nyalakan lampu led
        digitalWrite(LED_PIN, HIGH);
        while (digitalRead(BTN_PIN) == 0)
            ;

        // Ubah mode absensi di aplikasi web
        String getData, link;
        HTTPClient http;
        // Get Data
        link = "http://192.168.18.26:8080/rfid/ubah-mode";
        http.begin(link);

        int httpCode = http.GET();
        String payload = http.getString();

        Serial.println(payload);
        http.end();
    }

    // Matikan lampu lED
    digitalWrite(LED_PIN, LOW);

    if (!mfrc522.PICC_IsNewCardPresent())
        return;
    if (!mfrc522.PICC_ReadCardSerial())
        return;

    String IDTAG = "";
    for (byte i = 0; i < mfrc522.uid.size; i++)
    {
        IDTAG += mfrc522.uid.uidByte[i];
    }

    // Nyalakan lampu LED
    digitalWrite(LED_PIN, HIGH);

    // Kirim nomor kartu RFID untuk disimpan ke tabel tmprfid
    WiFiClient client;

    if (!client.connect(host, port))
    {
        Serial.println("Connection Failed");
        return;
    }

    String link;
    HTTPClient http;
    link = "http://192.168.18.26:8080/rfid/send-rfid/" + IDTAG;
    http.begin(link);

    int httpCode = http.GET();
    String payload = http.getString();
    Serial.println(payload);
    http.end();

    delay(2000);
}

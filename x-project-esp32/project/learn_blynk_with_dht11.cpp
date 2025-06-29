#define BLYNK_PRINT Serial
#define BLYNK_TEMPLATE_ID ""
#define BLYNK_TEMPLATE_NAME ""

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include <DHT.h>

char auth[] = "";
char ssid[] = "";
char pass[] = "";

#define DHTPIN 23
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

BlynkTimer timer;

void sendSensorData()
{
    float h = dht.readHumidity();
    float t = dht.readTemperature();

    if (isnan(h) || isnan(t))
    {
        Serial.println("Gagal membaca dari sensor DHT!");
        return;
    }

    Blynk.virtualWrite(V1, h);
    Blynk.virtualWrite(V0, t);

    Serial.print("Kelembaban: ");
    Serial.print(h);
    Serial.print(" %\t");
    Serial.print("Suhu: ");
    Serial.print(t);
    Serial.println(" *C");
}

void setup()
{
    Serial.begin(115200);
    dht.begin();

    // Koneksi Blynk akan otomatis menggunakan BLYNK_TEMPLATE_ID dan BLYNK_DEVICE_NAME
    Blynk.begin(auth, ssid, pass);

    timer.setInterval(3000L, sendSensorData);
}

void loop()
{
    Blynk.run();
    timer.run();
}
#include <Arduino.h>
#include <DHT.h>

#define DHTPIN 2
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

void setup()
{
    Serial.begin(9600);
    dht.begin();
}

void loop()
{
    delay(2000);

    float humidity = dht.readHumidity();
    float temperature = dht.readTemperature();

    if(isnan(humidity) || isnan(temperature)) {
        Serial.println("Gagal Membaca dari sensor DHT11");
        return;
    }

    Serial.print("Kelembapan : ");
    Serial.print(humidity);
    Serial.print(" %\t");

    Serial.print("Temperatur : ");
    Serial.print(temperature);
    Serial.println(" *C\n");
}
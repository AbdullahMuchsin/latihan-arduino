#include <Arduino.h>
#include <DHT.h>

#define DHTPIN 2
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

float humidity;
float temperature;

const int ledHijau = 4;
const int ledMerah = 5;

void setup()
{
    Serial.begin(9600);
    pinMode(ledHijau, OUTPUT);
    pinMode(ledMerah, OUTPUT);
    dht.begin();
}

void loop()
{
    humidity = dht.readHumidity();
    temperature = dht.readTemperature();

    if (isnan(humidity) || isnan(temperature))
    {
        Serial.print("Data Gagal mendapatkan Sensor DHT11");
        return;
    }

    Serial.print("Kelembapan : ");
    Serial.print(humidity);
    Serial.print(" %\t");

    Serial.print("Suhu : ");
    Serial.print(temperature);
    Serial.println(" *C");

    if (temperature > 30)
    {
        digitalWrite(ledMerah, HIGH);
        digitalWrite(ledHijau, LOW);
    }
    else if (temperature < 30)
    {
        digitalWrite(ledMerah, LOW);
        digitalWrite(ledHijau, HIGH);
    }

    delay(2000);
}
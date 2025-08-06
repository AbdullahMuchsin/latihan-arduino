#include <Arduino.h>
#include <SoftwareSerial.h>

SoftwareSerial hujan(34, 35); // RX TX

void setup()
{
    Serial.begin(9600);
    hujan.begin(9600);
}

void loop()
{
    String data_hujan = "";
    while (hujan.available() > 0)
    {
        data_hujan += char(hujan.read());
    }
    data_hujan.trim();
    Serial.println(data_hujan);
    delay(1000);
}
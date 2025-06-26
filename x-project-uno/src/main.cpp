#include <Arduino.h>
#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN 10 // SDA pin
#define RST_PIN 9 // RST pin

MFRC522 mfrc522(SS_PIN, RST_PIN); // Instance

void setup()
{
    Serial.begin(9600);
    while (!Serial)
        ;

    SPI.begin();
    mfrc522.PCD_Init();

    if (!mfrc522.PCD_PerformSelfTest())
    {
        Serial.println("Modul RFID gagal test diri!");
    }
    else
    {
        Serial.println("Modul RFID siap.");
        Serial.println("Letakkan Kartu Anda!");
    }
}

void loop()
{
    if (!mfrc522.PICC_IsNewCardPresent() || !mfrc522.PICC_ReadCardSerial())
        return;

    Serial.print("UID Card : ");
    for (int i = 0; i < mfrc522.uid.size; i++)
    {
        Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? "0" : "");
        Serial.print(mfrc522.uid.uidByte[i], HEX);
        Serial.print(" ");
    }

    Serial.println();

    mfrc522.PICC_HaltA();
    mfrc522.PCD_StopCrypto1();
};
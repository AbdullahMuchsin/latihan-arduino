#include <Arduino.h>
#include <SPI.h>
#include <MFRC522.h>

const int SS_PIN = 10;
const int RST_PIN = 9;

MFRC522 mfrc522(SS_PIN, RST_PIN);

String uid;
const int led = 8;

String getUIDString()
{
    String uidString = "";

    for (byte i = 0; i < mfrc522.uid.size; i++)
    {
        if (mfrc522.uid.uidByte[i] < 0x10)
            uidString += "0";
        uidString += String(mfrc522.uid.uidByte[i], HEX);
    }
    uidString.toUpperCase();

    return uidString;
}

void setup()
{
    Serial.begin(9600);
    pinMode(led, OUTPUT);
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
    uid = getUIDString();

    Serial.println(uid);

    if(uid == "1324C495") digitalWrite(led, HIGH);
    if(uid != "1324C495") digitalWrite(led, LOW);

    mfrc522.PICC_HaltA();
    mfrc522.PCD_StopCrypto1();
};

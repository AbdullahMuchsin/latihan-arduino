#include <Arduino.h>
#include <CTBot.h>

CTBot myBot;

const String ssid = "--- Your ssid ---";     // WiFi SSID
const String pass = "--- Your password ---"; // WiFi Password
const String token = "--- Your Token ---";   // Token Bot

int64_t chatID = 0; // akan diambil otomatis dari pengirim pesan

void setup()
{
    Serial.begin(9600);
    delay(500);
    Serial.println("Memulai telegram bot...");
    Serial.println("Menghubungkan ke WiFi...");

    // Koneksi WiFi
    myBot.wifiConnect(ssid, pass);
    myBot.setTelegramToken(token);

    // Cek koneksi
    if (myBot.testConnection())
    {
        Serial.println("✅ Koneksi Telegram Bot berhasil!");
    }
    else
    {
        Serial.println("❌ Gagal koneksi ke Telegram Bot!");
    }
}

void loop()
{
    TBMessage msg;

    if (myBot.getNewMessage(msg))
    {
        Serial.println("📩 Pesan masuk dari: " + String(msg.sender.username));
        Serial.println("💬 Isi pesan: " + msg.text);

        // Simpan chat ID jika belum ada
        if (chatID == 0)
        {
            chatID = msg.sender.id;
            Serial.print("💾 Chat ID disimpan: ");
            Serial.println(chatID);
        }

        // Ubah pesan jadi huruf kecil semua
        String pesan = msg.text;
        pesan.toLowerCase();

        if (pesan == "hallo")
        {
            myBot.sendMessage(chatID, "Hallo juga, " + msg.sender.firstName + " 👋");
        }
        else if (pesan == "id")
        {
            myBot.sendMessage(chatID, "Chat ID kamu: " + String(chatID));
        }
        else
        {
            myBot.sendMessage(chatID, "Pesan \"" + msg.text + "\" belum dikenali.");
        }
    }
}

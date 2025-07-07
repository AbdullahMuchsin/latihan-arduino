#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup()
{
    Serial.begin(9600);

    if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C))
    {
        Serial.println(F("OLED tidak terdeteksi"));
        for (;;)
            ;
    }

    display.clearDisplay();

    // ======================
    // ICON SINYAL DI KIRI ATAS
    // ======================
    for (int i = 0; i < 4; i++)
    {
        display.fillRect(2 + i * 4, 10 - i * 2, 3, i * 2 + 2, SSD1306_WHITE);
    }

    // ======================
    // ICON BATERAI DI KANAN ATAS
    // ======================
    display.drawRect(108, 2, 18, 8, SSD1306_WHITE); // outline baterai
    display.fillRect(126, 4, 2, 4, SSD1306_WHITE);  // kepala baterai
    display.fillRect(110, 4, 14, 4, SSD1306_WHITE); // isi baterai full

    // ======================
    // ICON WIFI (seperti busur)
    // ======================
    display.drawCircle(88, 6, 5, SSD1306_WHITE);
    display.drawCircle(88, 6, 3, SSD1306_WHITE);
    display.fillCircle(88, 6, 1, SSD1306_WHITE);

    // ======================
    // GARIS PEMISAH
    // ======================
    display.drawLine(0, 14, 128, 14, SSD1306_WHITE);

    // ======================
    // TEKS STATUS DI TENGAH
    // ======================
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(32, 24);
    display.println("Menu Utama");

    // ======================
    // ICON BULAT DI BAWAH
    // ======================
    display.drawCircle(64, 54, 6, SSD1306_WHITE);
    display.fillCircle(64, 54, 3, SSD1306_WHITE);

    display.display();
}

void loop()
{
    // Static, tidak ngapa-ngapain
}

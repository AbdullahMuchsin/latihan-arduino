#include <Arduino.h>

// Serial Monitor 1
int pinLed = 6;

void setup()
{
    pinMode(pinLed, OUTPUT);
    Serial.begin(9600);
}

void loop()
{
    digitalWrite(pinLed, HIGH);
    Serial.println("LED MENYALA");
    delay(100);
    digitalWrite(pinLed, LOW);
    Serial.println("LED PADAM");
    delay(100);
}

#include <Arduino.h>

// Serial Monitor 2
int pinLed = 6;

bool isKlip = false;

void setup()
{
    pinMode(pinLed, OUTPUT);
    Serial.begin(9600);
    Serial.println("Masukkan 1 --> nyala atau 2 --> padam");
}

void loop()
{
    if (Serial.available())
    {
        int kondisi = Serial.parseInt();

        if (kondisi == 1)
        {
            digitalWrite(pinLed, HIGH);
            Serial.println("LED MENYALA");
        }

        if (kondisi == 2)
        {
            digitalWrite(pinLed, LOW);
            Serial.println("LED LOW");
        }

        if (kondisi == 3)
        {
            isKlip = true;
        }

        if (kondisi == 4)
        {
            isKlip = false;
        }
    }

    if (isKlip)
    {
        digitalWrite(7, HIGH);
        Serial.println("LED MERAH NYALA KELAP KELIP");
        delay(200);
        digitalWrite(7, LOW);
        Serial.println("LED MERAH PADAM KELAP KELIP");
        delay(200);
    }
    else
    {
        digitalWrite(7, LOW);
        Serial.println("LED MERAH PADAM KELAP KELIP");
    }
}

// Task Pertemuan Ini
#include <Arduino.h>

// Pin LED
const int ledPins[] = {6, 7, 8, 9};
// Pin Push Button
const int button1 = 2;
const int button2 = 3;
const int button3 = 4;
// Pin Buzzer
const int buzzer = 10;

// Variabel untuk menu
int menuChoice = 0;

// Fungsi menampilkan menu
void showMenu()
{
    Serial.println("=== MENU ===");
    Serial.println("1. LED Kelap-kelip");
    Serial.println("2. Buzzer Sirine (5 detik)");
    Serial.println("3. LED berjalan + Buzzer");
    Serial.println("4. PWM Padamkan LED");
    Serial.print("Pilih menu: ");
}

// Menu 1: LED kelap-kelip
void blinkLEDs()
{
    Serial.println("LED Kelap-kelip 5x");
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            digitalWrite(ledPins[j], HIGH);
        }
        delay(300);
        for (int j = 0; j < 4; j++)
        {
            digitalWrite(ledPins[j], LOW);
        }
        delay(300);
    }
}

// Menu 2: Buzzer sirine 5 detik
void buzzerSirine()
{
    Serial.println("Buzzer sirine 5 detik");
    unsigned long startTime = millis();
    while (millis() - startTime < 5000)
    {
        tone(buzzer, 1000); // bunyikan buzzer 1 kHz
        delay(100);
        noTone(buzzer);
        delay(100);
    }
}

// Menu 3: LED berjalan + buzzer
void ledBerjalanBuzzer()
{
    Serial.println("LED berjalan + Buzzer");
    for (int i = 0; i < 4; i++)
    {
        digitalWrite(ledPins[i], HIGH);
        tone(buzzer, 1000);
        delay(300);
        digitalWrite(ledPins[i], LOW);
        noTone(buzzer);
    }
}

// Menu 4: PWM padamkan LED
void pwmPadamLED()
{
    Serial.println("Padamkan LED dengan PWM");
    for (int brightness = 255; brightness >= 0; brightness -= 5)
    {
        for (int i = 0; i < 4; i++)
        {
            analogWrite(ledPins[i], brightness);
        }
        delay(50);
    }
}

// Fungsi eksekusi menu
void executeMenu(int choice)
{
    switch (choice)
    {
    case 1:
        blinkLEDs();
        break;
    case 2:
        buzzerSirine();
        break;
    case 3:
        ledBerjalanBuzzer();
        break;
    case 4:
        pwmPadamLED();
        break;
    default:
        Serial.println("Pilihan tidak valid!");
    }
}

void setup()
{
    // Inisialisasi LED sebagai OUTPUT
    for (int i = 0; i < 4; i++)
    {
        pinMode(ledPins[i], OUTPUT);
    }

    // Inisialisasi push button sebagai INPUT_PULLUP
    pinMode(button1, INPUT_PULLUP);
    pinMode(button2, INPUT_PULLUP);
    pinMode(button3, INPUT_PULLUP);

    // Inisialisasi buzzer
    pinMode(buzzer, OUTPUT);

    // Serial Monitor untuk menu
    Serial.begin(9600);
}

void loop()
{
    // Jika button3 ditekan, tampilkan menu
    if (digitalRead(button3) == LOW)
    {
        delay(200); // debounce
        showMenu();
        while (!Serial.available())
        {
            // Tunggu input dari Serial Monitor
        }
        menuChoice = Serial.parseInt(); // baca angka dari serial
        Serial.println();
        executeMenu(menuChoice);
    }
}

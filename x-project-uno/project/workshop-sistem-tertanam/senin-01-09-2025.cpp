
//  a. PWM 1
#include <Arduino.h>

int pinLed = 6;

void setup()
{
    pinMode(pinLed, OUTPUT);
}

void loop()
{
    analogWrite(pinLed, 255);
    delay(200);
    analogWrite(pinLed, 128);
    delay(200);
    analogWrite(pinLed, 0);
    delay(200);
}

// b. PWM 2
#include <Arduino.h>

int pinLed = 6;

void setup()
{
}

void loop()
{
    for (int dutyCycle = 0; dutyCycle <= 255; dutyCycle += 5)
    {
        analogWrite(pinLed, dutyCycle);
        delay(100);
    }

    for (int dutyCycle = 255; dutyCycle >= 0; dutyCycle -= 5)
    {
        analogWrite(pinLed, dutyCycle);
        delay(100);
    }
}

// Test Case Materi 4
#include <Arduino.h>

// Pin setup
const int ledPins[] = {9, 8, 7, 6};
const int button1 = 2;
const int button2 = 3;
const int buzzer = 10;

// Fungsi LED kiri ke kanan + buzzer
void ledKiriKanan()
{
    for (int i = 0; i < 4; i++)
    {
        digitalWrite(ledPins[i], HIGH);
        tone(buzzer, 1000); // bunyi buzzer
        delay(200);
        digitalWrite(ledPins[i], LOW);
        noTone(buzzer);
    }
}

// Fungsi LED kanan ke kiri dengan PWM
void ledKananKiriPWM()
{
    for (int i = 3; i >= 0; i--)
    {
        // Fade in
        for (int j = 0; j <= 255; j += 15)
        {
            analogWrite(ledPins[i], j);
            delay(20);
        }
        // Fade out
        for (int j = 255; j >= 0; j -= 15)
        {
            analogWrite(ledPins[i], j);
            delay(20);
        }
    }
}

void setup()
{
    // Set pin LED sebagai output
    for (int i = 0; i < 4; i++)
    {
        pinMode(ledPins[i], OUTPUT);
    }
    pinMode(button1, INPUT_PULLUP);
    pinMode(button2, INPUT_PULLUP);
    pinMode(buzzer, OUTPUT);
}

void loop()
{
    // Baca tombol
    bool btn1State = digitalRead(button1) == LOW; // ditekan = LOW
    bool btn2State = digitalRead(button2) == LOW;

    if (btn1State)
    {
        ledKiriKanan();
    }
    else if (btn2State)
    {
        ledKananKiriPWM();
    }
    else
    {
        // Matikan semua saat idle
        for (int i = 0; i < 4; i++)
        {
            digitalWrite(ledPins[i], LOW);
        }
        noTone(buzzer);
    }
}

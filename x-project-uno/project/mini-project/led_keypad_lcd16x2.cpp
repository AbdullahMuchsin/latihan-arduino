#include <Arduino.h>
#include <keypad.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

const byte ROWS = 4; // Jumlah baris
const byte COLS = 3; // Jumlah kolom
char charKeypad;

// Untuk keypad array 4x3
const char Keys[ROWS][COLS] = {
    {'1', '2', '3'},
    {'4', '5', '6'},
    {'7', '8', '9'},
    {'*', '0', '#'},
};

byte rowPins[ROWS] = {2, 3, 4, 5}; // Jumlah baris
byte colPins[COLS] = {6, 7, 8};    // Jumlah kolom

Keypad kpd = Keypad(makeKeymap(Keys), rowPins, colPins, ROWS, COLS);

const int pinLed = 9;

void setup()
{
    Serial.begin(9600);

    pinMode(pinLed, OUTPUT);

    lcd.init();
    lcd.backlight();
    lcd.setCursor(0, 0);
    lcd.print("== SWITCH LED ==");
    lcd.setCursor(0, 1);
    lcd.print("Keypad Pin: __");
}

void loop()
{
    charKeypad = kpd.getKey();

    if (charKeypad)
    {
        Serial.println(charKeypad);
        lcd.setCursor(12, 1);
        lcd.print("  ");
        lcd.setCursor(12, 1);
        lcd.print(charKeypad);
        
        switch (charKeypad)
        {
        case '1':
            digitalWrite(pinLed, HIGH);
            break;
        case '0':
            digitalWrite(pinLed, LOW);
            break;
        default:
            break;
        }
    }
}
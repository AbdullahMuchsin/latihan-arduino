#include <Arduino.h>
#include <keypad.h>

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

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  charKeypad = kpd.getKey();

  if (charKeypad)
  {
    Serial.println(charKeypad);
  }
}
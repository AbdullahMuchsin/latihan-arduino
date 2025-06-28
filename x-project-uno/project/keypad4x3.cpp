#include <Arduino.h>
#include <Keypad.h>

const byte ROWS = 4; // 4 baris
const byte COLS = 3; // 3 kolom

// Layout tombol untuk 4x3 keypad
char keys[ROWS][COLS] = {
  {'1', '2', '3'},
  {'4', '5', '6'},
  {'7', '8', '9'},
  {'*', '0', '#'}
};

// Pin baris dan kolom ke Arduino (urutan sesuai pin keypad kamu)
byte rowPins[ROWS] = {2, 3,4 , 5};    // Pin baris
byte colPins[COLS] = {6, 7, 8};       // Pin kolom

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

void setup() {
  Serial.begin(9600);
}

void loop() {
  char key = keypad.getKey();
  if (key) {
    Serial.println(key);
  }
}

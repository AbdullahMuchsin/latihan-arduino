#include <Arduino.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);

void setup()
{
  lcd.init();
  lcd.backlight();

  lcd.setCursor(0,0);
  lcd.print("Cappy Bara!");

  lcd.setCursor(0,1);
  lcd.print("Cappy Bara 3x");
}

void loop()
{
  
}
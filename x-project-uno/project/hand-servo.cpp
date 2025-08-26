#include <Arduino.h>
#include <Servo.h>

Servo servoX;
Servo servoY;

int joyX = A2;
int joyY = A3;

void setup()
{
    Serial.begin(9600);
    servoX.attach(9);  // Servo pertama di pin D9
    servoY.attach(10); // Servo kedua di pin D10
}

void loop()
{
    int xVal = analogRead(joyX); // 0 - 1023
    int yVal = analogRead(joyY);

    // Cetak nilai joystick ke Serial Monitor
    Serial.print("X : ");
    Serial.print(xVal);
    Serial.print(" | Y : ");
    Serial.println(yVal);

    // Mapping joystick ke sudut servo 0 - 180
    int angleX = map(xVal, 0, 1023, 0, 180);
    int angleY = map(yVal, 0, 1023, 0, 180);

    servoX.write(angleX);
    servoY.write(angleY);

    delay(15); // biar servo lebih halus
}

#include <Arduino.h>
#include <SoftwareSerial.h>

// JDY-31 Bluetooth pada pin A0 (RX), A1 (TX)
SoftwareSerial bluetooth(A0, A1); // RX, TX

// Lampu & Buzzer
#define light_FR 14  // A0
#define light_FL 15  // A1
#define light_BR 16  // A2
#define light_BL 17  // A3
#define horn_Buzz 18 // A4

// Pin L298N (1 modul)
#define ENA 5 // Motor Kiri PWM
#define IN1 2 // Motor Kiri
#define IN2 3
#define IN3 4 // Motor Kanan
#define IN4 7
#define ENB 6 // Motor Kanan PWM

int command;
int speedCar = 100;
boolean lightFront = false;
boolean lightBack = false;
boolean horn = false;

void setup()
{
    int pins[] = {ENA, ENB, IN1, IN2, IN3, IN4, light_BR, light_BL, horn_Buzz};
    for (int i = 0; i < sizeof(pins) / sizeof(pins[0]); i++)
    {
        pinMode(pins[i], OUTPUT);
    }

    pinMode(A0, INPUT);  // RX
    pinMode(A1, OUTPUT); // TX

    Serial.begin(9600);
    bluetooth.begin(9600);
}

// ===== Gerakan Dasar =====
void goAhead()
{
    // Motor Kiri
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    analogWrite(ENA, speedCar);

    // Motor Kanan
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
    analogWrite(ENB, speedCar);
}

void goBack()
{
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    analogWrite(ENA, speedCar);

    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
    analogWrite(ENB, speedCar);
}

void goLeft()
{
    // Motor kiri mundur
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    analogWrite(ENA, speedCar);

    // Motor kanan maju
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
    analogWrite(ENB, speedCar);
}

void goRight()
{
    // Motor kiri maju
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    analogWrite(ENA, speedCar);

    // Motor kanan mundur
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
    analogWrite(ENB, speedCar);
}

void stopRobot()
{
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
    analogWrite(ENA, 0);
    analogWrite(ENB, 0);
}

// ===== Main Loop =====
void loop()
{
    if (bluetooth.available())
    {
        command = bluetooth.read();
        stopRobot();

        digitalWrite(light_BR, lightBack ? HIGH : LOW);
        digitalWrite(light_BL, lightBack ? HIGH : LOW);
        digitalWrite(horn_Buzz, horn ? HIGH : LOW);

        switch (command)
        {
        case 'F':
            goAhead();
            break;
        case 'B':
            goBack();
            break;
        case 'R':
            goRight();
            break;
        case 'L':
            goLeft();
            break;

        case '0':
            speedCar = 100;
            break;
        case '1':
            speedCar = 130;
            break;
        case '2':
            speedCar = 160;
            break;
        case '3':
            speedCar = 190;
            break;
        case '4':
            speedCar = 220;
            break;
        case '5':
            speedCar = 255;
            break;

        case 'W':
            lightFront = true;
            break;
        case 'w':
            lightFront = false;
            break;
        case 'U':
            lightBack = true;
            break;
        case 'u':
            lightBack = false;
            break;
        case 'V':
            horn = true;
            break;
        case 'v':
            horn = false;
            break;
        }

        // Lampu depan
        if (lightFront)
        {
            pinMode(A0, OUTPUT);
            digitalWrite(A0, HIGH); // light_FR
            pinMode(A1, OUTPUT);
            digitalWrite(A1, HIGH); // light_FL
        }
        else
        {
            pinMode(A0, INPUT); // RX Bluetooth
            pinMode(A1, OUTPUT);
            digitalWrite(A1, LOW);
        }
    }
}

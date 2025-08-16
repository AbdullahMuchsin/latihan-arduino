#include <Arduino.h>
#include <SoftwareSerial.h>

// JDY-31 Bluetooth pada pin A0 (RX), A1 (TX)
SoftwareSerial bluetooth(A0, A1); // RX, TX

// Lampu & Buzzer
#define light_FR 14  // A0 (dipakai juga RX Bluetooth)
#define light_FL 15  // A1 (dipakai juga TX Bluetooth)
#define light_BR 16  // A2
#define light_BL 17  // A3
#define horn_Buzz 18 // A4

// PWM untuk Motor
#define ENA_m1 5  // Motor KIRI
#define ENB_m1 6  // Motor KIRI
#define ENA_m2 10 // Motor KANAN
#define ENB_m2 11 // Motor KANAN

// Input Motor - L298N
// Motor KIRI (L298N 1)
#define IN_11 2 // Maju Depan Kiri
#define IN_12 3 // Mundur Depan Kiri
#define IN_13 4 // Mundur Belakang Kiri
#define IN_14 7 // Maju Belakang Kiri

// Motor KANAN (L298N 2)
#define IN_21 8  // Maju Depan Kanan
#define IN_22 9  // Mundur Depan Kanan
#define IN_23 12 // Mundur Belakang Kanan
#define IN_24 13 // Maju Belakang Kanan

int command;
int speedCar = 100;
boolean lightFront = false;
boolean lightBack = false;
boolean horn = false;

void setup()
{
    int pins[] = {ENA_m1, ENB_m1, ENA_m2, ENB_m2, IN_11, IN_12, IN_13, IN_14,
                  IN_21, IN_22, IN_23, IN_24, light_BR, light_BL, horn_Buzz};
    for (int i = 0; i < sizeof(pins) / sizeof(pins[0]); i++)
    {
        pinMode(pins[i], OUTPUT);
    }

    pinMode(A0, INPUT);  // RX
    pinMode(A1, OUTPUT); // TX

    Serial.begin(9600);
    bluetooth.begin(9600);
}

// Gerak Maju
void goAhead()
{
    // Motor KIRI
    digitalWrite(IN_11, HIGH);
    digitalWrite(IN_12, LOW);
    analogWrite(ENA_m1, speedCar);

    digitalWrite(IN_13, LOW);
    digitalWrite(IN_14, HIGH);
    analogWrite(ENB_m1, speedCar);

    // Motor KANAN
    digitalWrite(IN_21, LOW);
    digitalWrite(IN_22, HIGH);
    analogWrite(ENA_m2, speedCar);

    digitalWrite(IN_23, HIGH);
    digitalWrite(IN_24, LOW);
    analogWrite(ENB_m2, speedCar);
}

// Gerak Mundur
void goBack()
{
    // Motor KIRI
    digitalWrite(IN_11, LOW);
    digitalWrite(IN_12, HIGH);
    analogWrite(ENA_m1, speedCar);

    digitalWrite(IN_13, HIGH);
    digitalWrite(IN_14, LOW);
    analogWrite(ENB_m1, speedCar);

    // Motor KANAN
    digitalWrite(IN_21, HIGH);
    digitalWrite(IN_22, LOW);
    analogWrite(ENA_m2, speedCar);

    digitalWrite(IN_23, LOW);
    digitalWrite(IN_24, HIGH);
    analogWrite(ENB_m2, speedCar);
}

// Belok Kanan (motor kiri maju, motor kanan mundur)
void goRight()
{
    // Motor KIRI
    digitalWrite(IN_11, LOW);
    digitalWrite(IN_12, HIGH);
    analogWrite(ENA_m1, speedCar);

    digitalWrite(IN_13, HIGH);
    digitalWrite(IN_14, LOW);
    analogWrite(ENB_m1, speedCar);

    // Motor KANAN
    digitalWrite(IN_21, LOW);
    digitalWrite(IN_22, HIGH);
    analogWrite(ENA_m2, speedCar);

    digitalWrite(IN_23, HIGH);
    digitalWrite(IN_24, LOW);
    analogWrite(ENB_m2, speedCar);
}

// Belok Kiri (motor kanan maju, motor kiri mundur)
void goLeft()
{
    // Motor KIRI
    digitalWrite(IN_11, HIGH);
    digitalWrite(IN_12, LOW);
    analogWrite(ENA_m1, speedCar);

    digitalWrite(IN_13, LOW);
    digitalWrite(IN_14, HIGH);
    analogWrite(ENB_m1, speedCar);

    // Motor KANAN
    digitalWrite(IN_21, HIGH);
    digitalWrite(IN_22, LOW);
    analogWrite(ENA_m2, speedCar);

    digitalWrite(IN_23, LOW);
    digitalWrite(IN_24, HIGH);
    analogWrite(ENB_m2, speedCar);
}

void stopRobot()
{
    int inPins[] = {IN_11, IN_12, IN_13, IN_14, IN_21, IN_22, IN_23, IN_24};
    for (int i = 0; i < sizeof(inPins) / sizeof(inPins[0]); i++)
    {
        digitalWrite(inPins[i], LOW);
    }
    analogWrite(ENA_m1, 0);
    analogWrite(ENB_m1, 0);
    analogWrite(ENA_m2, 0);
    analogWrite(ENB_m2, 0);
}

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
            goLeft();
            break;
        case 'L':
            goRight();
            break;
        case '0':
            speedCar = 100;
            break;
        case '1':
            speedCar = 115;
            break;
        case '2':
            speedCar = 130;
            break;
        case '3':
            speedCar = 145;
            break;
        case '4':
            speedCar = 160;
            break;
        case '5':
            speedCar = 175;
            break;
        case '6':
            speedCar = 190;
            break;
        case '7':
            speedCar = 205;
            break;
        case '8':
            speedCar = 220;
            break;
        case '9':
            speedCar = 235;
            break;
        case 'q':
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

        // Lampu depan (gunakan A0 dan A1 hanya sebentar)
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

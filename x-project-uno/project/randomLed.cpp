#include <Arduino.h>

const int led1 = 2;
const int led2 = 3;
const int led3 = 4;
const int led4 = 5;
const int led5 = 6;

const int button1 = 8;
const int button2 = 9;

int tipeLed = 0;
boolean autoLed = true;

unsigned long previousMillis = 0;
const long interval = 200; // default interval
int step = 0;              // step pola

void blinkAll()
{
    if (step == 0)
    {
        digitalWrite(led1, HIGH);
        digitalWrite(led2, HIGH);
        digitalWrite(led3, HIGH);
        digitalWrite(led4, HIGH);
        digitalWrite(led5, HIGH);
        step = 1;
    }
    else
    {
        digitalWrite(led1, LOW);
        digitalWrite(led2, LOW);
        digitalWrite(led3, LOW);
        digitalWrite(led4, LOW);
        digitalWrite(led5, LOW);
        step = 0;
    }
}

void runningLight()
{
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
    digitalWrite(led5, LOW);
    switch (step)
    {
    case 0:
        digitalWrite(led1, HIGH);
        break;
    case 1:
        digitalWrite(led2, HIGH);
        break;
    case 2:
        digitalWrite(led3, HIGH);
        break;
    case 3:
        digitalWrite(led4, HIGH);
        break;
    case 4:
        digitalWrite(led5, HIGH);
        break;
    }
    step++;
    if (step > 4)
        step = 0;
}

void bounceLight()
{
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
    digitalWrite(led5, LOW);
    switch (step)
    {
    case 0:
        digitalWrite(led1, HIGH);
        break;
    case 1:
        digitalWrite(led2, HIGH);
        break;
    case 2:
        digitalWrite(led3, HIGH);
        break;
    case 3:
        digitalWrite(led4, HIGH);
        break;
    case 4:
        digitalWrite(led5, HIGH);
        break;
    case 5:
        digitalWrite(led4, HIGH);
        break;
    case 6:
        digitalWrite(led3, HIGH);
        break;
    case 7:
        digitalWrite(led2, HIGH);
        break;
    case 8:
        digitalWrite(led1, HIGH);
        break;
    }
    step++;
    if (step > 8)
        step = 0;
}

void alternateBlink()
{
    if (step == 0)
    {
        digitalWrite(led1, HIGH);
        digitalWrite(led3, HIGH);
        digitalWrite(led5, HIGH);
        digitalWrite(led2, LOW);
        digitalWrite(led4, LOW);
        step = 1;
    }
    else
    {
        digitalWrite(led2, HIGH);
        digitalWrite(led4, HIGH);
        digitalWrite(led1, LOW);
        digitalWrite(led3, LOW);
        digitalWrite(led5, LOW);
        step = 0;
    }
}

void sparkle()
{
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
    digitalWrite(led5, LOW);

    int led = random(1, 6);
    if (led == 1)
        digitalWrite(led1, HIGH);
    else if (led == 2)
        digitalWrite(led2, HIGH);
    else if (led == 3)
        digitalWrite(led3, HIGH);
    else if (led == 4)
        digitalWrite(led4, HIGH);
    else if (led == 5)
        digitalWrite(led5, HIGH);
}

void runPattern()
{
    unsigned long currentMillis = millis();
    if (currentMillis - previousMillis >= interval)
    {
        previousMillis = currentMillis;

        switch (tipeLed)
        {
        case 1:
            blinkAll();
            break;
        case 2:
            runningLight();
            break;
        case 3:
            bounceLight();
            break;
        case 4:
            alternateBlink();
            break;
        case 5:
            sparkle();
            break;
        default:
            break;
        }
    }
}

void autoPattern()
{
    for (int i = 1; i <= 5; i++)
    {
        tipeLed = i;
        step = 0;
        unsigned long startTime = millis();
        while (millis() - startTime < 3000)
        { // tiap pola jalan 3 detik
            runPattern();
            if (digitalRead(button1) == HIGH)
            {
                tipeLed++;
                if (tipeLed > 5)
                    tipeLed = 1;
                autoLed = false;
                step = 0;
                delay(200);
                return;
            }
            if (digitalRead(button2) == HIGH)
            {
                autoLed = true;
                step = 0;
                delay(200);
                return;
            }
        }
    }
}

void manualPattern()
{
    runPattern();
}

void setup()
{
    Serial.begin(9600);
    pinMode(led1, OUTPUT);
    pinMode(led2, OUTPUT);
    pinMode(led3, OUTPUT);
    pinMode(led4, OUTPUT);
    pinMode(led5, OUTPUT);
    pinMode(button1, INPUT);
    pinMode(button2, INPUT);
}

void loop()
{
    // Cek tombol
    if (digitalRead(button1) == HIGH)
    {
        tipeLed++;
        if (tipeLed > 5)
            tipeLed = 1;
        autoLed = false;
        step = 0;
        delay(200); // debounce sederhana
    }

    if (digitalRead(button2) == HIGH)
    {
        autoLed = true;
        step = 0;
        delay(200);
    }

    // Jalankan pola
    if (autoLed)
    {
        autoPattern();
    }
    else
    {
        manualPattern();
    }
}
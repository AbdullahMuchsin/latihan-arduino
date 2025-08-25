// 1 : Kontrol Buzzer
void setup()
{
    pinMode(10, OUTPUT);
}

void loop()
{
    digitalWrite(10, HIGH);
    delay(100);
    digitalWrite(10, LOW);
    delay(100);
}

// 2 : Pushbutton sebagai switch
int pinLed = 6;
int button = 2;
int bacaButton, lastButton, kondisi = 0;

void setup()
{
    pinMode(pinLed, OUTPUT);
    pinMode(button, INPUT);
}

void loop()
{

    bacaButton = digitalRead(button);

    if ((bacaButton == HIGH) && (lastButton == LOW))
    {
        kondisi = 1 - kondisi;
        delay(10);
    }

    lastButton = bacaButton;

    if (kondisi == 1)
    {
        digitalWrite(pinLed, HIGH);
    }
    else
    {
        digitalWrite(pinLed, LOW);
    }
}

// 3 : Pushbutton sebagai toggle switch
int i;
int timer = 500;
int pinLed[] = {6, 7, 8, 9};
int jmlPin = 4;

void setup()
{
    for (int i = 0; i < jmlPin; i++)
    {
        pinMode(pinLed[i], OUTPUT);
    }
}

void loop()
{
    for (int i = 0; i < jmlPin; i++)
    {
        digitalWrite(pinLed[i], HIGH);
        delay(timer);
        digitalWrite(pinLed[i], LOW);
        delay(timer);
    }
}

// 4 : Running LED
int i;
int timer = 500;
int pinLed[] = {6, 7, 8, 9};
int jmlPin = 4;

void setup()
{
    for (int i = 0; i < jmlPin; i++)
    {
        pinMode(pinLed[i], OUTPUT);
    }
}

void loop()
{
    for (int i = 0; i < jmlPin; i++)
    {
        digitalWrite(pinLed[i], HIGH);
        delay(timer);
        digitalWrite(pinLed[i], LOW);
        delay(timer);
    }
}

// 5 : Blink dengan variabel
int pinLed = 6;

void setup()
{
    pinMode(pinLed, OUTPUT);
}

void loop()
{
    digitalWrite(pinLed, HIGH);
    delay(100);
    digitalWrite(pinLed, LOW);
    delay(100);
}

// 6 : Basic blink
void setup()
{
    pinMode(6, OUTPUT);
}

void loop()
{
    digitalWrite(6, HIGH);
    delay(100);
    digitalWrite(6, LOW);
    delay(100);
}
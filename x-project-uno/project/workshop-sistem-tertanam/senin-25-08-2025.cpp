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
int button1 = 2;
int pinled = 6;

int btnState = 0;

void setup()
{
    pinMode(pinLed, OUTPUT);
    pinMode(button1, INPUT);
}

void loop()
{
    btnState = digitalRead(button1);

    if (btnState == LOW)
    {
        digitalWrite(pinLed, HIGH);
    }
    else
    {
        digitalWrite(pinLed, LOW);
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

// 7 : My Case
int pinLed = 6;
int button = 2;
int bacaButton, lastButton, kondisi = 0;

// Tambahan
int button2 = 3;     // untuk LED2
int button3 = 4;     // untuk buzzer
int pin_led2 = 7;    // LED2
int pin_buzzer = 10; // buzzer
int bacaButton3, lastButton3 = HIGH, kondisi_buzzer = 0;

void setup()
{
    pinMode(pinLed, OUTPUT);
    pinMode(button, INPUT_PULLUP);

    // tambahan
    pinMode(button2, INPUT_PULLUP);
    pinMode(button3, INPUT_PULLUP);
    pinMode(pin_led2, OUTPUT);
    pinMode(pin_buzzer, OUTPUT);
}

void loop()
{
    // --- Button 1 : toggle LED1 ---
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

    // --- Button 2 : LED2 nyala hanya saat ditekan ---
    if (digitalRead(button2) == LOW) // karena INPUT_PULLUP, aktif saat LOW
        digitalWrite(pin_led2, HIGH);
    else
        digitalWrite(pin_led2, LOW);

    // --- Button 3 : toggle buzzer ---
    bacaButton3 = digitalRead(button3);
    if ((bacaButton3 == LOW) && (lastButton3 == HIGH))
    {
        kondisi_buzzer = 1 - kondisi_buzzer;
        delay(10);
    }
    lastButton3 = bacaButton3;

    if (kondisi_buzzer == 1)
        digitalWrite(pin_buzzer, HIGH);
    else
        digitalWrite(pin_buzzer, LOW);
}

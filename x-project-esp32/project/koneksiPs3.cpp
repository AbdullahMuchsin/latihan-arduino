#include <Arduino.h>
#include <Ps3Controller.h>

void setup()
{
    Serial.begin(115200);

    // Ganti dengan MAC ESP32 kamu
    Ps3.begin("34:5F:45:A9:44:06");

    Serial.println("Menunggu PS3 Controller terhubung...");
}
int last_lx = 0, last_ly = 0;
int last_rx = 0, last_ry = 0;
int last_l2 = 0, last_r2 = 0;

void loop()
{
    if (Ps3.isConnected())
    {
        // Digital buttons
        if (Ps3.data.button.cross)
            Serial.println("CROSS ditekan");
        if (Ps3.data.button.circle)
            Serial.println("CIRCLE ditekan");
        if (Ps3.data.button.square)
            Serial.println("SQUARE ditekan");
        if (Ps3.data.button.triangle)
            Serial.println("TRIANGLE ditekan");

        if (Ps3.data.button.up)
            Serial.println("UP ditekan");
        if (Ps3.data.button.down)
            Serial.println("DOWN ditekan");
        if (Ps3.data.button.left)
            Serial.println("LEFT ditekan");
        if (Ps3.data.button.right)
            Serial.println("RIGHT ditekan");

        if (Ps3.data.button.l1)
            Serial.println("L1 ditekan");
        if (Ps3.data.button.l2)
            Serial.println("L2 ditekan");
        if (Ps3.data.button.l3)
            Serial.println("L3 ditekan");

        if (Ps3.data.button.r1)
            Serial.println("R1 ditekan");
        if (Ps3.data.button.r2)
            Serial.println("R2 ditekan");
        if (Ps3.data.button.r3)
            Serial.println("R3 ditekan");

        if (Ps3.data.button.start)
            Serial.println("START ditekan");
        if (Ps3.data.button.select)
            Serial.println("SELECT ditekan");
        if (Ps3.data.button.ps)
            Serial.println("PS ditekan");

        // Analog stick (print hanya jika beda > 5)
        if (abs(Ps3.data.analog.stick.lx - last_lx) > 5 ||
            abs(Ps3.data.analog.stick.ly - last_ly) > 5)
        {
            Serial.print("Left Stick: X=");
            Serial.print(Ps3.data.analog.stick.lx);
            Serial.print(" Y=");
            Serial.println(Ps3.data.analog.stick.ly);
            last_lx = Ps3.data.analog.stick.lx;
            last_ly = Ps3.data.analog.stick.ly;
        }

        if (abs(Ps3.data.analog.stick.rx - last_rx) > 5 ||
            abs(Ps3.data.analog.stick.ry - last_ry) > 5)
        {
            Serial.print("Right Stick: X=");
            Serial.print(Ps3.data.analog.stick.rx);
            Serial.print(" Y=");
            Serial.println(Ps3.data.analog.stick.ry);
            last_rx = Ps3.data.analog.stick.rx;
            last_ry = Ps3.data.analog.stick.ry;
        }

        // Analog trigger
        if (abs(Ps3.data.analog.button.l2 - last_l2) > 5 ||
            abs(Ps3.data.analog.button.r2 - last_r2) > 5)
        {
            Serial.print("L2: ");
            Serial.print(Ps3.data.analog.button.l2);
            Serial.print(" R2: ");
            Serial.println(Ps3.data.analog.button.r2);
            last_l2 = Ps3.data.analog.button.l2;
            last_r2 = Ps3.data.analog.button.r2;
        }

        // Contoh getar jika CROSS ditekan
        if (Ps3.data.button.cross)
        {
            Ps3.setRumble(255, 255); // getar maksimal
        }
        else
        {
            Ps3.setRumble(0, 0);
        }

        delay(100); // lebih cepat
    }
}

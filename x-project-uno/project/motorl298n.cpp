#include <Arduino.h>

// Definisi pin untuk Motor A
const int motorA_IN1 = 7; // IN1 pada L298N untuk Motor A
const int motorA_IN2 = 8; // IN2 pada L298N untuk Motor A
const int motorA_EN = 6;  // ENA (PWM) untuk Motor A

// Definisi pin untuk Motor B
const int motorB_IN3 = 4; // IN3 pada L298N untuk Motor B
const int motorB_IN4 = 5; // IN4 pada L298N untuk Motor B
const int motorB_EN = 9;  // ENB (PWM) untuk Motor B

// Fungsi kontrol Motor A
void setMotorA(int dir1, int dir2, int speed)
{
    digitalWrite(motorA_IN1, dir1);
    digitalWrite(motorA_IN2, dir2);
    analogWrite(motorA_EN, speed); // Kecepatan dari 0-255
    // Tambahkan debug di sini
    Serial.print("Motor A -> IN1: ");
    Serial.print(dir1);
    Serial.print(", IN2: ");
    Serial.print(dir2);
    Serial.print(", EN: ");
    Serial.println(speed);
}

// Fungsi kontrol Motor B
void setMotorB(int dir3, int dir4, int speed)
{
    digitalWrite(motorB_IN3, dir3);
    digitalWrite(motorB_IN4, dir4);
    analogWrite(motorB_EN, speed); // Kecepatan dari 0-255
    // Tambahkan debug di sini
    Serial.print("Motor B -> IN3: ");
    Serial.print(dir3);
    Serial.print(", IN4: ");
    Serial.print(dir4);
    Serial.print(", EN: ");
    Serial.println(speed);
}

void setup()
{
    // Set semua pin sebagai OUTPUT
    pinMode(motorA_IN1, OUTPUT);
    pinMode(motorA_IN2, OUTPUT);
    pinMode(motorA_EN, OUTPUT);

    pinMode(motorB_IN3, OUTPUT);
    pinMode(motorB_IN4, OUTPUT);
    pinMode(motorB_EN, OUTPUT);

    // Mulai Serial Monitor
    Serial.begin(9600);
    Serial.println("Inisialisasi selesai. Siap menjalankan motor...");
}

void loop()
{
    // === MOTOR A ===
    Serial.println("\n--- MENGUJI MOTOR A ---");
    Serial.println("Motor A: MAJU dengan KECEPATAN SEDANG (150)");
    setMotorA(HIGH, LOW, 150); // Arah maju
    delay(3000);

    Serial.println("Motor A: MUNDUR dengan KECEPATAN MAKSIMUM (255)");
    setMotorA(LOW, HIGH, 255); // Arah mundur
    delay(3000);

    Serial.println("Motor A: BERHENTI");
    setMotorA(LOW, LOW, 0);
    delay(2000);

    // === MOTOR B ===
    Serial.println("\n--- MENGUJI MOTOR B ---");
    Serial.println("Motor B: MAJU dengan KECEPATAN MAKSIMUM (255)");
    setMotorB(HIGH, LOW, 255);
    delay(3000);

    Serial.println("Motor B: MUNDUR dengan KECEPATAN PELAN (80)");
    setMotorB(LOW, HIGH, 80);
    delay(3000);

    Serial.println("Motor B: BERHENTI");
    setMotorB(LOW, LOW, 0);
    delay(2000);

    // === KEDUA MOTOR SERENTAK ===
    Serial.println("\n--- MENGUJI KEDUA MOTOR SERENTAK ---");
    Serial.println("Kedua Motor: MAJU, Motor A pelan (100), Motor B cepat (200)");
    setMotorA(HIGH, LOW, 100);
    setMotorB(HIGH, LOW, 200);
    delay(4000);

    Serial.println("Kedua Motor: BERHENTI");
    setMotorA(LOW, LOW, 0);
    setMotorB(LOW, LOW, 0);
    delay(2000);

    Serial.println("Ulangi siklus...\n");
}
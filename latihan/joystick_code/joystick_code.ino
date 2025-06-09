// Pin joystick
const int joyX = A0; // Pin untuk sumbu X
const int joyY = A1; // Pin untuk sumbu Y
const int joyButton = 7; // Pin untuk tombol joystick

// Batas untuk menentukan arah
const int threshold = 100; // Toleransi untuk nilai netral
const int centerValue = 512; // Nilai tengah sumbu X dan Y (sekitar 512)

void setup() {
  // Inisialisasi komunikasi serial
  Serial.begin(9600);

  // Set pin tombol sebagai input
  pinMode(joyButton, INPUT_PULLUP);
}

void loop() {
  // Baca nilai sumbu X dan Y
  int xValue = analogRead(joyX);
  int yValue = analogRead(joyY);

  // Baca status tombol
  int buttonState = digitalRead(joyButton);

  // Variabel untuk menyimpan arah
  String direction = "Neutral";

  // Deteksi arah pada sumbu X
  if (xValue < centerValue - threshold) {
    direction = "LEFT";
  } else if (xValue > centerValue + threshold) {
    direction = "RIGHT";
  }

  // Deteksi arah pada sumbu Y
  if (yValue < centerValue - threshold) {
    direction = "TOP";
  } else if (yValue > centerValue + threshold) {
    direction = "BOTTOM";
  }

  // Cetak hasil deteksi arah dan status tombol
  Serial.print("Direction: ");
  Serial.print(direction);
  Serial.print(" | Button: ");
  Serial.println(buttonState == LOW ? "Pressed" : "Not Pressed");

  // Delay untuk mengurangi pembacaan (opsional)
  delay(100);
}

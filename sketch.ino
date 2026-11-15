/*
  Nama : Hanifah Mutia Khansa
  NIM  : 26/588672/PT/11440
  Tugas: Studi Kasus Day 3 - GMRT UGM (Versi Ringkas)
*/

#include <ESP32Servo.h>
#include <Wire.h>

Servo servo1, servo2, servo3, servo4, servo5;

const int pinServo1 = 13; // Roll (berlawanan arah)
const int pinServo2 = 14; // Roll (berlawanan arah)
const int pinServo3 = 26; // Pitch (searah)
const int pinServo4 = 27; // Pitch (searah)
const int pinServo5 = 25; // Yaw
const int pinPIR = 4;  // Sensor PIR

// Ubah sudut [-90..90] ke PWM [1000..2000 us], 0 deg = 1500 us
int sudutKePWM(float sudut) {
  if (sudut > 90) sudut = 90;
  if (sudut < -90) sudut = -90;
  return map((long)round(sudut), -90, 90, 1000, 2000);
}

void setup() {
  Serial.begin(115200);
  Wire.begin(21, 22); // I2C: SDA = GPIO 21, SCL = GPIO 22
  pinMode(pinPIR, INPUT);

  servo1.attach(pinServo1, 1000, 2000);
  servo2.attach(pinServo2, 1000, 2000);
  servo3.attach(pinServo3, 1000, 2000);
  servo4.attach(pinServo4, 1000, 2000);
  servo5.attach(pinServo5, 1000, 2000);

  // Posisi awal 0 derajat (1500 us)
  servo1.writeMicroseconds(1500);
  servo2.writeMicroseconds(1500);
  servo3.writeMicroseconds(1500);
  servo4.writeMicroseconds(1500);
  servo5.writeMicroseconds(1500);

  Serial.println("Siap jalan!");
}

void loop() {
  // 1. Cek gerakan eksternal dari PIR
  if (digitalRead(pinPIR) == HIGH) {
    Serial.println("PIR aktif! Gerak ke posisi target lalu kembali ke 0 deg.");
    servo1.writeMicroseconds(sudutKePWM(45));
    servo2.writeMicroseconds(sudutKePWM(45));
    servo3.writeMicroseconds(sudutKePWM(45));
    servo4.writeMicroseconds(sudutKePWM(45));
    servo5.writeMicroseconds(sudutKePWM(45));
    delay(800);
    servo1.writeMicroseconds(1500);
    servo2.writeMicroseconds(1500);
    servo3.writeMicroseconds(1500);
    servo4.writeMicroseconds(1500);
    servo5.writeMicroseconds(1500);
  }

  // 2. Kasus Uji 1: Roll +30 deg dan Pitch -20 deg
  float roll  = 30.0;
  float pitch = -20.0;

  // Servo 1 & 2 berlawanan arah Roll; Servo 3 & 4 searah Pitch
  int pwm1 = sudutKePWM(-roll);
  int pwm2 = sudutKePWM(-roll);
  int pwm3 = sudutKePWM(pitch);
  int pwm4 = sudutKePWM(pitch);

  servo1.writeMicroseconds(pwm1);
  servo2.writeMicroseconds(pwm2);
  servo3.writeMicroseconds(pwm3);
  servo4.writeMicroseconds(pwm4);

  // 3. Contoh sederhana Yaw berhenti -> jeda 1 detik -> kembali ke 0 deg (1500 us)
  float yaw = 30.0;
  servo5.writeMicroseconds(sudutKePWM(yaw));
  delay(1000);
  servo5.writeMicroseconds(1500);

  // Cetak PWM Servo 1 - 4 ke Serial Monitor
  Serial.print("PWM S1: "); Serial.print(pwm1); Serial.print(" us | ");
  Serial.print("PWM S2: "); Serial.print(pwm2); Serial.print(" us | ");
  Serial.print("PWM S3: "); Serial.print(pwm3); Serial.print(" us | ");
  Serial.print("PWM S4: "); Serial.print(pwm4); Serial.println(" us");

  delay(500);
}

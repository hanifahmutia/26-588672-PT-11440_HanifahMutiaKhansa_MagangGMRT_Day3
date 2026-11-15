# Tugas Day 3 - GMRT UGM

## Profile
* **Nama:** Hanifah Mutia Khansa
* **NIM:** 26/588672/PT/11440

## Description
Sistem simulasi kendali gerak berbasis mikrokontroler **ESP32** menggunakan sensor gerak **PIR** dan sensor orientasi **IMU**, dengan aktuator berupa **5 motor servo** serta komunikasi **I2C** (SDA = GPIO 21, SCL = GPIO 22) dan **Serial Monitor** (115200 baud).

## Feature Table
| Fitur | Input (Sensor) | Output (Aktuator) | Perilaku |
| :--- | :--- | :--- | :--- |
| Roll | Data orientasi sumbu Roll (IMU / nilai uji) | Servo 1 & Servo 2 | Bergerak berlawanan arah sesuai nilai Roll dengan pemetaan sudut ke lebar pulsa PWM (1000–2000 µs) |
| Pitch | Data orientasi sumbu Pitch (IMU / nilai uji) | Servo 3 & Servo 4 | Bergerak searah sesuai nilai Pitch dengan pemetaan sudut ke lebar pulsa PWM (1000–2000 µs) |
| Yaw | Data orientasi sumbu Yaw (IMU / nilai uji) | Servo 5 | Bergerak ke posisi target, berhenti/jeda 1 detik, lalu kembali ke posisi 0° (1500 µs) |
| Gerakan Eksternal | Sensor PIR (GPIO 4) | Servo 1–5 | Saat terdeteksi gerakan (HIGH), aktuator merespons ke posisi target lalu kembali ke posisi awal (0° / 1500 µs) |

## How to Run
1. Buka tautan proyek Wokwi: `[tempel link proyek Wokwi di sini]`.
2. Pastikan library **`ESP32Servo`** sudah terpasang di **Project Libraries** pada Wokwi.
3. Klik tombol **Start Simulation / Play** (hijau) untuk menjalankan kode pada `sketch.ino` dan amati pergerakan servo serta keluaran nilai PWM pada **Serial Monitor**.
4. Untuk menguji respons gerakan eksternal, picu sinyal `HIGH` pada sensor PIR selama simulasi berjalan.
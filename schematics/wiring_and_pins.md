# 15km LoRa32 Rescue Rover — Wiring & RF Specifications

## ⚡ Power & Subsystem Architecture
* **Core Processing:** Heltec Wi-Fi LoRa 32 V2 (ESP32 + SX1276) integrating both the microcontroller and the Sub-GHz transceiver.
* **Long-Range Link:** Operating on the 868MHz/915MHz ISM band with a configured Spreading Factor of 12 for maximum communication distance (up to 15km line-of-sight).
* **Locomotion:** Dual-channel L298N motor driver powering high-torque DC gear motors for rugged terrain navigation.

---

## 📌 Complete GPIO Pinout Mapping (`Heltec LoRa32 V2`)

| Component | Component Pin | Heltec LoRa32 Pin | Engineering Function |
| :--- | :--- | :--- | :--- |
| **NEO-6M GPS Module** | `TX / RX` | `GPIO 17 (RX2) / GPIO 16 (TX2)` | NMEA Satellite Coordinate Stream |
| **DS18B20 Waterproof Sensor** | `DATA` | `GPIO 23` | 1-Wire Thermal & Environmental Monitoring |
| **L298N Motor Controller** | `IN1, IN2, IN3, IN4` | `GPIO 12, 13, 25, 26` | Drivetrain Locomotion Control |
| **SX1276 LoRa Transceiver** | *Internal SPI Bus* | *NSS: 18, RST: 14, DIO0: 26* | Sub-GHz Radio Packet Transmission |
| **Power Supply System** | `VCC / GND` | `5V / GND Rail` | Dual 18650 Li-Ion Battery Architecture |

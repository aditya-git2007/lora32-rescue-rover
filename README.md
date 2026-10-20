# lora32-rescue-rover
long-range 15km wireless rescue rover powered by ESP32 LoRa and GPS telemetry.
# 📡 15km LoRa32 Long-Range Rescue Rover

> A robust, long-range wireless tracking and telemetry robotic rover designed for disaster-response scenarios where standard cellular and Wi-Fi networks fail.

[![Status](https://img.shields.io/badge/Status-Completed-emerald?style=for-the-badge)]()
[![MCU](https://img.shields.io/badge/Controller-ESP32_LoRa_SX1276-blue?style=for-the-badge)]()

---

## 🎯 Overview & Mission Objective
The **15km LoRa32 Rescue Rover** acts as an independent field unit capable of transmitting live telemetry, sensor data, and GPS coordinates over extreme distances up to 15 kilometers using high-efficiency Sub-GHz radio frequencies (868MHz/915MHz) without relying on cellular towers.

---

## 🛠️ Bill of Materials (BOM)
| Component | Specification / Role |
| :--- | :--- |
| **Heltec Wi-Fi LoRa 32 (ESP32 + SX1276)** | Dual-core MCU integrated with SX1276 LoRa transceiver & OLED display |
| **NEO-6M GPS Module** | Real-time latitude/longitude satellite coordinate acquisition |
| **DS18B20 Waterproof Temperature Sensor** | Environmental thermal tracking |
| **L298N Motor Driver + Dual DC Motors** | High-torque skid-steer drivetrain |
| **Power Architecture** | 18650 Li-Ion dual battery pack with voltage regulation |

---

## 📌 GPIO Pinout & LoRa Configuration
| Component | Component Pin | Heltec LoRa32 Pin | Engineering Function |
| :--- | :--- | :--- | :--- |
| **NEO-6M GPS Module** | `TX / RX` | `GPIO 17 (RX2) / GPIO 16 (TX2)` | NMEA Data Stream |
| **DS18B20 Thermal Sensor**| `DATA` | `GPIO 23` | 1-Wire Environmental Monitoring |
| **L298N Motor Controller**| `IN1, IN2, IN3, IN4`| `GPIO 12, 13, 25, 26` | Rover Drivetrain Locomotion |
| **SX1276 LoRa Transceiver**| *Internal SPI* | *NSS: 18, RST: 14, DIO0: 26* | 868MHz/915MHz Long-Range Radio Link |

---

## 📂 Repository Structure
```text
📂 lora32-rescue-rover
├── 📂 firmware             <-- ESP32 LoRa C++ source code (lora_rover_node.ino)
├── 📂 schematics           <-- Wiring & frequency configuration notes
└── 📄 README.md            <-- Project documentation

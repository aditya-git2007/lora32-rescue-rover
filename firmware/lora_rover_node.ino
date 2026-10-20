```cpp
// ==========================================
// 15KM LORA32 RESCUE ROVER — FIRMWARE
// Long-Range Telemetry & GPS Packet Transmitter
// Developer: Aditya Kumar Gupta (aditya.geninfo.in)
// ==========================================

#include <SPI.h>
#include <LoRa.h>
#include <TinyGPS++.h>
#include <Wire.h>

#define BAND 868E6 // Operating Frequency: 868MHz / 915MHz

TinyGPSPlus gps;
HardwareSerial GPSStream(2); // Use UART2 on ESP32

// Motor Control Pins
const int m1 = 12;
const int m2 = 13;
const int m3 = 25;
const int m4 = 26;

void setup() {
  Serial.begin(115200);
  GPSStream.begin(9600, SERIAL_8N1, 16, 17);

  pinMode(m1, OUTPUT); pinMode(m2, OUTPUT);
  pinMode(m3, OUTPUT); pinMode(m4, OUTPUT);

  // Initialize LoRa (Heltec V2 board pins)
  SPI.begin(5, 19, 27, 18);
  LoRa.setPins(18, 14, 26);
  
  if (!LoRa.begin(BAND)) {    Serial.println("LoRa Initialization Failed!");
    while (1);
  }
  LoRa.setSpreadingFactor(12); // Maximum range setting
  LoRa.setSignalBandwidth(125E3);
}

void loop() {
  while (GPSStream.available() > 0) {
    gps.encode(GPSStream.read());
  }

  if (gps.location.isUpdated()) {
    String packet = "ROVER_ID:01 | LAT: " + String(gps.location.lat(), 6) + 
                    " | LNG: " + String(gps.location.lng(), 6) + 
                    " | ALT: " + String(gps.altitude.meters());

    // Send packet via Long-Range LoRa Radio
    LoRa.beginPacket();
    LoRa.print(packet);
    LoRa.endPacket();
    
    Serial.println("Telemetry Sent: " + packet);
  }
  delay(5000);
}

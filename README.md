# 🏥 Smart Healthcare Monitoring System

A real-time IoT-based healthcare system using ESP32 + FreeRTOS + MQTT + LoRa to monitor and transmit vital health data efficiently.

---

## 🚀 **Key Features**

- 📏 Height Measurement (Ultrasonic Sensor)  
- ❤️ Heart Rate & SpO₂ Monitoring (IR Sensor / MAX30102)  
- 🩺 Blood Pressure Tracking  
- ⚡ FreeRTOS Multitasking (Real-time processing)  
- 📡 Dual Communication → MQTT (Cloud) + LoRa (Long-Range)  
- 📱 Flutter Dashboard (Live Data Visualization)  

---

## 🧠 **How It Works**

Sensors → ESP32 (FreeRTOS) → MQTT (Cloud) + LoRa → Flutter Dashboard

---

## 🛠️ **Tech Stack**

- ESP32, FreeRTOS  
- MQTT Protocol, LoRa (SX1278)  
- Flutter (Frontend Dashboard)  
- Arduino Framework  

---


---

## 📊 **Sample Data (MQTT Payload)**

```json
{
  "height": 165.2,
  "heart_rate": 78,
  "spo2": 97,
  "bp": 120
}
⚡ Setup
Configure WiFi + MQTT Broker
Upload code to ESP32
Subscribe to topic → health/data
Monitor data on Flutter Dashboard
🔥 Highlights
Real-time health monitoring
Hybrid communication (MQTT + LoRa)
Scalable IoT architecture
Real-world healthcare application
👨‍💻 Author

Rohan Immidichetty

📜 License

MIT License

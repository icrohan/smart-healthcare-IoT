# smart-healthcare-IoT
Smart Healthcare Monitoring System (IoT + ESP32 + FreeRTOS)

A real-time IoT-based healthcare monitoring system built using ESP32, FreeRTOS, and wireless communication technologies (MQTT + LoRa) to track and transmit vital health parameters efficiently.

🚀 Project Overview

This project focuses on creating a smart, scalable, and real-time health monitoring solution that can be used in:

🏠 Smart Homes
🏥 Clinics & Hospitals
🌍 Remote Healthcare / Rural Areas

The system collects multiple health metrics and transmits them wirelessly to a cloud-based dashboard for monitoring and analysis.

⚙️ Features
📏 Height Measurement using Ultrasonic Sensor
❤️ Heart Rate Monitoring (IR Sensor / MAX30102)
🩸 SpO₂ (Oxygen Saturation) Tracking
🩺 Blood Pressure Monitoring
⚡ FreeRTOS-based Multitasking
📡 Dual Communication:
MQTT (WiFi - Cloud)
LoRa (Long-range communication)
📱 Flutter-based Dashboard (Real-time Visualization)
🔄 Real-time Data Processing & Transmission
🧠 System Architecture
Sensors → ESP32 (FreeRTOS Tasks)
        → MQTT (WiFi) → Cloud / Web Dashboard
        → LoRa → Remote Receiver
🛠️ Tech Stack
Embedded & Hardware
ESP32
Ultrasonic Sensor
MAX30102 (SpO₂ + Heart Rate)
Blood Pressure Sensor
Software & Communication
FreeRTOS
MQTT Protocol
LoRa (SX1278)
Arduino Framework
Frontend
Flutter (Web/App Dashboard)

🔌 Hardware Setup
ESP32 Pin Configuration
Component	Pin
Ultrasonic TRIG	12
Ultrasonic ECHO	13
BP Sensor	34
LoRa SS	5
LoRa RST	14
LoRa DIO0	2
📡 Data Flow
Sensors collect real-time health data
ESP32 processes data using FreeRTOS tasks
Data is formatted into JSON
Sent via:
MQTT → Cloud Dashboard
LoRa → Remote Node
Flutter app displays live health metrics
📊 Sample Data (MQTT Payload)
{
  "height": 165.2,
  "heart_rate": 78,
  "spo2": 97,
  "bp": 120
}
⚡ Installation & Setup
1️⃣ Clone the Repository
git clone https://github.com/your-username/smart-healthcare-iot.git
cd smart-healthcare-iot
2️⃣ ESP32 Setup
Install Arduino IDE
Install required libraries:
WiFi.h
PubSubClient
LoRa.h
Wire.h
Update WiFi credentials in code:
const char* ssid = "YOUR_WIFI";
const char* password = "YOUR_PASSWORD";
Upload code to ESP32
3️⃣ MQTT Testing

Use public broker:

broker.hivemq.com

Subscribe to topic:

health/data
4️⃣ Flutter App
Use mqtt_client package
Connect to same MQTT broker
Display real-time sensor data
🔥 Key Highlights
⚡ Real-time multitasking with FreeRTOS
🌐 Hybrid communication (LoRa + MQTT)
📊 Scalable IoT architecture
🧩 Modular and extensible system
🏥 Applicable in real-world healthcare scenarios
🚀 Future Enhancements
🤖 AI-based health anomaly detection
🔐 Blockchain-based secure medical records
📈 Advanced analytics dashboard
🧠 Edge AI on ESP32
📡 Integration with wearable devices
👨‍💻 Author

Rohan Immidichetty

IoT | Embedded Systems | Web3 | AI
Passionate about building real-world impactful systems
⭐ Support

If you like this project:

⭐ Star this repository
🍴 Fork it
🤝 Connect with me on LinkedIn
📜 License

This project is open-source under the MIT License.

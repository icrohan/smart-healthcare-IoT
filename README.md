🏥 Smart Healthcare Monitoring System

A real-time IoT-based healthcare system using ESP32 + FreeRTOS + MQTT + LoRa to monitor and transmit vital health data.

🚀 Key Features
📏 Height Measurement (Ultrasonic Sensor)
❤️ Heart Rate & SpO₂ Monitoring (IR Sensor / MAX30102)
🩺 Blood Pressure Tracking
⚡ FreeRTOS Multitasking for real-time processing
📡 Dual Communication: MQTT (Cloud) + LoRa (Long-Range)
📱 Flutter Dashboard for live data visualization
🧠 How It Works

Sensors → ESP32 (FreeRTOS) → MQTT (Cloud) + LoRa → Flutter Dashboard

🛠️ Tech Stack
ESP32, FreeRTOS
MQTT, LoRa
Flutter (Frontend)
Arduino Framework
📊 Sample Data
{
  "height": 165.2,
  "heart_rate": 78,
  "spo2": 97,
  "bp": 120
}
⚡ Setup
Configure WiFi + MQTT broker
Upload code to ESP32
Subscribe to topic: health/data
View data on Flutter Dashboard
🔥 Highlights
⚡ Real-time health monitoring
🌐 Hybrid communication (MQTT + LoRa)
🧩 Scalable IoT architecture
🏥 Practical healthcare application
👨‍💻 Author

Rohan Immidichetty

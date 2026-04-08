#include <WiFi.h>
#include <PubSubClient.h>
#include <Wire.h>
#include <SPI.h>
#include <LoRa.h>

// ================= CONFIG =================

// WiFi
const char* ssid = "YOUR_WIFI";
const char* password = "YOUR_PASSWORD";

// MQTT
const char* mqtt_server = "broker.hivemq.com";
const int mqtt_port = 1883;
const char* topic = "health/data";

// Ultrasonic
#define TRIG 12
#define ECHO 13

// BP Sensor
#define BP_PIN 34

// LoRa Pins
#define SS 5
#define RST 14
#define DIO0 2

// ================= GLOBALS =================
WiFiClient espClient;
PubSubClient client(espClient);

// ================= WIFI =================
void setup_wifi() {
  Serial.println("Connecting to WiFi...");
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWiFi Connected!");
}

// ================= MQTT =================
void reconnect_mqtt() {
  while (!client.connected()) {
    Serial.println("Connecting to MQTT...");
    if (client.connect("ESP32Client")) {
      Serial.println("MQTT Connected");
    } else {
      delay(1000);
    }
  }
}

void mqtt_send(String payload) {
  if (!client.connected()) reconnect_mqtt();
  client.loop();
  client.publish(topic, payload.c_str());
}

// ================= LORA =================
void lora_init() {
  LoRa.setPins(SS, RST, DIO0);
  if (!LoRa.begin(433E6)) {
    Serial.println("LoRa Failed!");
    while (1);
  }
  Serial.println("LoRa Initialized");
}

void lora_send(String data) {
  LoRa.beginPacket();
  LoRa.print(data);
  LoRa.endPacket();
}

// ================= ULTRASONIC =================
float getHeight() {
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);

  long duration = pulseIn(ECHO, HIGH);
  float distance = duration * 0.034 / 2;

  return distance;
}

// ================= SPO2 + HR (SIMULATED / BASIC) =================
int getHeartRate() {
  return random(70, 100);
}

int getSpO2() {
  return random(95, 100);
}

// ================= BP =================
int getBP() {
  int val = analogRead(BP_PIN);
  return map(val, 0, 4095, 80, 140);
}

// ================= FREERTOS TASK =================
void sensorTask(void *pvParameters) {
  while (1) {

    float height = getHeight();
    int hr = getHeartRate();
    int spo2 = getSpO2();
    int bp = getBP();

    // JSON Payload
    String data = "{";
    data += "\"height\":" + String(height) + ",";
    data += "\"heart_rate\":" + String(hr) + ",";
    data += "\"spo2\":" + String(spo2) + ",";
    data += "\"bp\":" + String(bp);
    data += "}";

    Serial.println(data);

    // Send via MQTT
    mqtt_send(data);

    // Send via LoRa
    lora_send(data);

    vTaskDelay(2000 / portTICK_PERIOD_MS);
  }
}

// ================= SETUP =================
void setup() {
  Serial.begin(115200);

  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);

  setup_wifi();
  client.setServer(mqtt_server, mqtt_port);

  lora_init();

  // Create FreeRTOS Task
  xTaskCreate(
    sensorTask,
    "Sensor Task",
    4096,
    NULL,
    1,
    NULL
  );
}

// ================= LOOP =================
void loop() {
  // Empty (FreeRTOS handles execution)
}

#ifndef CONFIG_H
#define CONFIG_H

// WiFi
const char* ssid = "YOUR_WIFI";
const char* password = "YOUR_PASS";

// MQTT
const char* mqtt_server = "broker.hivemq.com";
const int mqtt_port = 1883;
const char* topic = "health/data";

// LoRa Pins
#define SS 5
#define RST 14
#define DIO0 2

// Ultrasonic
#define TRIG 12
#define ECHO 13

// BP sensor (example analog)
#define BP_PIN 34

#endif

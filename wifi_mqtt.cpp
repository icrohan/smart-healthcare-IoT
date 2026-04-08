#include <WiFi.h>
#include <PubSubClient.h>
#include "config.h"

WiFiClient espClient;
PubSubClient client(espClient);

void setup_wifi() {
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }
}

void reconnect_mqtt() {
  while (!client.connected()) {
    client.connect("ESP32Client");
  }
}

void mqtt_init() {
  client.setServer(mqtt_server, mqtt_port);
}

void mqtt_send(String payload) {
  if (!client.connected()) reconnect_mqtt();
  client.loop();
  client.publish(topic, payload.c_str());
}

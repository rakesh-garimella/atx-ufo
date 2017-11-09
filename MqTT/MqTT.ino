#include "PubSubClient.h"
#include <ESP8266WiFi.h>

#define FASTLED_ESP8266_D1_PIN_ORDER

const char* ssid = "YourSSID"; //type your WIFI information inside the quotes
const char* password = "YourWIFIpassword";
const char* mqtt_server = "ServerIP";
const char* mqtt_username = "username";
const char* mqtt_password = "password";
const int mqtt_port = 18906;

#define SENSORNAME "clientid"

#include "FastLED.h"

#define NUM_LEDS 30 //this defines the number of LED Segments in the Strip
#define DATA_PIN 4 //plug the green wire of the TM1803 Radioshack Strip into Pin 7
CRGB leds[NUM_LEDS];

WiFiClient espClient;
PubSubClient client(espClient);

void printCurrentNet() {
  // print the SSID of the network you're attached to:
  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());

  // print the received signal strength:
  long rssi = WiFi.RSSI();
  Serial.print("signal strength (RSSI):");
  Serial.println(rssi);

}

void setup_wifi() {
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid);

  delay(120);

  printCurrentNet();

}

void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");
}


void reconnect() {
  // Loop until we're reconnected
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    // Attempt to connect
    if (client.connect(SENSORNAME, mqtt_username, mqtt_password)) {
      Serial.println("connected");
      client.subscribe("Message");
      setColor(0, 0, 0);
      sendState();
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}
void setup() {
  Serial.begin(115200);
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
  delay(50);
  Serial.println();
  Serial.print("MAC: ");
  Serial.println(WiFi.macAddress());

  setup_wifi();

  client.setServer(mqtt_server, mqtt_port);
  client.setCallback(callback);




}

void loop() {
  // put your main code here, to run repeatedly:

  if (!client.connected()) {
    reconnect();
  }

  client.loop();




}


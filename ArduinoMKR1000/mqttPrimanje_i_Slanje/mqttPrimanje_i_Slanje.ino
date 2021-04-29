#include <ArduinoMqttClient.h>
#include <WiFi101.h> 
#include <FastLED.h>

#include "arduino_secrets.h"
///////please enter your sensitive data in the Secret tab/arduino_secrets.h
char ssid[] = SECRET_SSID;        // your network SSID (name)
char pass[] = SECRET_PASS;    // your network password (use for WPA, or use as key for WEP)

// To connect with SSL/TLS:
// 1) Change WiFiClient to WiFiSSLClient.
// 2) Change port value from 1883 to 8883.
// 3) Change broker value to a server with a known SSL/TLS root certificate 
//    flashed in the WiFi module.

WiFiClient wifiClient;
MqttClient mqttClient(wifiClient);

const char broker[] = "10.0.0.3";
int        port     = 1883;
const char topic[]  = "naredbe";
const char topicPub[] = "test";

#define NUM_LEDS 60
#define DATA_PIN 3
#define CLOCK_PIN 13

CRGB leds[NUM_LEDS];

// dodan botun na D6
#define button 1
bool prekidac = false;
void paliLedice()
{
  for(int whiteLed = 0; whiteLed < NUM_LEDS; whiteLed = whiteLed + 1) {
      // Turn our current led on to white, then show the leds
      leds[whiteLed] = CRGB::White;

      // Show the leds (only one of which is set to white, from above)
      FastLED.show();

      // Wait a little bit
      delay(50);
   }
}

void gasiLedice()
{
  for(int whiteLed = 0; whiteLed < NUM_LEDS; whiteLed = whiteLed + 1) {
      leds[whiteLed] = CRGB::Black;
      FastLED.show();
      delay(50);
   }
}


void setup() {
  delay(2000);
  FastLED.addLeds<WS2811, DATA_PIN, RGB>(leds, NUM_LEDS);
  
  //Initialize serial and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }

  // attempt to connect to Wifi network:
  Serial.print("Attempting to connect to WPA SSID: ");
  Serial.println(ssid);
  while (WiFi.begin(ssid, pass) != WL_CONNECTED) {
    // failed, retry
    Serial.print(".");
    delay(5000);
  }

  Serial.println("You're connected to the network");
  Serial.println();

  // You can provide a unique client ID, if not set the library uses Arduino-millis()
  // Each client must have a unique client ID
  // mqttClient.setId("clientId");

  // You can provide a username and password for authentication
  // mqttClient.setUsernamePassword("username", "password");

  Serial.print("Attempting to connect to the MQTT broker: ");
  Serial.println(broker);

  if (!mqttClient.connect(broker, port)) {
    Serial.print("MQTT connection failed! Error code = ");
    Serial.println(mqttClient.connectError());

    while (1);
  }

  Serial.println("You're connected to the MQTT broker!");
  Serial.println();

  Serial.print("Subscribing to topic: ");
  Serial.println(topic);
  Serial.println();

  // subscribe to a topic
  mqttClient.subscribe(topic);

  // topics can be unsubscribed using:
  // mqttClient.unsubscribe(topic);

  Serial.print("Waiting for messages on topic: ");
  Serial.println(topic);
  Serial.println();
}

void loop() {

  bool provjeraBotuna = digitalRead(button);
  
  if (provjeraBotuna) {
    provjeraBotuna = false;
    prekidac = !prekidac;
    if (prekidac){
      Serial.print("Sending message to topic: ");
      Serial.println(topic);
      Serial.println("1");

    // send message, the Print interface can be used to set the message contents
      mqttClient.beginMessage(topic);
      mqttClient.print("1");
      mqttClient.endMessage();

      Serial.println();

    }
    else{
      Serial.print("Sending message to topic: ");
      Serial.println(topic);
      Serial.println("0");

    // send message, the Print interface can be used to set the message contents
      mqttClient.beginMessage(topic);
      mqttClient.print("0");
      mqttClient.endMessage();

      Serial.println();
    }
    delay(500);
  }

  int messageSize = mqttClient.parseMessage();
  if (messageSize) {
    // we received a message, print out the topic and contents
    Serial.print("Received a message with topic '");
    Serial.print(mqttClient.messageTopic());
    Serial.print("', length ");
    Serial.print(messageSize);
    Serial.println(" bytes:");
    char poruka = (char)mqttClient.read();
    // use the Stream interface to print the contents
    Serial.println(poruka);
    if (poruka == '1')
    {
      paliLedice();
      prekidac = true;
    }
    else
    {
      gasiLedice();
      prekidac = false;
    }
    Serial.println("Done.");
  }
}

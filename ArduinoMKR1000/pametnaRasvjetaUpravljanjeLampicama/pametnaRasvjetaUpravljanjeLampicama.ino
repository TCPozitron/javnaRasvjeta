
#include <ArduinoMqttClient.h>
#include <WiFi101.h> 

#include "arduino_secrets.h"
///////please enter your sensitive data in the Secret tab/arduino_secrets.h
char ssid[] = SECRET_SSID;        // your network SSID (name)
char pass[] = SECRET_PASS;    // your network password (use for WPA, or use as key for WEP)

#define led1 10
#define led2 9
#define led3 8
#define led4 7

WiFiClient wifiClient;
MqttClient mqttClient(wifiClient);

const char broker[] = "10.0.0.12";
int        port     = 1883;
const char topic[]  = "naredbe";
const char topicPub[] = "test";

void on1(){
  digitalWrite(led1, HIGH);
}
void on2(){
  digitalWrite(led2, HIGH);
}
void on3(){
  digitalWrite(led3, HIGH);
}
void on4(){
  digitalWrite(led4, HIGH);
}

void off1(){
  digitalWrite(led1, LOW);
}
void off2(){
  digitalWrite(led2, LOW);
}
void off3(){
  digitalWrite(led3, LOW);
}
void off4(){
  digitalWrite(led4, LOW);
}


void setup() {
  delay(200);
  digitalWrite(led1, HIGH);
  delay(200);
  digitalWrite(led2, HIGH);
  delay(200);
  digitalWrite(led3, HIGH);
  delay(200);
  digitalWrite(led4, HIGH);
  delay(200);
  digitalWrite(led1, LOW);
  delay(200);
  digitalWrite(led2, LOW);
  delay(200);
  digitalWrite(led3, LOW);
  delay(200);
  digitalWrite(led4, LOW);

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

/*
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
  */

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

    // ok, tu je mogao switch-case, ali mi se nije dalo
    
    if (poruka == '1')
    {
      on1();
    }
    if (poruka == '2')
    {
      on2();
    }
    if (poruka == '3')
    {
      on3();
    }
    if (poruka == '4')
    {
      on4();
    }
    if (poruka == '5')
    {
      off1();
    }
    if (poruka == '6')
    {
      off2();
    }
    if (poruka == '7')
    {
      off3();
    }
    if (poruka == '8')
    {
      off4();
    }

    

    
    Serial.println();

    Serial.println();
  }
}


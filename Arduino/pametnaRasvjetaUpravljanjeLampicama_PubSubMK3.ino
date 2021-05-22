
#include <PubSubClient.h>
#include <WiFi101.h>

#include "arduino_secrets.h"
///////please enter your sensitive data in the Secret tab/arduino_secrets.h
char ssid[] = SECRET_SSID;  // your network SSID (name)
char pass[] = SECRET_PASS;  // your network password (use for WPA, or use as key for WEP)

#define led1 2
#define led2 3
#define led3 4
#define led4 5

IPAddress server(10, 0, 0, 12);
WiFiClient wifiClient;
PubSubClient mqttClient(wifiClient);

int port = 1883;
const char topic[] = "naredbe";
const char topicPub[] = "test";
char poruka[6];
char razinaSvjetlosti[2];
char duljinaTrajanja[2];
int svjetlost;
int trajanje;

void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");

  for (int i = 0; i < length; i++) {
    poruka[i] = (char)payload[i];
    Serial.print((char)payload[i]);
    }
  Serial.println();
  if (poruka[0] == '1' && poruka[1] != '9') { on1(poruka); }
  if (poruka[0] == '2' && poruka[1] != '9') { on2(poruka); }
  if (poruka[0] == '3' && poruka[1] != '9') { on3(poruka); }
  if (poruka[0] == '4' && poruka[1] != '9') { on4(poruka); }
  if (poruka[0] == '1' && poruka[1] == '9') { off1(); }
  if (poruka[0] == '2' && poruka[1] == '9') { off2(); }
  if (poruka[0] == '3' && poruka[1] == '9') { off3(); }
  if (poruka[0] == '4' && poruka[1] == '9') { off4(); }

}

void reconnect() {
  // Loop until we're reconnected
  while (!mqttClient.connected()) {
    Serial.print("Attempting MQTT connection...");
    // Attempt to connect
    if (mqttClient.connect("arduinoClient")) {
      Serial.println("connected");
      ledFlash(3);
      // Once connected, publish an announcement...
      mqttClient.publish(topicPub, "hello world");
      // ... and resubscribe
      mqttClient.subscribe(topic);
    } else {
      Serial.print("failed, rc=");
      Serial.print(mqttClient.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}

void ledFlash(int broj){
  for (int i = 0; i < broj; i++){
    digitalWrite(led1, HIGH);
      digitalWrite(led2, HIGH);
      digitalWrite(led3, HIGH);
      digitalWrite(led4, HIGH);delay(250);
      digitalWrite(led1, LOW);delay(100);
      digitalWrite(led2, LOW);delay(100);
      digitalWrite(led3, LOW);delay(100);
      digitalWrite(led4, LOW);delay(200);
  }
}

void on1(char poruka[]) {
  digitalWrite(led1, HIGH);
  Serial.println("On Led1");
  Serial.print("Razina svjetlosti: ");
  for (int i = 1; i < 3; i++) {
    razinaSvjetlosti[i-1] = poruka[i];
    Serial.print(razinaSvjetlosti[i-1]);
    }
    Serial.println();

    Serial.print("Duljina trajanja: ");
    for (int i = 3; i < 5; i++) {
    duljinaTrajanja[i-3] = poruka[i];
    Serial.print(duljinaTrajanja[i-3]);
    }
    Serial.println();
    // convert char[] u integer
    svjetlost = atoi(&razinaSvjetlosti[0]);
    trajanje = atoi(&duljinaTrajanja[0]);
    Serial.println(svjetlost);
    Serial.println(trajanje);
    // izračun jakosti svjetla (od 0-255)
    float fSvjetlost = (float)svjetlost;
    int jacina = (int)(255*(fSvjetlost/100));
    Serial.print("Jačina: "); Serial.println(jacina);
    if (svjetlost != 0){
      analogWrite(led1, jacina);
      delay(trajanje*1000);
      analogWrite(led1, 255);
    }
}
void on2(char poruka[]) {
  digitalWrite(led2, HIGH);
  Serial.println("On Led2");
  Serial.print("Razina svjetlosti: ");
  for (int i = 1; i < 3; i++) {
    razinaSvjetlosti[i-1] = poruka[i];
    Serial.print(razinaSvjetlosti[i-1]);
    }
    Serial.println();

    Serial.print("Duljina trajanja: ");
    for (int i = 3; i < 5; i++) {
    duljinaTrajanja[i-3] = poruka[i];
    Serial.print(duljinaTrajanja[i-3]);
    }
    Serial.println();
    // convert char[] u integer
    svjetlost = atoi(&razinaSvjetlosti[0]);
    trajanje = atoi(&duljinaTrajanja[0]);
    Serial.println(svjetlost);
    Serial.println(trajanje);
    // izračun jakosti svjetla (od 0-255)
    float fSvjetlost = (float)svjetlost;
    int jacina = (int)(255*(fSvjetlost/100));
    Serial.print("Jačina: "); Serial.println(jacina);
    if (svjetlost != 0){
      analogWrite(led2, jacina);
      delay(trajanje*1000);
      analogWrite(led2, 255);
    }
}
void on3(char poruka[]) {
  digitalWrite(led3, HIGH);
  Serial.println("On Led3");
  Serial.print("Razina svjetlosti: ");
  for (int i = 1; i < 3; i++) {
    razinaSvjetlosti[i-1] = poruka[i];
    Serial.print(razinaSvjetlosti[i-1]);
    }
    Serial.println();

    Serial.print("Duljina trajanja: ");
    for (int i = 3; i < 5; i++) {
    duljinaTrajanja[i-3] = poruka[i];
    Serial.print(duljinaTrajanja[i-3]);
    }
    Serial.println();
    // convert char[] u integer
    svjetlost = atoi(&razinaSvjetlosti[0]);
    trajanje = atoi(&duljinaTrajanja[0]);
    Serial.println(svjetlost);
    Serial.println(trajanje);
    // izračun jakosti svjetla (od 0-255)
    float fSvjetlost = (float)svjetlost;
    int jacina = (int)(255*(fSvjetlost/100));
    Serial.print("Jačina: "); Serial.println(jacina);
    if (svjetlost != 0){
      analogWrite(led3, jacina);
      delay(trajanje*1000);
      analogWrite(led3, 255);
    }
}
void on4(char poruka[]) {
  digitalWrite(led4, HIGH);
  Serial.println("On Led4");
  Serial.print("Razina svjetlosti: ");
  for (int i = 1; i < 3; i++) {
    razinaSvjetlosti[i-1] = poruka[i];
    Serial.print(razinaSvjetlosti[i-1]);
    }
    Serial.println();

    Serial.print("Duljina trajanja: ");
    for (int i = 3; i < 5; i++) {
    duljinaTrajanja[i-3] = poruka[i];
    Serial.print(duljinaTrajanja[i-3]);
    }
    Serial.println();
    // convert char[] u integer
    svjetlost = atoi(&razinaSvjetlosti[0]);
    trajanje = atoi(&duljinaTrajanja[0]);
    Serial.println(svjetlost);
    Serial.println(trajanje);
    // izračun jakosti svjetla (od 0-255)
    float fSvjetlost = (float)svjetlost;
    int jacina = (int)(255*(fSvjetlost/100));
    Serial.print("Jačina: "); Serial.println(jacina);
    if (svjetlost != 0){
      analogWrite(led4, jacina);
      delay(trajanje*1000);
      analogWrite(led4, 255);
    }
}

void off1() {
  analogWrite(led1, 0);
  Serial.println("Off Led1");
}
void off2() {
  analogWrite(led2, 0);
  Serial.println("Off Led2");
}
void off3() {
  analogWrite(led3, 0);
  Serial.println("Off Led3");
}
void off4() {
  analogWrite(led4, 0);
  Serial.println("Off Led4");
}


void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  delay(500);
  digitalWrite(led1, HIGH);
  delay(250);
  digitalWrite(led2, HIGH);
  delay(250);
  digitalWrite(led3, HIGH);
  delay(250);
  digitalWrite(led4, HIGH);
  delay(250);
  digitalWrite(led1, LOW);delay(250);
  digitalWrite(led2, LOW);delay(250);
  digitalWrite(led3, LOW);delay(250);
  digitalWrite(led4, LOW);delay(250);

  //Initialize serial and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ;  // wait for serial port to connect. Needed for native USB port only
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

  mqttClient.setServer(server, port);
  mqttClient.setCallback(callback);

  // topics can be unsubscribed using:
  // mqttClient.unsubscribe(topic);
}

void loop() {
  if (!mqttClient.connected()) {
    reconnect();
  }
  mqttClient.loop();

}

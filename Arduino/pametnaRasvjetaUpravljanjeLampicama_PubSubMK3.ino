// biblioteke za MQTT protokol i WiFi povezivanje
#include <PubSubClient.h>
#include <WiFi101.h>
// wifi ssid i pass se učitavaju iz odvojenog dokumenta
#include "arduino_secrets.h"
char ssid[] = SECRET_SSID;  
char pass[] = SECRET_PASS;  

// definiranje pinova za LED diode
#define led1 2
#define led2 3
#define led3 4
#define led4 5

// definiranje IP adrese MQTT brokera (Raspberry Pi)
IPAddress server(10, 0, 0, 12);
// instanciranje objekata za povezivanje na wifi i mqtt
WiFiClient wifiClient;
PubSubClient mqttClient(wifiClient);

// definiranje mqtt porta, kanala i ostalih varijabli
int port = 1883;
const char topic[] = "naredbe";
const char topicPub[] = "test";
char poruka[6];
char razinaSvjetlosti[2];
char duljinaTrajanja[2];
int svjetlost;
int trajanje;

// metoda za spajanje na MQTT broker i slanje poruke na 'test' kanal nakon spajanja
void reconnect() {
  // petlja se izvršava dok spajanje na MQTT broker nije uspješno
  while (!mqttClient.connected()) {
    Serial.print("Pokušaj spajanja na MQTT broker... ");
    // Pokušaj spajanja
    if (mqttClient.connect("arduinoClient")) {
      Serial.println("Spojen!");
      // vizualan signal spajanja na MQTT broker
      ledFlash(3);
      // slanje poruke na 'test' kanal nakon spajanja
      mqttClient.publish(topicPub, "Dobro jutro!");
      // prijava na kanal 'naredbe'
      mqttClient.subscribe(topic);
    } else {
      // debug kod neuspjeha spajanja na MQTT broker
      Serial.print("neuspjeh, kodStanja=");
      Serial.print(mqttClient.state());
      Serial.println(" pokušat ću opet nakon 5 sekundi");
      // pauza od 5 sekundi
      delay(5000);
    }
  }
}

// metoda za vizualan signal spajanja na MQTT broker
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
// metoda koja se izvršava kada stigne mqtt poruka na kanal 'naredbe'
void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Poruka na kanalu [");
  Serial.print(topic);
  Serial.print("]");

// čitanje poruke i spremanje svakog byte-a u niz char poruka[6]
  for (int i = 0; i < length; i++) {
    poruka[i] = (char)payload[i];
    Serial.print((char)payload[i]);
    }
  Serial.println();
  
  //provjera poruke
  /*
  * poruke dolaze u obliku xyyzz gdje je:
  * x - broj LED diode
  * yy - razina svjetlosti
  * zz - duljina trajanja regulacije
  * y = 9 označava naredbu isključivanje LED diode
  * npr. 12530 znači da LED 1 radi na 25% intenziteta 30 sekundi
  * y = 0 znači 100% intenziteta
  */
  if (poruka[0] == '1' && poruka[1] != '9') { on1(poruka); }
  if (poruka[0] == '2' && poruka[1] != '9') { on2(poruka); }
  if (poruka[0] == '3' && poruka[1] != '9') { on3(poruka); }
  if (poruka[0] == '4' && poruka[1] != '9') { on4(poruka); }
  if (poruka[0] == '1' && poruka[1] == '9') { off1(); }
  if (poruka[0] == '2' && poruka[1] == '9') { off2(); }
  if (poruka[0] == '3' && poruka[1] == '9') { off3(); }
  if (poruka[0] == '4' && poruka[1] == '9') { off4(); }

}
//metode za uključivanje LED dioda (on1, on2, on3 i on4)
void on1(char poruka[]) {
  // uključivanje LED diode sa intenzintetom od 100%
  analogWrite(led1, 255);
  Serial.println("On Led1");
  
  // dekodiranje poruke na yy - intenzitet i zz - duljina trajanja regulacije
  Serial.print("Razina svjetlosti: ");
  // čita drugi i treći byte poruke i sprema ih u niz char razinaSvjetlosti[2]
  for (int i = 1; i < 3; i++) {
    razinaSvjetlosti[i-1] = poruka[i];
    Serial.print(razinaSvjetlosti[i-1]);
    }
    Serial.println();
  
  // čita četvrti i peti byte poruke i sprema ih u niz char duljinaTrajanja[2]
    Serial.print("Duljina trajanja: ");
    for (int i = 3; i < 5; i++) {
    duljinaTrajanja[i-3] = poruka[i];
    Serial.print(duljinaTrajanja[i-3]);
    }
    Serial.println();
  
    // pretvorba tipa char[] u integer i debug ispis
    svjetlost = atoi(&razinaSvjetlosti[0]);
    trajanje = atoi(&duljinaTrajanja[0]);
    Serial.println(svjetlost);
    Serial.println(trajanje);
  
    // izračun jakosti svjetla (od 0-255)
    float fSvjetlost = (float)svjetlost;
    int jacina = (int)(255*(fSvjetlost/100));
    //debug
    Serial.print("Jačina: "); Serial.println(jacina);
    
    // postavljanje intenziteta LED diode i duljine trajanja regulacije
    if (svjetlost != 0){
      analogWrite(led1, jacina);
      delay(trajanje*1000);
      //nakon isteka vremena regulacije LED dioda se postavlja na 100% intenziteta
      analogWrite(led1, 255);
    }
}

void on2(char poruka[]) {
  analogWrite(led2, 255);
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
  analogWrite(led3, 255);
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
  analogWrite(led4, 255);
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

// metode za isključivanje LED dioda (off1, off2, off3 i off4)
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
  // postavljanje pinova
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  // vizualni signal uključivanja (testiranje LED dioda)
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

  //inicijalizacija serial porta
  Serial.begin(9600);

  // pokušaj spajanja na WiFi mrežu
  Serial.print("Spajanje na SSID: ");
  Serial.println(ssid);
  while (WiFi.begin(ssid, pass) != WL_CONNECTED) {
    // failed, retry
    Serial.print(".");
    delay(500);
  }

  Serial.println("Spojen sam na mrežu!");
  Serial.println();

  // postavljanje MQTT brokera i naziva metode za izvršavanje kad stigme poruka na kanal
  mqttClient.setServer(server, port);
  mqttClient.setCallback(callback);

}

void loop() {
  // provjera veze prema MQTT brokeru
  if (!mqttClient.connected()) {
    reconnect();
  }
  // osiguravanje da se ne prekine veza prema MQTT brokeru
  mqttClient.loop();

}

#!/usr/bin/env python

# biblioteke za čitanje argumenata iz naredbe i mqtt
import sys
import paho.mqtt.client as mqtt
# definitanje IP adrese, porta, kanala i poruke za mqtt
broker = "127.0.0.1"
port = 1883
topic = "naredbe"
# poruka se sastoji od argumenata koje šalju php skripte
# prvi argument je broj LED diode, drugi je postotak intenziteta svjetla, treći je duljina trajanja regulacije
poruka = str(sys.argv[1])+str(sys.argv[2])+str(sys.argv[3])

# debug
print(poruka)
# definiranje mqtt client-a
client = mqtt.Client("lightControl")
# spajanje na mqtt broker
client.connect(broker, port)
# slanje poruke na kanal 'naredbe'
client.publish(topic, poruka)

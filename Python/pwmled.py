#!/usr/bin/env python

import sys
import paho.mqtt.client as mqtt

broker = "127.0.0.1"
port = 1883
topic = "naredbe"
poruka = str(sys.argv[1])+str(sys.argv[2])+str(sys.argv[3])

print(poruka)
client = mqtt.Client("lightControl")
client.connect(broker, port)
client.publish(topic, poruka)

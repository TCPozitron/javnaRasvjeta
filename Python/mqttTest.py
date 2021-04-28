#!/usr/bin/env python

import sys
import paho.mqtt.client as mqtt

broker = "127.0.0.1"
port = 1883
topic = "test"
poruka = str(sys.argv[1])

def on_message(client, userdata, message):
    print("message received " ,str(message.payload.decode("utf-8")))
    print("message topic=",message.topic)
    print("message qos=",message.qos)
    print("message retain flag=",message.retain)

client = mqtt.Client("lightControl")
client.connect(broker, port)
client.publish(topic, poruka)
client.subscribe("podaci")
client.on_message = on_message
client.loop_start()



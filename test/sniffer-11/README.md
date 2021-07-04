
<!--
Maintainer:   jeffskinnerbox@yahoo.com / www.jeffskinnerbox.me
Version:      0.0.1
-->


<div align="center">
<img src="http://www.foxbyrd.com/wp-content/uploads/2018/02/file-4.jpg" title="These materials require additional work and are not ready for general use." align="center">
</div>


-----



# DESCRIPTION
Wi-Fi Sniffer as a Human detector

This is the Material for video: https://www.youtube.com/watch?v=fmhjtzmLrg8

Things to do before you start:
- In mqtt.h update mqttServer = "Your Broker IP address"
- replace MQTT_USERNAME, MQTT_KEY if you do not use Peter Scargills script or you changed the "admin, admin".
- In WiFi_Sniffer set mySSID and MyPassword
- The mqtt topic is Sniffer/#

You find a sample Node-Red flow. Just copy-paste the raw file into your Node-Red

[Migrating from version 5 to 6](https://arduinojson.org/v6/doc/upgrade/)

# PHYSICAL DESIGN

## Hardware

## Wiring

# SOFTWARE DESIGN

## Sources

## Libraries
Install using the Library Manager in Arduino:

- ESP8266
- ArduinoJson ( https://bblanchon.github.io/ArduinoJson/ )
- PubSubClient ( https://pubsubclient.knolleary.net )

# SERIAL MONITOR
To monitor the programs activities while operating, power the NodeMCU via
USB connection to a Linux computer and execute the following: `screen /dev/ttyUSB0 9600,cs8`.
To terminate monitoring, enter: `CNTR-a :quit`.

# TESTING

# USAGE

# SOURCES


<!--
Maintainer:   jeffskinnerbox@yahoo.com / www.jeffskinnerbox.me
Version:      0.0.1
-->


<div align="center">
<img src="http://www.foxbyrd.com/wp-content/uploads/2018/02/file-4.jpg" title="These materials require additional work and are not ready for general use." align="center">
</div>


-----


# Sniffer-11
This is [Wi-Fi Sniffer as a Human detector][01] which has a companion [video by Andreas Spiess][02].

Things to do before you start:
- In mqtt.h update mqttServer = "Your Broker IP address"
- replace MQTT_USERNAME, MQTT_KEY if you do not use Peter Scargills script or you changed the "admin, admin".
- In WiFi_Sniffer set mySSID and MyPassword
- The mqtt topic is Sniffer/#
You find a sample Node-Red flow. Just copy-paste the raw file into your Node-Red

Install using the Library Manager in Arduino:
- ESP8266
- ArduinoJson ( https://bblanchon.github.io/ArduinoJson/ )
- PubSubClient ( https://pubsubclient.knolleary.net )

### Device Programming
ESP8266 was flashed using the [DIYMall ESP Prog][04] or
[Stemedu USB to ESP8266 ESP-01 programmer board][05].




[01]:https://github.com/SensorsIot/Wi-Fi-Sniffer-as-a-Human-detector
[02]:https://www.youtube.com/watch?v=fmhjtzmLrg8
[03]:
[04]:
[04]:http://www.diymalls.com/USB-to-ESP8266-Wifi-Programmer-Adapter-CH340C
[05]:https://www.amazon.com/gp/product/B08QMMGZLB

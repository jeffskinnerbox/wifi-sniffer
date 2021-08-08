
<!--
Maintainer:   jeffskinnerbox@yahoo.com / www.jeffskinnerbox.me
Version:      0.0.1
-->


<div align="center">
<img src="http://www.foxbyrd.com/wp-content/uploads/2018/02/file-4.jpg" title="These materials require additional work and are not ready for general use." align="center">
</div>


-----



[ESP8266 WifiSniffer](https://github.com/kalanda/esp8266-sniffer)
[How I tracked +500 people with ESP8266](https://hackaday.io/project/174644-how-i-tracked-500-people-with-esp8266)
[ESP8266 TURNED SECRETIVE WIFI PROBE REQUEST SNIFFER](https://hackaday.com/2020/09/20/esp8266-turned-secretive-wifi-probe-request-sniffer/)

phone is constantly searching for all WiFi networks which you already connect in the past (unless you did remove as "saved"), saying to anyone who is listening for those public packets where you have been before, and of course, your unique device MAC address.

Those public packets are named as "probe requests" and are used by smartphones to connect faster to wifi networks than if it waits for the network send a Beacon frame to announce the SSID.

This program just listen for those "probe requests" and prints to serial port the information. For now only shows the RSSI (bigger values are near devices), the MAC address of the device and the SSID (if available) of the wifi network which is looking for.

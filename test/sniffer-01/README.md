
T<!--
Maintainer:   jeffskinnerbox@yahoo.com / www.jeffskinnerbox.me
Version:      0.0.1
-->


<div align="center">
<img src="http://www.foxbyrd.com/wp-content/uploads/2018/02/file-4.jpg" title="These materials require additional work and are not ready for general use." align="center">
</div>


-----


This is the ordinal "[ESP8266 Mini Sniff][01]" by Ray Burnette,
later replaced by "[ESP8266 Sniffer][02]"
(called `sniffer-02` in my repository).
The [ordinal posting][03] Ray Burnette post has been deleted.
This device is purely a sniffer, and as such,
it doesn't interfere with WiFi commuication to report results.

Using ESP-01 device set to promiscuous mode (or is it monitor mode).

Programmed using the [DIYMall ESP Prog][04].



# Testing
```bash
screen /dev/ttyUSB0 57600,cs8clscls
cat /dev/ttyUSB0 | grep --line-buffered 74LL5
```



[01]:https://forum.arduino.cc/t/esp8266-mini-sniff/459923
[02]:https://www.hackster.io/kosme/esp8266-sniffer-9e4770
[03]:https://www.hackster.io/rayburne/esp8266-mini-sniff-f6b93a
[04]:http://www.diymalls.com/USB-to-ESP8266-Wifi-Programmer-Adapter-CH340C

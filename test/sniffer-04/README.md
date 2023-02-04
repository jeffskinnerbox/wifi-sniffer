
<!--
Maintainer:   jeffskinnerbox@yahoo.com / www.jeffskinnerbox.me
Version:      0.0.1
-->


<div align="center">
<img src="http://www.foxbyrd.com/wp-content/uploads/2018/02/file-4.jpg" title="These materials require additional work and are not ready for general use." align="center">
</div>


-----



# Sniffer-04
This is the [ESP8266 Friend Detector][01]
which detects when someone you know is near, so that you could display a greeting.

Using ESP-01 device set to promiscuous mode (or is it monitor mode).

### Device Programming
ESP8266 was flashed using the [DIYMall ESP Prog][04] or
[Stemedu USB to ESP8266 ESP-01 programmer board][05].

### Testing
```bash
screen /dev/ttyUSB0 57600,cs8cls
cat /dev/ttyUSB0 | grep --line-buffered 74LL5
```



[01]:https://www.hackster.io/ricardooliveira/esp8266-friend-detector-12542e
[02]:
[03]:
[04]:http://www.diymalls.com/USB-to-ESP8266-Wifi-Programmer-Adapter-CH340C
[05]:https://www.amazon.com/gp/product/B08QMMGZLB

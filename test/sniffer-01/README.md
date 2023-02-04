
T<!--
Maintainer:   jeffskinnerbox@yahoo.com / www.jeffskinnerbox.me
Version:      0.0.1
-->


<div align="center">
<img src="http://www.foxbyrd.com/wp-content/uploads/2018/02/file-4.jpg" title="These materials require additional work and are not ready for general use." align="center">
</div>


-----


# Sniffer-01
This is the ordinal "[ESP8266 Mini Sniff][01]" (backup stored [here][06]) by Ray Burnette,
later replaced, and potentially upgraded a bit, by "[ESP8266 Sniffer][02]"
(called `sniffer-02` in my repository).
The [ordinal posting][03] Ray Burnette post has been deleted.
This device is purely a sniffer, and as such,
it doesn't interfere with WiFi communication to report results.

Using ESP-01 device set to promiscuous mode (or is it monitor mode).

### Device Programming
ESP8266 was flashed using the [DIYMall ESP Prog][04] or
[Stemedu USB to ESP8266 ESP-01 programmer board][05].

### Testing
```bash
screen /dev/ttyUSB0 57600,cs8clscls
cat /dev/ttyUSB0 | grep --line-buffered 74LL5
```



[01]:https://forum.arduino.cc/t/esp8266-mini-sniff/459923
[02]:https://www.hackster.io/kosme/esp8266-sniffer-9e4770
[03]:https://www.hackster.io/rayburne/esp8266-mini-sniff-f6b93a
[04]:http://www.diymalls.com/USB-to-ESP8266-Wifi-Programmer-Adapter-CH340C
[05]:https://www.amazon.com/gp/product/B08QMMGZLB
[06]:https://github.com/witussk/wifi-sniffer-burnette-backup


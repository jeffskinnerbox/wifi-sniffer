
<!--
Maintainer:   jeffskinnerbox@yahoo.com / www.jeffskinnerbox.me
Version:      0.0.1
-->


<div align="center">
<img src="http://www.foxbyrd.com/wp-content/uploads/2018/02/file-4.jpg" title="These materials require additional work and are not ready for general use." align="center">
</div>


-----


# ESP8266 Deauther
The [ESSP8266 Deauther][01] firmware allows you to easily perform a variety of actions
to test 802.11 networks using an ESP8266.
Both versions 2 & 3 of this tool can perfrom the following attaches:

* Probe Scanner
* Deauth Attack
* Beacon Attack
* Probe Attack

The [deauthentication attack][02] is the main feature,
which can be used to disconnect devices from their WiFi network.
A lot of outdated WiFi devices are vulnerable to this type of attach,
for example, cheap IoT hardware.
With the arival of WiFi-6 devices, this is slowly changing.
With an ESP8266 Deauther, you can easily test this attack on your 2.4GHz WiFi network/devices
and see whether it's successful or not.

The prevention of deauthentication attacks does not offer many options.
But there are effective strategies for mitigating their impact.

* **Ensure that your network applies WPA2 encryption.**
If you use a pre-shared key, it must be complex
and lengthy to withstand threats like brute-force attacks.
* **Use devices that suppot 802.11w standards**,
which validates deauthentication frames and discards spoofed ones.
Older hardware and IoT devices might not support it.

* [Deauther or Jammer: What's the difference?](https://www.youtube.com/watch?v=gOyfD44A7rE)
* [How a deauthentication attack works][02]
* [Documentation: ESP8266 Deauther](http://deauther.com/docs/version3#esp8266-deauther-v3)
* [GetHub: ESP8266 Deauther - Version 3](https://github.com/SpacehuhnTech/esp8266_deauther/tree/v3)

### Device Programming
ESP8266 was flashed using the [DIYMall ESP Prog][04] or
[Stemedu USB to ESP8266 ESP-01 programmer board][05].

### Testing
```bash
screen /dev/ttyUSB0 57600,cs8clscls
cat /dev/ttyUSB0 | grep --line-buffered 74LL5
```



[01]:http://deauther.com/
[02]:https://atlasvpn.com/blog/what-is-a-deauthentication-attack
[03]:
[04]:http://www.diymalls.com/USB-to-ESP8266-Wifi-Programmer-Adapter-CH340C
[05]:https://www.amazon.com/gp/product/B08QMMGZLB


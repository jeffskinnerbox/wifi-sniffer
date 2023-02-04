
/* include all necessary libraries */
#include <ESP8266WiFi.h>
#include <Arduino.h>
#include <TimeLib.h>
#include <PCAP.h>

extern "C" {
  #include "user_interface.h"
}


//===== SETTINGS =====//
#define CHANNEL 1
#define BAUD_RATE 9600
#define CHANNEL_HOPPING true //if true it will scan on all channels
#define MAX_CHANNEL 11 //(only necessary if channelHopping is true)
#define HOP_INTERVAL 214 //in ms (only necessary if channelHopping is true)

//===== Run-Time variables =====//
PCAP pcap = PCAP();
int ch = CHANNEL;
unsigned long lastChannelChange = 0;

//===== FUNCTIONS =====//

/* will be executed on every packet the ESP8266 gets while beeing in promiscuous mode */
void sniffer(uint8_t *buf, uint16_t len) {
  uint32_t timestamp = now(); //current timestamp
  uint32_t microseconds = (unsigned int)(micros() - millis() * 1000); //micro seconds offset (0 - 999)
  pcap.newPacketSerial(timestamp, microseconds, len, buf); //write packet to file
}
int loop1 = 0;
void scan()
{
  Serial.println("WiFI XScanner V0.1");
  Serial.println("Scanning.....");
  // WiFi.scanNetworks will return the number of networks found
  int n = WiFi.scanNetworks();

  Serial.println("Scanning done");
  if (n == 0)
    Serial.println("no networks found");
  else
  {
    Serial.print(n);
    Serial.println(" Networks found");

    for (int i = 0; i < n; ++i)
    {
      // Print SSID and RSSI for each network found
      Serial.print("|");
      Serial.print(i + 1);
      Serial.print(" SSID: ");
      Serial.print(WiFi.SSID(i));
       Serial.print("    MAC:  ");
      Serial.print(WiFi.BSSIDstr(i));
      Serial.print(" RSSI: ");
      Serial.print(WiFi.RSSI(i));
       Serial.print("db   CH:");
      Serial.print(WiFi.channel(i));
      Serial.print("  Hidden: ");
      Serial.print(WiFi.isHidden(i));
      Serial.print("   ENC: ");
      switch(WiFi.encryptionType(i))
      {
        case ENC_TYPE_NONE:
              Serial.print("OPEN|");
        case ENC_TYPE_WEP:
              Serial.print("WEP|");
        case ENC_TYPE_TKIP:
              Serial.print("TKIP|");
        case ENC_TYPE_CCMP:
              Serial.print("CCMP|");
        case ENC_TYPE_AUTO:
              Serial.println("");

      }
      delay(100);
    }
  }
  Serial.println("---");

  // Wait a bit before scanning again

}
//===== SETUP =====//
void setup() {

  /* start Serial */
  Serial.begin(BAUD_RATE);
  delay(200);
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  scan();
  delay(5000);
  Serial.println();

  Serial.println("2 Seconds to Self-Destruct");
  delay(2000);
  Serial.println("<<START>>");
  pcap.startSerial();

  /* setup wifi */
  wifi_set_opmode(STATION_MODE);
  wifi_promiscuous_enable(0);
  WiFi.disconnect();
  wifi_set_promiscuous_rx_cb(sniffer);
  wifi_set_channel(ch);
  wifi_promiscuous_enable(1);
}

//===== LOOP =====//
void loop() {
  /* Channel Hopping */
  if(CHANNEL_HOPPING){
    unsigned long currentTime = millis();
    if(currentTime - lastChannelChange >= HOP_INTERVAL){
      lastChannelChange = currentTime;
      ch++; //increase channel
      if(ch > MAX_CHANNEL) ch = 1;
      wifi_set_channel(ch); //switch to new channel
    }
  }
}

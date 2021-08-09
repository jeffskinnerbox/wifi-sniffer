// by Ray Burnette 20161013 compiled on Linux 16.3 using Arduino 1.6.12
// Edited by Mads Mogensen (Gruppe 7) to filter by mac addresses and dump to serial


#include <ESP8266WiFi.h>

#include "sdk_structs.h"
#include "iee80211_structs.h"

// Mac address of our wifi access point.
//AA:BB:CC:DD:EE:FF
static const char ap_mac[6] = { 0xAA, 0xBB, 0xCC, 0xDD, 0xEE, 0xFF};


// Mac addresses of the ESP8266 chips used in this project
//2c:3a:e8:36:09:10
//2c:3a:e8:1b:53:75
//5c:cf:7f:69:08:3d
//5c:cf:7f:69:11:04
//5c:cf:7f:69:16:c7
//5c:cf:7f:69:16:ca
//5c:cf:7f:69:0c:ed
//dc:4f:22:0a:05:82
//dc:4f:22:0a:12:b0
//dc:4f:22:0a:16:ce
static const char blacklisted_macs[10][6] = {
  {0x2C, 0x3A, 0xE8, 0x36, 0x06, 0x10},
  {0x2C, 0x3A, 0xE8, 0x1B, 0x53, 0x75},
  {0x5C, 0xCF, 0x7F, 0x69, 0x08, 0x3D},
  {0x5C, 0xCF, 0x7F, 0x69, 0x11, 0x04},
  {0x5C, 0xCF, 0x7F, 0x69, 0x16, 0xC7},
  {0x5C, 0xCF, 0x7F, 0x69, 0x16, 0xCA},
  {0x5C, 0xCF, 0x7F, 0x69, 0x0C, 0xED},
  {0xDC, 0x4F, 0x22, 0x0A, 0x05, 0x82},
  {0xDC, 0x4F, 0x22, 0x0A, 0x12, 0xB0},
  {0xDC, 0x4F, 0x22, 0x0A, 0x16, 0xCE}
};

void wifi_sniffer_packet_handler(uint8_t *buff, uint16_t len)
{
  // First layer: type cast the received buffer into our generic SDK structure
  const wifi_promiscuous_pkt_t *ppkt = (wifi_promiscuous_pkt_t *)buff;
  // Second layer: define pointer to where the actual 802.11 packet is within the structure
  const wifi_ieee80211_packet_t *ipkt = (wifi_ieee80211_packet_t *)ppkt->payload;
  // Third layer: define pointers to the 802.11 packet header and payload
  const wifi_ieee80211_mac_hdr_t *hdr = &ipkt->hdr;

  if (memcmp(hdr->addr1, ap_mac, 6) == 0)
  {

    for (uint8_t i = 0; i < 10; i++)
    {
      if (memcmp(hdr->addr2, blacklisted_macs[i], 6) == 0) return;
    }

    const uint8_t * ptr = hdr->addr2;

    Serial.printf("%02X:%02X:%02X:%02X:%02X:02X %i\r\n", ptr[0], ptr[1], ptr[2], ptr[3], ptr[4], ptr[5], -ppkt->rx_ctrl.rssi);
  }
}

void setup() {
  Serial.begin(9600);

  //Set station mode, callback, then cycle promisc. mode
  wifi_set_opmode(STATION_MODE);
  wifi_promiscuous_enable(0);

  wifi_set_promiscuous_rx_cb(wifi_sniffer_packet_handler);
  wifi_promiscuous_enable(1);
  wifi_set_channel(7);

  Serial.println("\n\n\rSetup Complete ...");
}

void loop() {
  delay(10);
}

#include <esp_now.h>
#include <WiFi.h>
#include "common.h"
#include "CRSFHandset.h"
#include "UnusedPeriph.h"

/***** TODO! Adjust the values in this section to YOUR setup! *****/

// Model receiver's MAC address (replace with YOUR CyberBrick receiver Core MAC address: aa:bb:cc:dd:ee:ff!)
uint8_t cyberbrickRxMAC[] = {0xaa, 0xbb, 0xcc, 0xdd, 0xee, 0xff};

#define WIFI_CHANNEL 1 // Change to a channel your model's CyberBrick Core MicroPython code is configured to!
                        // Valid range 1 to 11

/******************************************/

// The following is replied in a CRSF ping response telegram to the handset and
// displayed as a module identification in EdgeTX under:
// System -> About -> Modules / RX version
const char device_name[] = "CyberBrick TX"; // max. 16 characters
char versionID[] = "1.0.0";

// Current state of channels, CRSF format
volatile uint16_t ChannelData[CRSF_NUM_CHANNELS];

CRSFHandset *handset = new CRSFHandset();
esp_now_peer_info_t peerInfo;

bool SendRCdataToRF();
bool initESPNOW();
void ESPNOW_OnDataSentCB(const uint8_t *mac_addr, esp_now_send_status_t status);

// Initialization
void setup() {
  pinMode(GPIO_PIN_BOOT0, INPUT); // setup so that we can detect pin-change for passthrough mode of the optional ExpressLRS module backpack
  initUnusedDevices();
  handset->Begin();
  while (!initESPNOW()) {}
}

// Main execution loop
void loop() {
  handset->handleInput();
  SendRCdataToRF();
  delay((uint32_t)(RF_FRAME_RATE_US/1000));
}

bool initESPNOW()
{
  WiFi.mode(WIFI_STA);
  WiFi.setChannel(WIFI_CHANNEL, WIFI_SECOND_CHAN_NONE);
  WiFi.setTxPower(WIFI_POWER_19_5dBm);
  while (!WiFi.STA.started()) {
    delay(100);
  }

  // Init ESP-NOW
  if (esp_now_init() != ESP_OK) return false;

  // Register callback to get the status of the transmitted ESP-NOW packet
  while (esp_now_register_send_cb(ESPNOW_OnDataSentCB) != ESP_OK) return false;

  // Register peer
  memcpy(peerInfo.peer_addr, cyberbrickRxMAC, 6);
  peerInfo.channel = WIFI_CHANNEL;
  peerInfo.encrypt = false;
  
  // Add peer
  if (esp_now_add_peer(&peerInfo) != ESP_OK){
    // Failed to add peer
    return false;
  }
  return true;
}

bool SendRCdataToRF()
{
  // Send message via ESP-NOW
  esp_err_t result = esp_now_send(cyberbrickRxMAC, (uint8_t *) &ChannelData, sizeof(ChannelData));
   
  if (result != ESP_OK) {
    return false;
  }
  return true;
}

// ESP-NOW callback, called when data is sent
void ESPNOW_OnDataSentCB(const uint8_t *mac_addr, esp_now_send_status_t status) {
  if (status == ESP_NOW_SEND_SUCCESS)
  {
    handset->JustSentRFpacket();
  }
}
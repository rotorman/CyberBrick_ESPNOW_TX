/*
 * This file belongs to the CyberBrick ESP-NOW transmitter & receiver project, hosted originally at:
 * https://github.com/rotorman/CyberBrick_ESPNOW
 * Copyright (C) 2025, Risto Kõiva
 *
 * Large parts of the code are based on the wonderful ExpressLRS project:
 * https://github.com/ExpressLRS/ExpressLRS and https://github.com/ExpressLRS/targets
 *
 * License GPL-3.0: https://www.gnu.org/licenses/gpl-3.0.html
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#include <esp_now.h>
#include <WiFi.h>
#include "common.h"
#include "CRSFHandset.h"
#include "UnusedPeriph.h"
#include "hwTimer.h"

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
connectionState_e connectionState = awatingFirstPacket;

CRSFHandset *handset = new CRSFHandset();
esp_now_peer_info_t peerInfo;

bool SendRCdataToRF();
void timerCallback();
bool initESPNOW();
void ESPNOW_OnDataSentCB(const uint8_t *mac_addr, esp_now_send_status_t status);
static void UARTconnected();
static void UARTdisconnected();
void ModelUpdateReq();

// Initialization
void setup() {
  pinMode(GPIO_PIN_BOOT0, INPUT); // setup so that we can detect pin-change for passthrough mode of the optional ExpressLRS module backpack
  initUnusedDevices();
  handset->Begin();
  handset->registerCallbacks(UARTconnected, UARTdisconnected, ModelUpdateReq);

  while (!initESPNOW()) {}
  hwTimer::init(timerCallback);
  hwTimer::updateIntervalUS(RF_FRAME_RATE_US);
  setConnectionState(awatingFirstPacket);
}

// Main execution loop
void loop() {
  handset->handleInput();
  delay(1); // yield
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

/*
 * Called from timer ISR when there is a CRSF connection from the handset
 */
void ICACHE_RAM_ATTR timerCallback()
{
  // Do not transmit until in disconnected/connected state
  if (connectionState == awaitingModelId)
    return;

  SendRCdataToRF();
}

bool ICACHE_RAM_ATTR SendRCdataToRF()
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

static void UARTdisconnected()
{
  hwTimer::stop();
  setConnectionState(disconnected);
}

static void UARTconnected()
{
  if (connectionState == disconnected)
    setConnectionState(connected);

  if (connectionState == awatingFirstPacket)
  {
    // When CRSF first connects, always go into a brief delay before
    // starting to transmit, to make sure a ModelID update isn't coming
    // right behind it
    setConnectionState(awaitingModelId);
  }

  // Start the timer to get EdgeTX sync going and a ModelID update sent
  hwTimer::resume();
}

void ModelUpdateReq()
{
  if (connectionState == awaitingModelId)
  {
    setConnectionState(connected);
  }
}

#include "common.h"
#include "CRSFHandset.h"
#include "UnusedPeriph.h"

// Current state of channels, CRSF format
uint32_t ChannelData[CRSF_NUM_CHANNELS];

CRSFHandset *handset = new CRSFHandset();

// Initialization
void setup() {
  pinMode(GPIO_PIN_BOOT0, INPUT); // setup so that we can detect pin-change for passthrough mode of the optional ExpressLRS module backpack
  initUnusedDevices();
  handset->Begin();
}

// Main execution loop
void loop() {
  handset->handleInput();
  delay(20);
}

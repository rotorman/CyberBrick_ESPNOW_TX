#pragma once
#include <Arduino.h>

#undef ICACHE_RAM_ATTR //fix to allow both esp32 and esp8266 to use ICACHE_RAM_ATTR for mapping to IRAM
#define ICACHE_RAM_ATTR IRAM_ATTR

#define GPIO_PIN_BOOT0 0
#define CRSF_NUM_CHANNELS 16U
#define RF_FRAME_RATE_US 20000U // 50 Hz

extern volatile uint16_t ChannelData[CRSF_NUM_CHANNELS]; // Current state of channels, CRSF format

// I/O definitions for Jumper Gemini T-20 internal ExpressLRS modules with ESP32 main MCU
// https://www.jumper-rc.com/transmitters/
// The configuration stems from https://github.com/ExpressLRS/targets/blob/master/TX/Generic%202400%20Gemini.json

#ifndef MODULE_IO_DEFINITIONS_H
#define MODULE_IO_DEFINITIONS_H

// Communication with the handset
#define GPIO_PIN_RCSIGNAL_RX_IN 3
#define GPIO_PIN_RCSIGNAL_TX_OUT 1

// Radio module 1
#define GPIO_PIN_RADIO_BUSY_IN 36
#define GPIO_PIN_RADIO_DIO1_IN 37
#define GPIO_PIN_RADIO_NRST_OUT 26
#define GPIO_PIN_RADIO_SPI_NSS_OUT 27

// Radio module 2
#define GPIO_PIN_RADIO2_BUSY_IN 39
#define GPIO_PIN_RADIO2_DIO1_IN 34
#define GPIO_PIN_RADIO2_NRST_OUT 21
#define GPIO_PIN_RADIO2_SPI_NSS_OUT 13

// Radio SPI-bus
#define GPIO_PIN_RADIO_SPI_MISO_IN 33
#define GPIO_PIN_RADIO_SPI_MOSI_OUT 32
#define GPIO_PIN_RADIO_SPI_SCK_OUT 25

// Radio power control
#define GPIO_PIN_RADIOPA_EN_OUT 25
#define GPIO_PIN_RADIOPWR_RX_EN_OUT 10
#define GPIO_PIN_RADIOPWR_TX_EN_OUT 14
#define GPIO_PIN_RADIO2PWR_RX_EN_OUT 9
#define GPIO_PIN_RADIO2PWR_TX_EN_OUT 15

// Backpack
#define GPIO_PIN_BACKPACK_RX_IN 18
#define GPIO_PIN_BACKPACK_TX_OUT 5
#define GPIO_PIN_BACKPACK_BOOT_OUT 23
#define GPIO_PIN_BACKPACK_EN_OUT 19
#define BACKPACK_BAUD 460800

// User-interface
#define GPIO_PIN_LED_RGB_OUT 22

// Miscellaneous
#define GPIO_PIN_MISC_FAN_PWM_OUT 4

#endif // MODULE_IO_DEFINITIONS_H

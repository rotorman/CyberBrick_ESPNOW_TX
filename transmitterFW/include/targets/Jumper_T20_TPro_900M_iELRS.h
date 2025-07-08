// I/O definitions for Jumper AION T-20 and T-Pro internal 900 MHz ExpressLRS modules with ESP32 main MCU
// https://www.jumper-rc.com/transmitters/
// The configuration stems from https://github.com/ExpressLRS/targets/blob/master/TX/Jumper%20T-20%20900.json

#ifndef MODULE_IO_DEFINITIONS_H
#define MODULE_IO_DEFINITIONS_H

// Communication with the handset
#define GPIO_PIN_RCSIGNAL_RX_IN 3
#define GPIO_PIN_RCSIGNAL_TX_OUT 1

// Radio module
#define GPIO_PIN_RADIO_DIO0_IN 26
#define GPIO_PIN_RADIO_DIO1_IN 25
#define GPIO_PIN_RADIO_NRST_OUT 14
#define GPIO_PIN_RADIO_SPI_NSS_OUT 5

// Radio SPI-bus
#define GPIO_PIN_RADIO_SPI_MISO_IN 19
#define GPIO_PIN_RADIO_SPI_MOSI_OUT 23
#define GPIO_PIN_RADIO_SPI_SCK_OUT 18

// Radio power control
#define GPIO_PIN_RADIOPWR_RX_EN_OUT 13
#define GPIO_PIN_RADIOPWR_TX_EN_OUT 12

#endif // MODULE_IO_DEFINITIONS_H

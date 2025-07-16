// I/O definitions for RadioMaster Ranger Micro and Nano
// https://radiomasterrc.com/products/ranger-micro-2-4ghz-elrs-module
// https://radiomasterrc.com/products/ranger-nano-2-4ghz-elrs-module
// The configuration stems from https://github.com/ExpressLRS/targets/blob/master/TX/Radiomaster%20Ranger%20Micro.json

#ifndef MODULE_IO_DEFINITIONS_H
#define MODULE_IO_DEFINITIONS_H

// Communication with the handset
#define GPIO_PIN_RCSIGNAL_RX_IN 13
#define GPIO_PIN_RCSIGNAL_TX_OUT 13

// Radio module
#define GPIO_PIN_RADIO_BUSY_IN 22
#define GPIO_PIN_RADIO_DIO1_IN 21
#define GPIO_PIN_RADIO_NRST_OUT 5
#define GPIO_PIN_RADIO_SPI_NSS_OUT 4

// Radio SPI-bus
#define GPIO_PIN_RADIO_SPI_MISO_IN 19
#define GPIO_PIN_RADIO_SPI_MOSI_OUT 23
#define GPIO_PIN_RADIO_SPI_SCK_OUT 18

// Radio power control
#define GPIO_PIN_RADIOPWR_RX_EN_OUT 32
#define GPIO_PIN_RADIOPWR_TX_EN_OUT 33

// Backpack
#define GPIO_PIN_BACKPACK_RX_IN 16
#define GPIO_PIN_BACKPACK_TX_OUT 17
#define GPIO_PIN_BACKPACK_BOOT_OUT 26
#define GPIO_PIN_BACKPACK_EN_OUT 25
#define BACKPACK_BAUD 460800

// Miscellaneous
#define GPIO_PIN_FAN_EN_OUT 27

#endif // MODULE_IO_DEFINITIONS_H

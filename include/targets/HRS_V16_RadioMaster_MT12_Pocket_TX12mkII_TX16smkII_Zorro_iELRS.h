// I/O definitions for:
// * HelloRadioSky V16 with internal ExpressLRS module
//   https://www.helloradiosky.com/
// * RadioMaster MT12 with internal ExpressLRS module
//   https://radiomasterrc.com/products/mt12-surface-radio-controller
//   https://radiomasterrc.com/collections/mt12-accessories/products/mt12-expresslrs-module
// * RadioMaster Pocket with internal ExpressLRS module
//   https://radiomasterrc.com/products/pocket-radio-controller-m2
//   https://radiomasterrc.com/collections/pocket-accessories/products/elrs-module-for-zorro-and-tx12-mark-ii
// * RadioMaster TX12 mkII with internal ExpressLRS module
//   https://radiomasterrc.com/products/tx12-mark-ii-radio-controller
//   https://radiomasterrc.com/collections/pocket-accessories/products/elrs-module-for-zorro-and-tx12-mark-ii
// * RadioMaster TX16s mkII with internal ExpressLRS module
//   https://radiomasterrc.com/collections/tx16s-mark-ii
//   https://radiomasterrc.com/collections/tx16s-mkii-accessories/products/tx16s-mkii-elrs-module
// * RadioMaster Zorro with internal ExpressLRS module
//   https://radiomasterrc.com/products/zorro-radio-controller
//   https://radiomasterrc.com/collections/pocket-accessories/products/elrs-module-for-zorro-and-tx12-mark-ii
// The configuration stems from https://github.com/ExpressLRS/targets/blob/master/TX/Radiomaster%20Zorro.json and
// https://github.com/ExpressLRS/targets/blob/master/TX/Radiomaster%20TX16S%202400.json

#ifndef MODULE_IO_DEFINITIONS_H
#define MODULE_IO_DEFINITIONS_H

// Communication with the handset
#define GPIO_PIN_RCSIGNAL_RX_IN 3
#define GPIO_PIN_RCSIGNAL_TX_OUT 1

// Radio module
#define GPIO_PIN_RADIO_BUSY_IN 21
#define GPIO_PIN_RADIO_DIO1_IN 4
#define GPIO_PIN_RADIO_DIO2_IN 22
#define GPIO_PIN_RADIO_NRST_OUT 14
#define GPIO_PIN_RADIO_SPI_NSS_OUT 5

// Radio SPI-bus
#define GPIO_PIN_RADIO_SPI_MISO_IN 19
#define GPIO_PIN_RADIO_SPI_MOSI_OUT 23
#define GPIO_PIN_RADIO_SPI_SCK_OUT 18

// Radio power control
#define GPIO_PIN_RADIOPWR_RX_EN_OUT 27
#define GPIO_PIN_RADIOPWR_TX_EN_OUT 26
#define GPIO_PIN_RADIOPWR_PA_PDET_AIN 35

// Backpack
#define GPIO_PIN_BACKPACK_RX_IN 16
#define GPIO_PIN_BACKPACK_TX_OUT 17
#define GPIO_PIN_BACKPACK_BOOT_OUT 15
#define GPIO_PIN_BACKPACK_EN_OUT 25
#define BACKPACK_BAUD 460800

#endif // MODULE_IO_DEFINITIONS_H
// I/O definitions for HappyModel ES24 and ES24 Pro
// https://www.happymodel.cn/index.php/2021/04/12/happymodel-2-4g-expresslrs-elrs-micro-tx-module-es24tx/
// https://www.happymodel.cn/index.php/2021/11/11/happymodel-es24tx-pro-micro-expresslrs-elrs-tx-module/
// The configuration stems from https://github.com/ExpressLRS/targets/blob/master/TX/HappyModel%20ES24.json
// and https://github.com/ExpressLRS/targets/blob/master/TX/HappyModel%20ES24%20Pro.json

#ifndef MODULE_IO_DEFINITIONS_H
#define MODULE_IO_DEFINITIONS_H

// Communication with the handset
#define GPIO_PIN_RCSIGNAL_RX_IN 13
#define GPIO_PIN_RCSIGNAL_TX_OUT 13

// Radio module
#define GPIO_PIN_RADIO_BUSY_IN 21
#define GPIO_PIN_RADIO_DIO1_IN 4
#define GPIO_PIN_RADIO_NRST_OUT 14
#define GPIO_PIN_RADIO_SPI_NSS_OUT 5

// Radio SPI-bus
#define GPIO_PIN_RADIO_SPI_MISO_IN 19
#define GPIO_PIN_RADIO_SPI_MOSI_OUT 23
#define GPIO_PIN_RADIO_SPI_SCK_OUT 18

// Radio power control
#define GPIO_PIN_RADIOPWR_RX_EN_OUT 27
#define GPIO_PIN_RADIOPWR_TX_EN_OUT 26

// Backpack
#define GPIO_PIN_BACKPACK_RX_IN 3
#define GPIO_PIN_BACKPACK_TX_OUT 1
#define BACKPACK_BAUD 460800

// User-interface
#define GPIO_PIN_LED_RGB_OUT 15

// Miscellaneous
#define GPIO_PIN_MISC_FAN_PWM_OUT 17

#endif // MODULE_IO_DEFINITIONS_H

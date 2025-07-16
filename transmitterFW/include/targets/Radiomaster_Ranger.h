// I/O definitions for RadioMaster Ranger
// https://radiomasterrc.com/products/ranger-2-4ghz-elrs-module
// The configuration stems from https://github.com/ExpressLRS/targets/blob/master/TX/Radiomaster%20Ranger.json

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

// I2C-bus
#define GPIO_PIN_SCL_OUT 12
#define GPIO_PIN_SDA_INOUT 14

// User-interface
#define GPIO_PIN_LED_RGB_OUT 15
#define GPIO_PIN_SCREEN_SCK_OUT 12
#define GPIO_PIN_SCREEN_SDA_INOUT 14
#define GPIO_PIN_JOYSTICK_AIN 39
#define GPIO_PIN_BUTTON_IN 34
#define GPIO_PIN_USER_BUTTON_LED_OUT 0
#define GPIO_PIN_BUTTON2_IN 35
#define GPIO_PIN_USER_BUTTON2_LED_OUT 1

// Miscellaneous
#define GPIO_PIN_MISC_FAN_PWM_OUT 2
#define GPIO_PIN_FAN_TACHO_IN 27

#endif // MODULE_IO_DEFINITIONS_H

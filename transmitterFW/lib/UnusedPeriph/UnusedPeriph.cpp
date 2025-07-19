/*
 * This file belongs to the CyberBrick ESP-NOW transmitter & receiver project, hosted originally at:
 * https://github.com/rotorman/CyberBrick_ESPNOW
 * Copyright (C) 2025, Risto Kõiva
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

#include "common.h"
#include "UnusedPeriph.h"

void initUnusedDevices(void)
{
#if defined(GPIO_PIN_RADIOPA_EN_OUT)
    pinMode(GPIO_PIN_RADIOPA_EN_OUT, OUTPUT);
    digitalWrite(GPIO_PIN_RADIOPA_EN_OUT, LOW); // Keep RF PA off
#endif

#if defined(GPIO_PIN_RADIO_NRST_OUT)
    pinMode(GPIO_PIN_RADIO_NRST_OUT, OUTPUT);
    digitalWrite(GPIO_PIN_RADIO_NRST_OUT, LOW); // Keep radio in reset
#endif

#if defined(GPIO_PIN_RADIOPWR_TX_EN_OUT)
    pinMode(GPIO_PIN_RADIOPWR_TX_EN_OUT, OUTPUT);
    digitalWrite(GPIO_PIN_RADIOPWR_TX_EN_OUT, LOW); // Keep RF PA transmit off
#endif

#if defined(GPIO_PIN_RADIOPWR_RX_EN_OUT)
    pinMode(GPIO_PIN_RADIOPWR_RX_EN_OUT, OUTPUT);
    digitalWrite(GPIO_PIN_RADIOPWR_RX_EN_OUT, LOW); // Keep RF PA receive off
#endif

#if defined(GPIO_PIN_RADIO2PWR_TX_EN_OUT)
    pinMode(GPIO_PIN_RADIO2PWR_TX_EN_OUT, OUTPUT);
    digitalWrite(GPIO_PIN_RADIO2PWR_TX_EN_OUT, LOW); // Keep RF PA transmit off
#endif

#if defined(GPIO_PIN_RADIO2PWR_RX_EN_OUT)
    pinMode(GPIO_PIN_RADIO2PWR_RX_EN_OUT, OUTPUT);
    digitalWrite(GPIO_PIN_RADIO2PWR_RX_EN_OUT, LOW); // Keep RF PA receive off
#endif

#if defined(GPIO_PIN_RADIOPWR_PA_PDET_AIN)
    analogSetPinAttenuation(GPIO_PIN_RADIOPWR_PA_PDET_AIN, ADC_0db);
    analogRead(GPIO_PIN_RADIOPWR_PA_PDET_AIN);
#endif

#if defined(GPIO_PIN_RADIO_SPI_NSS_OUT)
    pinMode(GPIO_PIN_RADIO_SPI_NSS_OUT, OUTPUT);
    digitalWrite(GPIO_PIN_RADIO_SPI_NSS_OUT, HIGH); // RF chip ChipSelect is low active, keep inactive
#endif

#if defined(GPIO_PIN_RADIO2_SPI_NSS_OUT)
    pinMode(GPIO_PIN_RADIO2_SPI_NSS_OUT, OUTPUT);
    digitalWrite(GPIO_PIN_RADIO2_SPI_NSS_OUT, HIGH); // RF chip ChipSelect is low active, keep inactive
#endif

#if defined(GPIO_PIN_RADIO_SPI_MOSI_OUT)
    pinMode(GPIO_PIN_RADIO_SPI_MOSI_OUT, OUTPUT);
    digitalWrite(GPIO_PIN_RADIO_SPI_MOSI_OUT, LOW);
#endif

#if defined(GPIO_PIN_RADIO_SPI_SCK_OUT)
    pinMode(GPIO_PIN_RADIO_SPI_SCK_OUT, OUTPUT);
    digitalWrite(GPIO_PIN_RADIO_SPI_SCK_OUT, LOW); // SPI mode 0 (CPOL=0, CPHA=0) default state is low
#endif

#if defined(GPIO_PIN_RADIO_SPI_MISO_IN)
    pinMode(GPIO_PIN_RADIO_SPI_MISO_IN, INPUT);
#endif

#if defined(GPIO_PIN_RADIO_BUSY_IN)
    pinMode(GPIO_PIN_RADIO_BUSY_IN, INPUT);
#endif

#if defined(GPIO_PIN_RADIO_DIO0_IN)
    pinMode(GPIO_PIN_RADIO_DIO0_IN, INPUT);
#endif

#if defined(GPIO_PIN_RADIO_DIO1_IN)
    pinMode(GPIO_PIN_RADIO_DIO1_IN, INPUT);
#endif

#if defined(GPIO_PIN_RADIO_DIO2_IN)
    pinMode(GPIO_PIN_RADIO_DIO2_IN, INPUT);
#endif

#if defined(GPIO_PIN_RADIO2_BUSY_IN)
    pinMode(GPIO_PIN_RADIO2_BUSY_IN, INPUT);
#endif

#if defined(GPIO_PIN_RADIO2_DIO1_IN)
    pinMode(GPIO_PIN_RADIO2_DIO1_IN, INPUT);
#endif

#if defined(GPIO_PIN_RADIO2_DIO2_IN)
    pinMode(GPIO_PIN_RADIO2_DIO2_IN, INPUT);
#endif

#if defined(GPIO_PIN_BACKPACK_EN_OUT)
    pinMode(GPIO_PIN_BACKPACK_EN_OUT, OUTPUT);
    digitalWrite(GPIO_PIN_BACKPACK_EN_OUT, LOW); // Turn backpack off
#endif

#if defined(GPIO_PIN_BACKPACK_BOOT_OUT)
    pinMode(GPIO_PIN_BACKPACK_BOOT_OUT, OUTPUT);		
    digitalWrite(GPIO_PIN_BACKPACK_BOOT_OUT, LOW); // Do not put Backpack into bootloader mode
#endif

#if defined(GPIO_PIN_BACKPACK_TX_OUT)
    pinMode(GPIO_PIN_BACKPACK_TX_OUT, OUTPUT);
    digitalWrite(GPIO_PIN_BACKPACK_TX_OUT, LOW);
#endif

#if defined(GPIO_PIN_BACKPACK_RX_IN)
    pinMode(GPIO_PIN_BACKPACK_RX_IN, INPUT);
#endif

#if defined(GPIO_PIN_MISC_FAN_PWM_OUT)
    pinMode(GPIO_PIN_MISC_FAN_PWM_OUT, OUTPUT);
    digitalWrite(GPIO_PIN_MISC_FAN_PWM_OUT, LOW);
#endif

#if defined(GPIO_PIN_FAN_EN_OUT)
    pinMode(GPIO_PIN_FAN_EN_OUT, OUTPUT);
    digitalWrite(GPIO_PIN_FAN_EN_OUT, LOW);
#endif

#if defined(GPIO_PIN_FAN_TACHO_IN)
    pinMode(GPIO_PIN_FAN_TACHO_IN, INPUT);
#endif

#if defined(GPIO_PIN_LED_RGB_OUT)
    pinMode(GPIO_PIN_LED_RGB_OUT, OUTPUT);
    digitalWrite(GPIO_PIN_LED_RGB_OUT, LOW);
#endif

#if defined(GPIO_PIN_SCL_OUT)
    pinMode(GPIO_PIN_SCL_OUT, OUTPUT_OPEN_DRAIN | PULLUP);
    digitalWrite(GPIO_PIN_SCL_OUT, HIGH);
#endif

#if defined(GPIO_PIN_SDA_INOUT)
    pinMode(GPIO_PIN_SDA_INOUT, OUTPUT_OPEN_DRAIN | PULLUP);
    digitalWrite(GPIO_PIN_SDA_INOUT, HIGH);
#endif

#if defined(GPIO_PIN_SCREEN_SCK_OUT)
    pinMode(GPIO_PIN_SCREEN_SCK_OUT, OUTPUT_OPEN_DRAIN | PULLUP);
    digitalWrite(GPIO_PIN_SCREEN_SCK_OUT, HIGH);
#endif

#if defined(GPIO_PIN_SCREEN_SDA_INOUT)
    pinMode(GPIO_PIN_SCREEN_SDA_INOUT, OUTPUT_OPEN_DRAIN | PULLUP);
    digitalWrite(GPIO_PIN_SCREEN_SDA_INOUT, HIGH);
#endif

#if defined(GPIO_PIN_JOYSTICK_AIN)
    analogRead(GPIO_PIN_JOYSTICK_AIN);
#endif

#if defined(GPIO_PIN_BUTTON_IN)
    pinMode(GPIO_PIN_BUTTON_IN, INPUT);
#endif

#if defined(GPIO_PIN_USER_BUTTON_LED_OUT)
    pinMode(GPIO_PIN_USER_BUTTON_LED_OUT, OUTPUT);
    digitalWrite(GPIO_PIN_USER_BUTTON_LED_OUT, LOW);
#endif

#if defined(GPIO_PIN_BUTTON2_IN)
    pinMode(GPIO_PIN_BUTTON2_IN, INPUT);
#endif

#if defined(GPIO_PIN_USER_BUTTON2_LED_OUT)
    pinMode(GPIO_PIN_USER_BUTTON2_LED_OUT, OUTPUT);
    digitalWrite(GPIO_PIN_USER_BUTTON2_LED_OUT, LOW);
#endif
}

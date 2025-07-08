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

#if defined(GPIO_PIN_LED_RGB_OUT)
    pinMode(GPIO_PIN_LED_RGB_OUT, OUTPUT);
    digitalWrite(GPIO_PIN_LED_RGB_OUT, LOW);
#endif
}

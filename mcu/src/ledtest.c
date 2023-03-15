#include <string.h>
#include "global.h"

#define LED_MASK_0 0b11000000
#define LED_MASK_1 0b11111100
#define LED_RNSIZE (((8*UART_BUFSIZE)*2))
#define LED_TXSIZE (LED_RNSIZE+2)

uint8_t txbuf[LED_TXSIZE];

void leds_test(uint8_t n) {
	memset(txbuf, LED_MASK_0, LED_TXSIZE);
	memset(txbuf, LED_MASK_1, n*24);
	HAL_SPI_Transmit(&hspi, txbuf, LED_TXSIZE, HAL_MAX_DELAY);
}

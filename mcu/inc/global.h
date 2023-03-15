#ifndef VS_GLOBAL
#define VS_GLOBAL

#include "stm32f4xx_hal.h"
#define LEDCOUNT (128)
#define UART_BUFSIZE (3*LEDCOUNT)

UART_HandleTypeDef huart;
SPI_HandleTypeDef hspi;

uint8_t uartrx;
uint8_t uartbuf[UART_BUFSIZE];

void init_hardware();
void init_uart();
void init_spi();

void leds_tx();
void leds_test(uint8_t);

#endif

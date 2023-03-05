/**
  ******************************************************************************
  * @file    main.c
  * @author  Ac6
  * @version V1.0
  * @date    01-December-2013
  * @brief   Default main function.
  ******************************************************************************
*/


#include "stm32f4xx.h"
#include "stm32f4xx_nucleo.h"

#include "global.h"

int main(void)
{
	init_hardware();
	uartrx = 0;

	while (1) {
		HAL_UART_Receive_IT(&huart, uartbuf, UART_BUFSIZE);
		if (uartrx) {
			leds_tx();
		}
	}
}

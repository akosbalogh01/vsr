#include "stm32f4xx_hal.h"
#include "global.h"

void USART2_IRQHandler(void) {
	HAL_UART_IRQHandler(&huart);
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef* uartHandle) {
	if (uartHandle->Instance == USART2) {
		uartrx = 1;
	}
}

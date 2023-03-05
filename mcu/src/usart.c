#include "global.h"

#define USART_TX_Pin GPIO_PIN_2
#define USART_RX_Pin GPIO_PIN_3

void init_uart() {
	huart.Instance = USART2;
	huart.Init.BaudRate 	= 1000000;
	huart.Init.HwFlowCtl 	= UART_HWCONTROL_NONE;
	huart.Init.Mode 		= UART_MODE_TX_RX;
	huart.Init.OverSampling	= UART_OVERSAMPLING_16;
	huart.Init.Parity 		= UART_PARITY_NONE;
	huart.Init.StopBits 	= UART_STOPBITS_1;
	huart.Init.WordLength 	= UART_WORDLENGTH_8B;

	HAL_UART_Init(&huart);
}

void HAL_UART_MspInit(UART_HandleTypeDef* uartHandle)
{
	GPIO_InitTypeDef GPIO_InitStruct = {0};
	if(uartHandle->Instance==USART2)
	{
		__HAL_RCC_USART2_CLK_ENABLE();

		__HAL_RCC_GPIOA_CLK_ENABLE();

		GPIO_InitStruct.Pin = USART_TX_Pin|USART_RX_Pin;
		GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
		GPIO_InitStruct.Pull = GPIO_PULLUP;
		GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
		GPIO_InitStruct.Alternate = GPIO_AF7_USART2;
		HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

		HAL_NVIC_SetPriority(USART2_IRQn, 0, 0);
		HAL_NVIC_EnableIRQ(USART2_IRQn);
	}
}

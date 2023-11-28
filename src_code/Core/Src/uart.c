/*
 * uart.c
 *
 *  Created on: Nov 28, 2023
 *      Author: dinhq
 */

#include "uart.h"

void sendUART(){
	char str[100];
	HAL_UART_Transmit(&huart2, (void*)str, sprintf(str,"!TimerRoad1=%d#\r\n",timerRoad1), 100);
}

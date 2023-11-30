/*
 * buzzer.c
 *
 *  Created on: Nov 23, 2023
 *      Author: takudo
 */

#include "buzzer.h"
#include <math.h>
//extern int r_val;
//int timerRoad1;
void startBuzzer(){
	if(timer3_flag){
		double temp = (1-(double)timerRoad1/r_val)*10;
		char str[100];
		int res = (int)round(temp);
		HAL_UART_Transmit(&huart2, (void*)str, sprintf(str,"!RES=%d#\r\n",res), 100);
		if (sig) __HAL_TIM_SetCompare (&htim3,TIM_CHANNEL_1,res);
		else __HAL_TIM_SetCompare (&htim3,TIM_CHANNEL_1,0);
		sig = 1 - sig;
		double temp1 = ((double)timerRoad1/r_val)*10;
		int timeBuz = (int)round(temp1);
		setTimer3(timeBuz*10);
	}
}

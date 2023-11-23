/*
 * buzzer.c
 *
 *  Created on: Nov 23, 2023
 *      Author: takudo
 */

#include "buzzer.h"

//extern int r_val;
//int timerRoad1;
void startBuzzer(){
	if(timer3_flag){
		int temp = (1-(double)(timerRoad1/r_val))*mul;
		mul+=5;
		if (sig) __HAL_TIM_SetCompare (&htim3,TIM_CHANNEL_1,temp);
		else __HAL_TIM_SetCompare (&htim3,TIM_CHANNEL_1,0);
		sig = 1 - sig;
		setTimer3(5);
	}
}

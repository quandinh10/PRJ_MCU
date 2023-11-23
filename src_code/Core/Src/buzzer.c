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
	if(buzzerFlag){
		//chay
	__HAL_TIM_SetCompare (&htim3,TIM_CHANNEL_1,(1-(timerRoad1/r_val)*100));
	if(timer3_flag==1)
		setTimer3((timerRoad1/r_val)*500);
	__HAL_TIM_SetCompare (&htim3,TIM_CHANNEL_1,0);
	if(timer3_flag==1)
		setTimer3((timerRoad1/r_val)*500);
	}
}

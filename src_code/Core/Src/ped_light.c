/*
 * ped_light.c
 *
 *  Created on: Nov 13, 2023
 *      Author: Admin
 */


#include "ped_light.h"

// Change sig name later
// Traffic ped status
void pedestrian_light_fsm(){
	switch (sig){
	case WAIT:
		// 3 for PED 1
		if (isButtonPressed(3)){
			sig = ON1;
			allowed = 0;
			setTimer8(1000);
		}
		break;
	case ON:
		HAL_GPIO_WritePin(PET_LED_GPIO_Port, PET_LED_Pin, RESET);
		onRed1();
		onGreen2();
		if (timer8_flag){
			sig = OFF;
			allowed = 1;
		}
		break;
	case OFF:
		offRed1();
		offGreen2();
		HAL_GPIO_WritePin(PET_LED_GPIO_Port, PET_LED_Pin, SET);
		sig = WAIT;
		break;
	default:
		break;
	}
}

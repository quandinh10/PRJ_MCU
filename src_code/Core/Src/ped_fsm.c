/*
 * ped_fsm.c
 *
 *  Created on: Nov 13, 2023
 *      Author: Admin
 */

#include "ped_fsm.h"

void ped_fsm(){
	if (isButtonPressed(3)) pedestrian_manual_fsm();
	switch(ped_status){
	case OFF:
		pedOff();
		__HAL_TIM_SetCompare (&htim3,TIM_CHANNEL_1,0);
		break;
	case RED:
		pedRed();
		if (led_status == RED_GREEN || led_status == RED_YELLOW) ped_status = GREEN;
		break;
	case GREEN:
		startBuzzer();
		pedGreen();
		if (led_status == GREEN_RED || led_status == YELLOW_RED) ped_status = OFF;
		break;
	}
}

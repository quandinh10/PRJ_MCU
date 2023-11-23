/*
 * ped_light.c
 *
 *  Created on: Nov 13, 2023
 *      Author: Admin
 */


#include "ped_manual.h"

// Change sig name later
// Traffic ped status
void pedestrian_manual_fsm(){
	if (led_status == RED_MAN || led_status == GREEN_MAN || led_status == YELLOW_MAN) return;
	switch (sig){
	case WAIT:
		// 3 for PED 1
		if (isButtonPressed(3)){
			sig = PED_ON;
			setTimer8(1000);
		}
		break;
	case PED_ON:
		if (timer8_flag){
			sig = WAIT;
			buzzerFlag = 0;
		}
	default:
		break;
	}
}

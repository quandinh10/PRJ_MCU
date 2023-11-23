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
	switch (sig){
	case WAIT:
		// 3 for PED 1
		if (isButtonPressed(3)){
			sig = PED_ON;
			setTimer8(1000);
		}
		break;
	case PED_ON:
		ped_fsm();
		if (timer8_flag) sig = WAIT;
	default:
		break;
	}
}

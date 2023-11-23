/*
 * ped_fsm.c
 *
 *  Created on: Nov 13, 2023
 *      Author: Admin
 */

#include "ped_fsm.h"

void ped_fsm(){
	switch(led_status){
	case RED_GREEN:
		if (sig == PED_ON){
			pedGreen();
			buzzerFlag = 1;
			setTimer3(50);
		}
		break;
	case GREEN_RED:
		buzzerFlag = 0;
		if (sig == PED_ON) pedRed();
		break;
	case YELLOW_RED:
		buzzerFlag = 0;
		if (sig == PED_ON) pedRed();
		break;
	default:
		break;
	}
}


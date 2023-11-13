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
			sig = GREEN;
			allowed = 0;
			setTimer8(1000);
		}
		break;
	case GREEN:
		pedGreen();
		onRed1();
		onGreen2();
		if (timer8_flag){
			sig = RED;
			allowed = 1;
		}
		break;
	case RED:
		offRed1();
		offGreen2();
		pedRed();
		sig = WAIT;
		break;
	default:
		break;
	}
}

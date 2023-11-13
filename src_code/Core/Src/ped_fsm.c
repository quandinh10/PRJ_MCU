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
		pedGreen();
		break;
	case GREEN_RED:
		pedRed();
		break;
	case YELLOW_RED:
		pedRed();
		break;
	default:
		break;
	}
}


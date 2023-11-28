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
	switch(led_status){
	case RED_GREEN:
		ped_status = GREEN;
		break;
	case RED_YELLOW:
		ped_status = GREEN;
		break;
	case GREEN_RED:
		ped_status = RED;
		break;
	case YELLOW_RED:
		ped_status = RED;
		break;
	default:
		break;
	}
}

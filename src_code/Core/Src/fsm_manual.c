/*
 * fsm_manual.c
 *
 *  Created on: Oct 15, 2023
 *      Author: dinhq
 */

#include "fsm_manual.h"

void fsm_manual_run(){
	switch(led_status){
	case RED_MAN:
		if (timer5_flag == 1){
			setTimer5(25);
			if (toogleFlag == 0){
				onRED1();
				onRED2();
			}
			else {
				offALL();
			}
			toogleFlag = 1 - toogleFlag;
		}
		if (isButtonPressed(1) == 1){
			r_inc++;
			timerRoad1++;
			if (r_inc >= 100) r_inc=2;
		}
		if (isButtonPressed(0) == 1){
			setTimer5(1);
			led_status = YELLOW_MAN;

			timerRoad1 = y_val;
			timerRoad2 = 3;
		}
		if (isButtonPressed(2) == 1){
			r_val=r_inc;
		}
		break;

	case YELLOW_MAN:
		if (timer5_flag == 1){
			setTimer5(25);
			if (toogleFlag == 0){
				onYELLOW1();
				onYELLOW2();
			}
			else {
				offALL();
			}
			toogleFlag = 1 - toogleFlag;
		}
		if (isButtonPressed(1) == 1){
			y_inc++;
			timerRoad1++;
			if (y_inc >= r_val) y_inc=1;
		}
		if (isButtonPressed(0) == 1){
			setTimer5(1);
			led_status = GREEN_MAN;

			timerRoad1 = g_val;
			timerRoad2 = 4;
		}
		if (isButtonPressed(2) == 1){
			y_val=y_inc;
		}
		break;

	case GREEN_MAN:
		if (timer5_flag == 1){
			setTimer5(25);
			if (toogleFlag == 0){
				onGREEN1();
				onGREEN2();
			}
			else {
				offALL();
			}
			toogleFlag = 1 - toogleFlag;
		}
		if (isButtonPressed(1) == 1){
			g_inc++;
			timerRoad1++;
			if (g_inc >= r_val) g_inc=1;
		}
		if (isButtonPressed(0) == 1){
			led_status = RED_GREEN;
			g_val = r_val-y_val;
			timerRoad1 = r_val;
			timerRoad2 = g_val;
			setTimer1(g_val*100);
			setTimer2(100);
		}
		if (isButtonPressed(2) == 1){
			g_val=g_inc;
			y_val=r_val-g_val;
		}
		break;

	default:
		break;
	}
}

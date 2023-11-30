/*
 * traffic_no_time.c
 *
 *  Created on: Nov 30, 2023
 *      Author: dinhq
 */

#include "traffic_no_time.h"

void traffic_no_time(){
	switch(led_status){
	case RED_GREEN_NO_TIME:
		onRED1();
		onGREEN2();

		if (isButtonPressed(1)){
			offALL();
			led_status = RED_GREEN;
			timerRoad1 = r_val;
			timerRoad2 = g_val;
			setTimer1(g_val*100);
			setTimer2(100);
		}
		break;
	case RED_YELLOW_NO_TIME:
		onRED1();
		onYELLOW2();

		if (isButtonPressed(1)){
			offALL();
			led_status = RED_YELLOW;
			timerRoad1 = y_val;
			timerRoad2 = y_val;
			setTimer1(y_val*100);
			setTimer2(100);
		}
		break;
	case GREEN_RED_NO_TIME:
		onGREEN1();
		onRED2();

		if (isButtonPressed(1)){
			offALL();
			led_status = GREEN_RED;
			timerRoad1 = g_val;
			timerRoad2 = r_val;
			setTimer1(g_val*100);
			setTimer2(100);
		}
		break;
	case YELLOW_RED_NO_TIME:
		onYELLOW1();
		onRED2();

		if (isButtonPressed(1)){
			offALL();
			led_status = YELLOW_RED;
			timerRoad1 = y_val;
			timerRoad2 = y_val;
			setTimer1(y_val*100);
			setTimer2(100);
		}
		break;
	}
}

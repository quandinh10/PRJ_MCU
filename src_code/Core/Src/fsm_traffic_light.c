/*
 * fsm_traffic_light.c
 *
 *  Created on: Oct 15, 2023
 *      Author: dinhq
 */

#include "fsm_traffic_light.h"

// Allowed signal

void fsm_traffic_light(){
	switch(led_status){
	case INIT:
		//TODO
		offALL();

		//INIT state
		led_status = RED_GREEN;
		setTimer1(g_val*100);
		setTimer2(100);
		break;
	case RED_GREEN:
		//decrement of counter of each road
		if (timer2_flag == 1){
			setTimer2(100);
			timerRoad1--;
			timerRoad2--;
			if (timerRoad2 <= 0) timerRoad2 = y_val;
		}

		//update state
		if (timer1_flag == 1){
			setTimer1(y_val*100);
			led_status = RED_YELLOW;
		}

		if (isButtonPressed(0)){
			offALL();
			led_status = RED_MAN;
			setTimer5(1);

			timerRoad1 = r_val;
			timerRoad2 = 2;

			//reset button flag
			resetButton();
		}
		break;
	case RED_YELLOW:
		//decrement of counter of each road
		if (timer2_flag == 1){
			setTimer2(100);
			timerRoad1--;
			if (timerRoad1 <= 0) timerRoad1 = g_val;
			timerRoad2--;
			if (timerRoad2 <= 0) timerRoad2 = r_val;
		}

		//update state
		if(timer1_flag == 1){
			setTimer1(g_val*100);
			led_status = GREEN_RED;
		}

		if (isButtonPressed(0)){
			offALL();
			led_status = RED_MAN;
			setTimer5(1);

			timerRoad1 = r_val;
			timerRoad2 = 2;

			//reset button flag
			resetButton();
		}
		break;
	case GREEN_RED:
		//decrement of counter of each road
		if (timer2_flag == 1){
			setTimer2(100);
			timerRoad1--;
			if (timerRoad1 <= 0) timerRoad1 = y_val;
			timerRoad2--;
		}

		//update state
		if(timer1_flag == 1){
			setTimer1(y_val*100);
			led_status = YELLOW_RED;
		}

		if (isButtonPressed(0)){
			offALL();
			led_status = RED_MAN;
			setTimer5(1);

			timerRoad1 = r_val;
			timerRoad2 = 2;

			//reset button flag
			resetButton();
		}
		break;
	case YELLOW_RED:
		//decrement of counter of each road
		if (timer2_flag == 1){
			setTimer2(100);
			timerRoad1--;
			if (timerRoad1 <= 0) timerRoad1 = r_val;
			timerRoad2--;
			if (timerRoad2 <= 0) timerRoad2 = g_val;
		}

		//update state
		if (timer1_flag == 1){
			setTimer1(g_val*100);
			led_status = RED_GREEN;
		}

		if (isButtonPressed(0)){
			offALL();
			led_status = RED_MAN;
			setTimer5(1);

			timerRoad1 = r_val;
			timerRoad2 = 2;

			//reset button flag
			resetButton();
		}
		break;
	default:
		break;
	}
//	//check mode (timer5 for toogle LED)
//	if (isButtonPressed(0) == 1 && (led_status == RED_GREEN || led_status == RED_YELLOW || led_status == GREEN_RED || led_status == YELLOW_RED)){
//		offALL();
//		led_status = RED_MAN;
//		setTimer5(1);
//
//		timerRoad1 = r_val;
//		timerRoad2 = 2;
//
//		//reset button flag
//		resetButton();
//	}
}

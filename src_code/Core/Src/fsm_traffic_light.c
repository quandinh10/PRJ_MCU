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
		//TODO
		if (allowed){
			onRED1();
			onGREEN2();
		}

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
		break;
	case RED_YELLOW:
		//TODO
		if (allowed){
			onRED1();
			onYELLOW2();
		}

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
		break;
	case GREEN_RED:
		if (allowed){
			onGREEN1();
			onRED2();
		}

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
		break;
	case YELLOW_RED:
		if (allowed){
			onYELLOW1();
			onRED2();
		}

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
		break;
	default:
		break;
	}
	//check mode (timer5 for toogle LED)
	if (isButtonPressed(0) == 1 && (led_status == RED_GREEN || led_status == RED_YELLOW || led_status == GREEN_RED || led_status == YELLOW_RED)){
		offALL();
		led_status = RED_MAN;
		r_inc = r_val;
		y_inc = y_val;
		g_inc = g_val;
		setTimer5(1);

		timerRoad1 = r_val;
		timerRoad2 = 2;
	}
}

/*
 * global.h
 *
 *  Created on: Oct 15, 2023
 *      Author: dinhq
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "main.h"
#include "software_timer.h"
#include "button.h"
#include "physical.h"
#include "scheduler.h"
#include "uart.h"
#include <string.h>
#include <stdio.h>
//fsm
#define INIT 0
#define RED_GREEN 1
#define RED_YELLOW 2
#define GREEN_RED 3
#define YELLOW_RED 4

#define RED_MAN 12
#define GREEN_MAN 13
#define YELLOW_MAN 14

#define RED 15
#define GREEN 16
#define OFF 17
#define PED_ON 18
#define WAIT 19

#define RED_GREEN_NO_TIME 25
#define RED_YELLOW_NO_TIME 27
#define GREEN_RED_NO_TIME 26
#define YELLOW_RED_NO_TIME 28

extern int led_status;
extern int r_val;
extern int g_val;
extern int y_val;

extern int r_inc;
extern int g_inc;
extern int y_inc;

extern int toogleFlag;
//7seg
extern int timerRoad1;
extern int timerRoad2;

//ped purpose
extern int mul;
extern int sig;
extern int buzzerFlag;
extern int ped_status;

extern TIM_HandleTypeDef htim3;
extern UART_HandleTypeDef huart2;
#endif /* INC_GLOBAL_H_ */

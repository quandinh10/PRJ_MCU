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
#define RED_PED_MAN 17
#define GREEN_PED_MAN 18
#define WAIT 19

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
extern int allowed;
extern int sig;

extern TIM_HandleTypeDef htim3;

#endif /* INC_GLOBAL_H_ */

/*
 * task.c
 *
 *  Created on: Nov 1, 2023
 *      Author: dinhq
 */

#include "task.h"

void REDtoogle(){
	HAL_GPIO_TogglePin(LED1_GPIO_Port, LED1_Pin);
}

void GREEN_ON(){
	HAL_GPIO_WritePin(LED2_GPIO_Port, LED2_Pin, RESET);
}

void GREENtoogle(){
	HAL_GPIO_TogglePin(LED3_GPIO_Port, LED3_Pin);
}

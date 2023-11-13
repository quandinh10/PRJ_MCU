/*
 * physical.c
 *
 *  Created on: Oct 23, 2023
 *      Author: dinhq
 */

#include "physical.h"

void onGREEN1(){
	HAL_GPIO_WritePin(LED1_1_GPIO_Port, LED1_1_Pin, RESET);
	HAL_GPIO_WritePin(LED1_2_GPIO_Port, LED1_2_Pin, SET);
};
void onYELLOW1(){
	HAL_GPIO_WritePin(LED1_1_GPIO_Port, LED1_1_Pin, SET);
	HAL_GPIO_WritePin(LED1_2_GPIO_Port, LED1_2_Pin, SET);
};
void onRED1(){
	HAL_GPIO_WritePin(LED1_1_GPIO_Port, LED1_1_Pin, SET);
	HAL_GPIO_WritePin(LED1_2_GPIO_Port, LED1_2_Pin, RESET);
};

void onGREEN2(){
	HAL_GPIO_WritePin(LED2_1_GPIO_Port, LED2_1_Pin, RESET);
	HAL_GPIO_WritePin(LED2_2_GPIO_Port, LED2_2_Pin, SET);
};
void onYELLOW2(){
	HAL_GPIO_WritePin(LED2_1_GPIO_Port, LED2_1_Pin, SET);
	HAL_GPIO_WritePin(LED2_2_GPIO_Port, LED2_2_Pin, SET);
};
void onRED2(){
	HAL_GPIO_WritePin(LED2_1_GPIO_Port, LED2_1_Pin, SET);
	HAL_GPIO_WritePin(LED2_2_GPIO_Port, LED2_2_Pin, RESET);
};

void offALL(){
	HAL_GPIO_WritePin(LED1_1_GPIO_Port, LED1_1_Pin, SET);
	HAL_GPIO_WritePin(LED1_2_GPIO_Port, LED1_2_Pin, SET);
	HAL_GPIO_WritePin(LED2_1_GPIO_Port, LED2_1_Pin, SET);
	HAL_GPIO_WritePin(LED2_2_GPIO_Port, LED2_2_Pin, SET);
};

//PED
void pedGreen(){
	HAL_GPIO_WritePin(PET_LED_GPIO_Port, PET_LED_Pin, RESET);
};

void pedRed(){
	HAL_GPIO_WritePin(PET_LED_GPIO_Port, PET_LED_Pin, RESET);
};

/*
 * button.c
 *
 *  Created on: Oct 5, 2023
 *      Author: dinhq
 */

#include "button.h"

uint16_t pin_mode[4]={MODE_Pin,INC_Pin,SET_Pin,PET_BUT_Pin};
GPIO_TypeDef* port_mode[4]={MODE_GPIO_Port,INC_GPIO_Port,SET_GPIO_Port,PET_BUT_GPIO_Port};

int KeyReg0[NUM_BUTTON]={NORMAL_STATE,NORMAL_STATE,NORMAL_STATE};
int KeyReg1[NUM_BUTTON]={NORMAL_STATE,NORMAL_STATE,NORMAL_STATE};
int KeyReg2[NUM_BUTTON]={NORMAL_STATE,NORMAL_STATE,NORMAL_STATE};
int KeyReg3[NUM_BUTTON]={NORMAL_STATE,NORMAL_STATE,NORMAL_STATE};

int TimeOutForKeyPress[NUM_BUTTON] =  {200,200,200,200};
int button_flag[NUM_BUTTON] = {0,0,0,0};

int isButtonPressed(int num){
	if(button_flag[num] == 1){
		button_flag[num] = 0;
		return 1;
	}
	return 0;
}

void subKeyProcess(int num){
	//TODO
	button_flag[num]=1;
}

void getKeyInput(){
	for (int i=0; i<NUM_BUTTON; i++){
		KeyReg2[i] = KeyReg1[i];
		KeyReg1[i] = KeyReg0[i];
		//Add your button here
		KeyReg0[i] = HAL_GPIO_ReadPin(port_mode[i], pin_mode[i]);

		if ((KeyReg1[i] == KeyReg0[i]) && (KeyReg1[i] == KeyReg2[i])){ //avoid noise
			if (KeyReg2[i] != KeyReg3[i]){ //change state
				KeyReg3[i] = KeyReg2[i];
				if (KeyReg3[i] == PRESSED_STATE){
					TimeOutForKeyPress[i] = 200;
					subKeyProcess(i);
				}
			}

			else{ //press without release
				TimeOutForKeyPress[i]--;
				if (TimeOutForKeyPress[i] == 0){
					KeyReg3[i] = NORMAL_STATE;
				}

			}
		}
	}
}

void resetButton(){
	for (int i = 0; i < NUM_BUTTON; i++){
		isButtonPressed(i);
	}
}


/*
 * button.h
 *
 *  Created on: Oct 5, 2023
 *      Author: dinhq
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include "global.h"

#define NORMAL_STATE SET
#define PRESSED_STATE RESET

#define NUM_BUTTON 4

extern int button_flag[NUM_BUTTON];

void getKeyInput();
int isButtonPressed(int num);

#endif /* INC_BUTTON_H_ */

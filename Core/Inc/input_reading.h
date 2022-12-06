/*
 * input_reading.h
 *
 *  Created on: Dec 1, 2022
 *      Author: DELL
 */

#ifndef INC_INPUT_READING_H_
#define INC_INPUT_READING_H_

#include "main.h"


#define N0_OF_BUTTONS 				       4

//timer interrupt duration is 10ms, so to pass 1 second,
//we need to jump to the interrupt service routine 100 time
#define DURATION_FOR_AUTO_INCREASING	   100


void button_reading(void);
unsigned char is_button_held(unsigned char index);
unsigned char is_button_pressed(unsigned char index);
unsigned char is_button_pressed_1s(unsigned char index);

#endif /* INC_INPUT_READING_H_ */

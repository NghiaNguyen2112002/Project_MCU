/*
 * global.h
 *
 *  Created on: Dec 1, 2022
 *      Author: DELL
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

enum BUTTON{BUTTON_1 = 0, BUTTON_2, BUTTON_3, PEDES_BUTTON};

extern unsigned char BUZZER_VOLUME;
extern unsigned char TIME_RED;
extern unsigned char TIME_AMBER;
extern unsigned char TIME_GREEN;

extern unsigned char UART_BUFFER[2];



#endif /* INC_GLOBAL_H_ */

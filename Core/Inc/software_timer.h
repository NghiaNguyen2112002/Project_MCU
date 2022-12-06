/*
 * software_timer.h
 *
 *  Created on: Dec 1, 2022
 *      Author: DELL
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

#include "main.h"
#include "input_reading.h"
#include "scheduler.h"

void SetTimer_0(uint16_t duration);
void SetTimer_1(uint16_t duration);
void SetTimer_2(uint16_t duration);
void SetTimer_3(uint16_t duration);


uint8_t FlagTimer_0(void); //return timer0 flag
uint8_t FlagTimer_1(void); //return timer1 flag
uint8_t FlagTimer_2(void); //return timer2 flag
uint8_t FlagTimer_3(void); //return timer3 flag

void RunSoftwareTimer(void);

#endif /* INC_SOFTWARE_TIMER_H_ */

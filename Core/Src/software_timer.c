/*
 * software_timer.c
 *
 *  Created on: Dec 1, 2022
 *      Author: DELL
 */


#include "software_timer.h"

static uint16_t		TIME_CYCLE			= 10;

static uint8_t		flag_timer_0		= 0;
static uint8_t		counter_timer_0 	= 0;

static uint8_t		flag_timer_1		= 0;
static uint8_t		counter_timer_1 	= 0;

static uint8_t		flag_timer_2		= 0;
static uint8_t		counter_timer_2 	= 0;

static uint8_t		flag_timer_3		= 0;
static uint8_t		counter_timer_3 	= 0;


void SetTimer_0(uint16_t duration){
	counter_timer_0 = duration / TIME_CYCLE;
	flag_timer_0 = 0;
}
void SetTimer_1(uint16_t duration){
	counter_timer_1 = duration / TIME_CYCLE;
	flag_timer_1 = 0;
}

void SetTimer_2(uint16_t duration){
	counter_timer_2 = duration / TIME_CYCLE;
	flag_timer_2 = 0;
}

void SetTimer_3(uint16_t duration){
	counter_timer_3 = duration / TIME_CYCLE;
	flag_timer_3 = 0;
}

void RunSoftwareTimer(void){
	if(counter_timer_0 > 0){
		counter_timer_0--;
		if(counter_timer_0 == 0){
			flag_timer_0 = 1;
		}
	}
	if(counter_timer_1 > 0){
		counter_timer_1--;
		if(counter_timer_1 == 0){
			flag_timer_1 = 1;
		}
	}
	if(counter_timer_2 > 0){
		counter_timer_2--;
		if(counter_timer_2 == 0){
			flag_timer_2 = 1;
		}
	}
	if(counter_timer_3 > 0){
		counter_timer_3--;
		if(counter_timer_3 == 0){
			flag_timer_3 = 1;
		}
	}
}

uint8_t FlagTimer_0(void){
	return flag_timer_0;
}
uint8_t FlagTimer_1(void){
	return flag_timer_1;
}

uint8_t FlagTimer_2(void){
	return flag_timer_2;
}

uint8_t FlagTimer_3(void){
	return flag_timer_3;
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim){
	if(htim->Instance == TIM2) {
		SCH_Update();
	}
}


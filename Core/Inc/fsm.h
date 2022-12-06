/*
 * fsm.h
 *
 *  Created on: Dec 1, 2022
 *      Author: DELL
 */

#ifndef INC_FSM_H_
#define INC_FSM_H_

#include "main.h"
#include "global.h"
#include "output_control.h"
#include "scheduler.h"
#include "input_reading.h"

enum MODE_LIGHT {INIT_LIGHT, RED, AMBER, GREEN};

enum MODE	{INIT, AUTO, MANUAL, MODI_RED, MODI_AMBER, MODI_GREEN, PEDESTRIAN};

void fsm_for_input_processing(void);


#endif /* INC_FSM_H_ */

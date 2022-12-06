/*
 * fsm.c
 *
 *  Created on: Dec 1, 2022
 *      Author: DELL
 */

#include "fsm.h"

//{INIT_LIGHT, RED, AMBER, GREEN};
enum MODE_LIGHT mode_manual_1 = INIT_LIGHT;
enum MODE_LIGHT mode_manual_2 = INIT_LIGHT;

enum MODE_LIGHT mode_auto_1 = INIT_LIGHT;
enum MODE_LIGHT mode_auto_2 = INIT_LIGHT;

//{INIT, AUTO, MANUAL, MODI_RED, MODI_AMBER, MODI_GREEN, PEDESTRIAN};
enum MODE mode = INIT;



uint8_t time_1;
uint8_t time_2;

uint8_t index_task_temp_1;
uint8_t index_task_temp_2;

uint8_t	is_P_Light_On = 0;

void Off_Buzzer(void){
	BUZZER_VOLUME = 0;
}
void Buzzer_Control(void){
	if(BUZZER_VOLUME == 0){
//		time_1 (red) decreases => BUZZER_VOLUME increases
		BUZZER_VOLUME = (TIME_RED - time_1) * 100 / TIME_RED;
	}
	else BUZZER_VOLUME = 0;

}
void Pedestrian_Control(void){
	is_P_Light_On = 1;
	if(mode_auto_1 == RED){
		Light_P_Green();
//		On Off Buzzer  every 500ms
		SCH_Add_Task(Buzzer_Control, 0, 50);
	}
	else {
//		traffic light: AMBER or GREEN
		Light_P_Red();
	}
}
void Delete_Pedestrian_Control(void){
//	delete Pedestrian_Control + buzzer_control
	SCH_Delete_Task_NAME(Buzzer_Control);
	SCH_Delete_Task_NAME(Pedestrian_Control);

	Light_P_Off();
	Off_Buzzer();
	is_P_Light_On = 0;

}


void fsm_for_manual_1(void){
	switch(mode_manual_1){
	case INIT_LIGHT:
		mode_manual_1 = RED;
		break;
	case RED:
		if(is_button_pressed(BUTTON_1)) mode_manual_1 = AMBER;
		Light_1_Red();
		break;
	case AMBER:
		if(is_button_pressed(BUTTON_1)) mode_manual_1 = GREEN;
		Light_1_Amber();
		break;
	case GREEN:
		if(is_button_pressed(BUTTON_1)) mode_manual_1 = RED;
		Light_1_Green();
		break;
	default:
		break;
	}
}
void fsm_for_manual_2(void){
	switch(mode_manual_2){
	case INIT_LIGHT:
		mode_manual_2 = RED;
		break;
	case RED:
		if(is_button_pressed(BUTTON_2)) mode_manual_2 = AMBER;
		Light_2_Red();
		break;
	case AMBER:
		if(is_button_pressed(BUTTON_2)) mode_manual_2 = GREEN;
		Light_2_Amber();
		break;
	case GREEN:
		if(is_button_pressed(BUTTON_2)) mode_manual_2 = RED;
		Light_2_Green();
		break;
	default:
		break;
	}
}

void fsm_for_auto_1(void){				//this function is invoked every 1s
	switch(mode_auto_1){
	case INIT_LIGHT:
		time_1 = TIME_RED;
		Light_1_Red();
		mode_auto_1 = RED;
		break;
	case RED:
		if(time_1 == 0){
			time_1 = TIME_GREEN;
			Light_1_Green();
			mode_auto_1 = GREEN;
		}
		time_1--;
		break;
	case AMBER:
		if(time_1 == 0){
			time_1 = TIME_RED;
			Light_1_Red();
			mode_auto_1 = RED;
		}
		time_1--;
		break;
	case GREEN:
		if(time_1 == 0){
			time_1 = TIME_AMBER;
			Light_1_Amber();
			mode_auto_1 = AMBER;
		}
		time_1--;
		break;
	default:
		break;
	}
}
void fsm_for_auto_2(void){				//this function is invoked every 1s
	switch(mode_auto_2){
	case INIT_LIGHT:
		time_2 = TIME_GREEN;
		Light_2_Green();
		mode_auto_2 = GREEN;
		break;
	case RED:
		if(time_2 == 0){
			time_2 = TIME_GREEN;
			Light_2_Green();
			mode_auto_2 = GREEN;
		}
		time_2--;
		break;
	case AMBER:
		if(time_2 == 0){
			time_2 = TIME_RED;
			Light_2_Red();
			mode_auto_2 = RED;
		}
		time_2--;
		break;
	case GREEN:
		if(time_2 == 0){
			time_2 = TIME_AMBER;
			Light_2_Amber();
			mode_auto_2 = AMBER;
		}
		time_2--;
		break;
	default:
		break;
	}
}

void fsm_for_input_processing(void){
	switch(mode){
	case INIT:
		mode_auto_1 = INIT_LIGHT;
		mode_auto_2 = INIT_LIGHT;
		index_task_temp_1 = SCH_Add_Task(fsm_for_auto_1, 0, 100);		//1000ms
		index_task_temp_2 = SCH_Add_Task(fsm_for_auto_2, 0, 100);		//1000ms
		mode = AUTO;
		break;
	case AUTO:

		UART_BUFFER[0] = time_1;
		UART_BUFFER[1] = time_2;

		if(is_button_pressed(PEDES_BUTTON) && (!is_P_Light_On)){
			mode = PEDESTRIAN;
		}
		else if(is_button_pressed(BUTTON_3)){
			SCH_Delete_Task_NAME(fsm_for_auto_1);
			SCH_Delete_Task_NAME(fsm_for_auto_2);
			mode = MANUAL;
		}
		break;
	case MANUAL:

		UART_BUFFER[0] = 0;
		UART_BUFFER[1] = 0;
		fsm_for_manual_1();
		fsm_for_manual_2();

		if(is_button_pressed(BUTTON_3)){
			mode = MODI_RED;
		}
		break;
	case MODI_RED:

		UART_BUFFER[0] = TIME_RED;
		UART_BUFFER[1] = 11;
		Light_1_Red();
		Light_2_Red();

		if(is_button_pressed(BUTTON_1)){
			TIME_RED++;
		}
		else if(is_button_pressed(BUTTON_2)){
			TIME_RED--;
		}
		else if(is_button_pressed(BUTTON_3)){
			mode = MODI_AMBER;
		}
		break;
	case MODI_AMBER:

		UART_BUFFER[0] = TIME_AMBER;
		UART_BUFFER[1] = 22;
		Light_1_Amber();
		Light_2_Amber();

		if(is_button_pressed(BUTTON_1)){
			TIME_AMBER++;
		}
		else if(is_button_pressed(BUTTON_2)){
			TIME_AMBER--;
		}
		else if(is_button_pressed(BUTTON_3)){
			mode = MODI_GREEN;
		}
		break;
	case MODI_GREEN:

		UART_BUFFER[0] = TIME_GREEN;
		UART_BUFFER[1] = 33;
		Light_1_Green();
		Light_2_Green();

		if(is_button_pressed(BUTTON_1)){
			TIME_GREEN++;
		}
		else if(is_button_pressed(BUTTON_2)){
			TIME_GREEN--;
		}
		else if(is_button_pressed(BUTTON_3)){
			mode = INIT;
		}
		break;
	case PEDESTRIAN:

		SCH_Add_Task(Pedestrian_Control, 0, 1);

		//Off P light after 2 cycles of traffic light
		SCH_Add_Task(Delete_Pedestrian_Control, 2 * ( TIME_RED + TIME_GREEN + TIME_AMBER) * 100, 0);
		mode = AUTO;
		break;
	default:
		break;
	}
}

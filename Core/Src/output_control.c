/*
 * output_control.c
 *
 *  Created on: Dec 1, 2022
 *      Author: DELL
 */

#include "output_control.h"


void Light_1_Red(void){
	HAL_GPIO_WritePin(T_Light_1_a_GPIO_Port, T_Light_1_a_Pin, SET);
	HAL_GPIO_WritePin(T_Light_1_b_GPIO_Port, T_Light_1_b_Pin, RESET);
}
void Light_1_Amber(void){
	HAL_GPIO_WritePin(T_Light_1_a_GPIO_Port, T_Light_1_a_Pin, RESET);
	HAL_GPIO_WritePin(T_Light_1_b_GPIO_Port, T_Light_1_b_Pin, SET);
}
void Light_1_Green(void){
	HAL_GPIO_WritePin(T_Light_1_a_GPIO_Port, T_Light_1_a_Pin, SET);
	HAL_GPIO_WritePin(T_Light_1_b_GPIO_Port, T_Light_1_b_Pin, SET);
}

void Light_2_Red(void){
	HAL_GPIO_WritePin(T_Light_2_a_GPIO_Port, T_Light_2_a_Pin, SET);
	HAL_GPIO_WritePin(T_Light_2_b_GPIO_Port, T_Light_2_b_Pin, RESET);
}
void Light_2_Amber(void){
	HAL_GPIO_WritePin(T_Light_2_a_GPIO_Port, T_Light_2_a_Pin, RESET);
	HAL_GPIO_WritePin(T_Light_2_b_GPIO_Port, T_Light_2_b_Pin, SET);
}
void Light_2_Green(void){
	HAL_GPIO_WritePin(T_Light_2_a_GPIO_Port, T_Light_2_a_Pin, SET);
	HAL_GPIO_WritePin(T_Light_2_b_GPIO_Port, T_Light_2_b_Pin, SET);
}

void Light_P_Off(void){
	HAL_GPIO_WritePin(P_Light_a_GPIO_Port, P_Light_a_Pin, RESET);
	HAL_GPIO_WritePin(P_Light_b_GPIO_Port, P_Light_b_Pin, RESET);
}
void Light_P_Red(void){
	HAL_GPIO_WritePin(P_Light_a_GPIO_Port, P_Light_a_Pin, SET);
	HAL_GPIO_WritePin(P_Light_b_GPIO_Port, P_Light_b_Pin, RESET);

}
void Light_P_Amber(void){
	HAL_GPIO_WritePin(P_Light_a_GPIO_Port, P_Light_a_Pin, RESET);
	HAL_GPIO_WritePin(P_Light_b_GPIO_Port, P_Light_b_Pin, SET);
}
void Light_P_Green(void){
	HAL_GPIO_WritePin(P_Light_a_GPIO_Port, P_Light_a_Pin, SET);
	HAL_GPIO_WritePin(P_Light_b_GPIO_Port, P_Light_b_Pin, SET);
}

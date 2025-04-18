#ifndef __MOTOR_H__	
#define __MOTOR_H__

#include "main.h" //HAL库文件声明
#include "tim.h"

//L为左轮，R为右轮

#define L_GO 	    HAL_GPIO_WritePin(IN1_GPIO_Port,  IN1_Pin,  GPIO_PIN_SET);     HAL_GPIO_WritePin(IN2_GPIO_Port,  IN2_Pin,  GPIO_PIN_RESET)
#define R_GO	    HAL_GPIO_WritePin(IN3_GPIO_Port,  IN3_Pin,  GPIO_PIN_SET);     HAL_GPIO_WritePin(IN4_GPIO_Port,  IN4_Pin,  GPIO_PIN_RESET)

#define L_BACK 		HAL_GPIO_WritePin(IN1_GPIO_Port,  IN1_Pin,  GPIO_PIN_RESET);   HAL_GPIO_WritePin(IN2_GPIO_Port,  IN2_Pin,  GPIO_PIN_SET)
#define R_BACK		HAL_GPIO_WritePin(IN3_GPIO_Port,  IN3_Pin,  GPIO_PIN_RESET);   HAL_GPIO_WritePin(IN4_GPIO_Port,  IN4_Pin,  GPIO_PIN_SET)


/*外部调用*/
void Motor_Init(void);

void Motor_SetSpeed(uint8_t PIN,int8_t Speed);

#endif 



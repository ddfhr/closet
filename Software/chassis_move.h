#ifndef __CHASSIS_MOVE_H__
#define __CHASSIS_MOVE_H__

#include "main.h" //HAL���ļ�����

extern TIM_HandleTypeDef htim2;//����TIM2��HAL��ṹ��


void chassis_move_init(void);//���̳�ʼ��
void chassis_set_speed(void);//���̵���ٶ�����

#endif 


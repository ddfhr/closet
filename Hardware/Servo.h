#ifndef _SERVO_H
#define _SERVO_H

#include "tim.h"



//�ⲿ����

void Servo_Init(void);

void ServoCtrl(uint8_t Channel,uint8_t Angle);

void ServoCtrl2(uint8_t Channel,float Angle,short Speed);
#endif


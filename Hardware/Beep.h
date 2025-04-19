#ifndef __BEEP_H
#define __BEEP_H

#include "stm32f1xx_hal.h"

// Ӳ�����ã��ɸ���ʵ�������޸ģ�
#define BEEP_GPIO_PORT          GPIOA
#define BEEP_GPIO_PIN           GPIO_PIN_4

// �궨�壨�򻯲�����
#define BEEP_ON()               HAL_GPIO_WritePin(BEEP_GPIO_PORT, BEEP_GPIO_PIN, GPIO_PIN_SET)
#define BEEP_OFF()              HAL_GPIO_WritePin(BEEP_GPIO_PORT, BEEP_GPIO_PIN, GPIO_PIN_RESET)
#define BEEP_TOGGLE()           HAL_GPIO_TogglePin(BEEP_GPIO_PORT, BEEP_GPIO_PIN)

// ��������
void BEEP_Init(void);

#endif /* __BEEP_H */
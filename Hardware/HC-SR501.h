#ifndef __BODY_HW_H
#define __BODY_HW_H
#include "stm32f1xx_hal.h"
#include "math.h"

/***************�����Լ��������****************/
// BODY_HW GPIO�궨��
#define BODY_HW_GPIO_PORT       GPIOA
#define BODY_HW_GPIO_PIN        GPIO_PIN_0

/*********************END**********************/

void BODY_HW_Init(void);
uint16_t BODY_HW_GetData(void);

#endif /* __BODY_HW_H */
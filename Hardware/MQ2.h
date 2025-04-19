#ifndef __MQ2_H
#define __MQ2_H

#include "stm32f1xx_hal.h"

/*****************MQ-2��������������DOģʽ��******************
 * �汾��V1.1��HAL��汾��
 * ���ܣ�ͨ�����������DO���������
 * ���ţ�PA1�����Զ��壩
 **************************************************************/

// Ӳ�����ã�����ʵ�������޸ģ�
#define MQ2_DO_GPIO_PORT        GPIOB
#define MQ2_DO_GPIO_PIN         GPIO_PIN_15

// ��������
void MQ2_Init(void);
uint8_t MQ2_GetData(void);  // ����0/1��ʾ����״̬

#endif /* __MQ2_H */
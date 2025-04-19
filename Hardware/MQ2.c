#include "MQ2.h"

/*****************MQ-2��ʼ��******************/
void MQ2_Init(void)
{
    GPIO_InitTypeDef GPIO_InitStruct = {0};

    // ʹ��GPIOʱ�ӣ�CubeMX���Զ����ɣ��˴���ʡ�ԣ�
    // __HAL_RCC_GPIOA_CLK_ENABLE();

    // ����GPIOΪ��������
    GPIO_InitStruct.Pin = MQ2_DO_GPIO_PIN;
    GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
    GPIO_InitStruct.Pull = GPIO_PULLUP;  // ���������������
    HAL_GPIO_Init(MQ2_DO_GPIO_PORT, &GPIO_InitStruct);
}

/*****************��ȡ����״̬******************/
uint8_t MQ2_GetData(void)
{
    // DO���ŵ͵�ƽ��ʾ��⵽����ע���߼�ȡ����
    return (HAL_GPIO_ReadPin(MQ2_DO_GPIO_PORT, MQ2_DO_GPIO_PIN) == GPIO_PIN_RESET) ? 1 : 0;
}
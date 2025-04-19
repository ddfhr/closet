#include "Beep.h"

/*****************����������ʵ�֣�HAL�⣩******************/
void BEEP_Init(void)
{
    GPIO_InitTypeDef GPIO_InitStruct = {0};

    // ʹ��GPIOʱ�ӣ�����CubeMX���Զ����ɣ��˴���ʡ�ԣ�
    // __HAL_RCC_GPIOA_CLK_ENABLE();

    // ����GPIO
    GPIO_InitStruct.Pin = BEEP_GPIO_PIN;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;  // �������
    GPIO_InitStruct.Pull = GPIO_NOPULL;          // ��������
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH; // ����ģʽ
    HAL_GPIO_Init(BEEP_GPIO_PORT, &GPIO_InitStruct);

    // Ĭ�Ϲرշ�����
    BEEP_OFF();
}
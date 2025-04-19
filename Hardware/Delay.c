/*
 * Delay.c
 *
 *  Created on: Apr 19, 2025
 *      Author: luzhe
 */

#include "stm32f1xx_hal.h"
#include "stm32f1xx_hal_tim.h"

TIM_HandleTypeDef htim_us;
void MX_TIM_US_Init(void){
	uint32_t timer_clk = HAL_RCC_GetPCLK1Freq() * 2; // ��ȡAPB1��ʱ��ʱ�ӣ������б�Ƶ��
	htim_us.Instance = TIM2;  // ѡ����ö�ʱ������TIM2/TIM5��
	htim_us.Init.Prescaler = (timer_clk / 1000000) - 1; // ����1MHz����
	htim_us.Init.CounterMode = TIM_COUNTERMODE_UP;
	htim_us.Init.Period = 0xFFFFFFFF; // �������ֵ
	htim_us.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	HAL_TIM_Base_Init(&htim_us);
	HAL_TIM_Base_Start(&htim_us);
}

void delay_us(uint32_t us)
{
    uint32_t start = __HAL_TIM_GET_COUNTER(&htim_us);
    uint32_t elapsed;
    do {
        elapsed = __HAL_TIM_GET_COUNTER(&htim_us) - start;
    } while(elapsed < us);
}

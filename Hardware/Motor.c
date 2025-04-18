#include "motor.h"

/*
С����ʼ������
ռ�ö�ʱ��3���ĸ�ͨ��
*/
void Motor_Init(void)
{
	/*�������Ƶ���Ķ�ʱ��ͨ��*/
	HAL_TIM_PWM_Start(&htim3,TIM_CHANNEL_1);  //������ʱ��3ͨ��1
	HAL_TIM_PWM_Start(&htim3,TIM_CHANNEL_2);
	HAL_TIM_PWM_Start(&htim3,TIM_CHANNEL_3);  
	HAL_TIM_PWM_Start(&htim3,TIM_CHANNEL_4);

}
/*
С�����ƺ���
Motor�� ������1-4 ,����ֻ�����������ӣ������Ҫ����Ļ�����ǰ����һ���Ѻ���ļ���
Speed: ������ٶ�
*/

void Motor_SetSpeed(uint8_t Motor,int8_t Speed)
{
	if(Speed > 100)
	{
		Speed = 100;
	}
	else if(Speed < -100)
	{
		Speed = -100;
	}
	int16_t compare = Speed * 200;
	switch (Motor)
	{
		case 1:
			if(Speed >= 0)
			{		
				L_GO;				
				__HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_1,compare); 
			}
			else	
			{
				L_BACK;
				__HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_1,-compare);
			}
			break;
		case 2:
			if(Speed >= 0)
			{		
				R_GO;				
				__HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_2,compare); 
			}
			else	
			{
				R_BACK;
				__HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_2,-compare);
			}
			break;
	}
}



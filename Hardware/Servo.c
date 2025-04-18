#include "Servo.h"
/*
�����ʼ������
ռ�ö�ʱ��2���ĸ�ͨ��
*/
void Servo_Init(void)
{
/*�������ƶ���Ķ�ʱ��ͨ��*/
	HAL_TIM_PWM_Start(&htim2,TIM_CHANNEL_1);  //������ʱ��2ͨ��1
	HAL_TIM_PWM_Start(&htim2,TIM_CHANNEL_2);
	HAL_TIM_PWM_Start(&htim2,TIM_CHANNEL_3);  
	HAL_TIM_PWM_Start(&htim2,TIM_CHANNEL_4);
	
}
/*
180�ȶ�����ƺ���
Channel�� ͨ��1-4 ��Ӧ ���1-4 
Angle ������Ƕ� 0-180
*/

void ServoCtrl(uint8_t Channel,uint8_t Angle)
{
	short compare;
	compare = 500 + (float)Angle / 180 * 2000; //����Ƕ�PWMת����ʽ
	switch(Channel)
	  {
			case 1:            //���1��ת              
				 __HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_1,compare); 
				break;
			case 2:
				__HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_2,compare); 
				break;
			case 3:
				__HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_3,compare); 
				break;
			case 4:
				__HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_4,compare); 
				break;
    }
	
}

/*
180�ȶ�����ƺ������ɿ��ٶ�
Channel�� ͨ��1-4 ��Ӧ ���1-4 
Angle ������Ƕ� 0-180
Speed : ���ת�����ٶȣ�����̫��һ�����ھ��У�
*/

void ServoCtrl2(uint8_t Channel,float Angle,short Speed)   //�������ٶ���,�������Ҫ����ʹ��,��̫����
{
	
	float compare=0;
	
	compare = 500+(Angle*2000/180);
	for(short i=0;i<compare;i += Speed)
	{
		if      (Channel==1)     __HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_1,i); 
		else	if(Channel==2) 		 __HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_2,i); 
		else	if(Channel==3)     __HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_3,i); 
		else	if(Channel==4)		 __HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_4,i); 
		HAL_Delay(1);	
	}
	
}

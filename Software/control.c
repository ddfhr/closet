#include "global.h"
#include "bluetooth.h"
#include "Motor.h"
#include "chassis_move.h"
void Global_init(void)
{
//����	
	Global.input.x = 0;
	Global.input.y = 0;
	Global.input.r = 0;
	
	Global.max_x = 60;
	Global.max_y = 0;
	Global.max_r = 80;
//��е��
	Global.input.small_pitch = 0;
	Global.input.mid_pitch = 0;
	Global.input.big_pitch = 0;
	
	Global.gripper = OPEN;		
}

/*
	����ʾ��

    Y
	*
	*
	*
	*
	**********X					      
*/

void control_tack(void)
{
	//�����������ڵ�����
	if(USART2_RX_BUF[0]==0xA5) 	//�жϽ��յ�1�������ǲ��ǰ�ͷ0xA5)	
	{
		//�˶�
		 Global.input.x = USART2_RX_BUF[1] - 50;
		 Global.input.r = USART2_RX_BUF[2] - 50;
		//��е��
		 Global.input.small_pitch = USART2_RX_BUF[6] * 2;
		 Global.input.mid_pitch = USART2_RX_BUF[4] * 2;
	   	 Global.input.big_pitch = USART2_RX_BUF[3] * 2;
		//��צ
		if(USART2_RX_BUF[5])
			Global.gripper = OPEN;
		else
			Global.gripper = CLOSE;
	}
		


}


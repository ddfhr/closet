#include "global.h"
#include "bluetooth.h"
#include "Motor.h"
#include "chassis_move.h"
void Global_init(void)
{
//底盘	
	Global.input.x = 0;
	Global.input.y = 0;
	Global.input.r = 0;
	
	Global.max_x = 60;
	Global.max_y = 0;
	Global.max_r = 80;
//机械臂
	Global.input.small_pitch = 0;
	Global.input.mid_pitch = 0;
	Global.input.big_pitch = 0;
	
	Global.gripper = OPEN;		
}

/*
	坐标示意

    Y
	*
	*
	*
	*
	**********X					      
*/

void control_tack(void)
{
	//接收蓝牙串口的数据
	if(USART2_RX_BUF[0]==0xA5) 	//判断接收第1个数据是不是包头0xA5)	
	{
		//运动
		 Global.input.x = USART2_RX_BUF[1] - 50;
		 Global.input.r = USART2_RX_BUF[2] - 50;
		//机械臂
		 Global.input.small_pitch = USART2_RX_BUF[6] * 2;
		 Global.input.mid_pitch = USART2_RX_BUF[4] * 2;
	   	 Global.input.big_pitch = USART2_RX_BUF[3] * 2;
		//夹爪
		if(USART2_RX_BUF[5])
			Global.gripper = OPEN;
		else
			Global.gripper = CLOSE;
	}
		


}


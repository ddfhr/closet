#include "chassis_move.h"
#include "motor.h"
#include "Global.h"



void chassis_move_init(void)
{
	Global.wheel_speed[0] = 0;
	Global.wheel_speed[1] = 0;
	Global.wheel_speed[2] = 0;
	Global.wheel_speed[3] = 0;
}
void chassis_set_speed(void)
{
	//��������ת��
	Global.wheel_speed[0] =  + Global.input.r + Global.input.x;//����
	Global.wheel_speed[1] = - Global.input.r + Global.input.x ;//����
	
	//����������
	Motor_SetSpeed(1,Global.wheel_speed[0]);
	Motor_SetSpeed(2,Global.wheel_speed[1]);
}	




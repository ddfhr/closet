#include "robot_arm.h"
#include "Servo.h"
#include "Global.h"


void robot_arm_init(void)
{

}
void robot_arm_set(void)
{
	ServoCtrl(1,Global.input.big_pitch);
	ServoCtrl(2,Global.input.mid_pitch);
	ServoCtrl(3,Global.input.small_pitch);
	
//МазІ	
	if(Global.gripper == CLOSE)
		ServoCtrl(4,0);
	else
		ServoCtrl(4,90);		
}	


/**
 * @file global.h
 * @author 
 * @brief 全局状态机
 * @version 0.1
 * @date 
 *
 * @copyright 
 *
 */
#include "stdint.h"
 
#define __GLOBAL_H__
#ifdef __GLOBAL_H__

struct GlobalStatus_t
{
    float max_x, max_y, max_r;//底盘最大分速度
	float wheel_speed[4];//轮子转速
	
    enum gripper_e//夹爪
    {
        OPEN = 0,//开
        CLOSE,
    } gripper;
			
    struct
    {
		float x, y, r; // 底盘移动
		float big_pitch,mid_pitch,small_pitch;//机械臂
		
    } input;

};

extern struct GlobalStatus_t Global;


#endif
// end of file


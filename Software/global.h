/**
 * @file global.h
 * @author 
 * @brief ȫ��״̬��
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
    float max_x, max_y, max_r;//���������ٶ�
	float wheel_speed[4];//����ת��
	
    enum gripper_e//��צ
    {
        OPEN = 0,//��
        CLOSE,
    } gripper;
			
    struct
    {
		float x, y, r; // �����ƶ�
		float big_pitch,mid_pitch,small_pitch;//��е��
		
    } input;

};

extern struct GlobalStatus_t Global;


#endif
// end of file


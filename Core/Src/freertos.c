/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * File Name          : freertos.c
  * Description        : Code for freertos applications
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "FreeRTOS.h"
#include "task.h"
#include "main.h"
#include "cmsis_os.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "global.h"
#include "OLED.h" 
#include "IR.h"
#include "HC-SR501.h"
#include "Beep.h"
#include "MQ2.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN Variables */

/* USER CODE END Variables */
/* Definitions for ChassisTask */
osThreadId_t ChassisTaskHandle;
const osThreadAttr_t ChassisTask_attributes = {
  .name = "ChassisTask",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityNormal,
};
/* Definitions for GimbalTask */
osThreadId_t GimbalTaskHandle;
const osThreadAttr_t GimbalTask_attributes = {
  .name = "GimbalTask",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityLow,
};
/* Definitions for BluetoothTask */
osThreadId_t BluetoothTaskHandle;
const osThreadAttr_t BluetoothTask_attributes = {
  .name = "BluetoothTask",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityLow,
};

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */
uint16_t ir;
uint16_t mq2;
int value = 2;
/* USER CODE END FunctionPrototypes */

void ChassisTask_callback(void *argument);
void GimbalTask_callback(void *argument);
void BluetoothTask_callback(void *argument);

void MX_FREERTOS_Init(void); /* (MISRA C 2004 rule 8.1) */

/**
  * @brief  FreeRTOS initialization
  * @param  None
  * @retval None
  */
void MX_FREERTOS_Init(void) {
  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* USER CODE BEGIN RTOS_MUTEX */
  /* add mutexes, ... */
  /* USER CODE END RTOS_MUTEX */

  /* USER CODE BEGIN RTOS_SEMAPHORES */
  /* add semaphores, ... */
  /* USER CODE END RTOS_SEMAPHORES */

  /* USER CODE BEGIN RTOS_TIMERS */
  /* start timers, add new ones, ... */
  /* USER CODE END RTOS_TIMERS */

  /* USER CODE BEGIN RTOS_QUEUES */
  /* add queues, ... */
  /* USER CODE END RTOS_QUEUES */

  /* Create the thread(s) */
  /* creation of ChassisTask */
  ChassisTaskHandle = osThreadNew(ChassisTask_callback, NULL, &ChassisTask_attributes);

  /* creation of GimbalTask */
  GimbalTaskHandle = osThreadNew(GimbalTask_callback, NULL, &GimbalTask_attributes);

  /* creation of BluetoothTask */
  BluetoothTaskHandle = osThreadNew(BluetoothTask_callback, NULL, &BluetoothTask_attributes);

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
  /* USER CODE END RTOS_THREADS */

  /* USER CODE BEGIN RTOS_EVENTS */
  /* add events, ... */
  /* USER CODE END RTOS_EVENTS */

}

/* USER CODE BEGIN Header_ChassisTask_callback */
/**
  * @brief  Function implementing the ChassisTask thread.
  * @param  argument: Not used
  * @retval None
  */
/* USER CODE END Header_ChassisTask_callback */
//温湿度控制
void ChassisTask_callback(void *argument)
{
  /* USER CODE BEGIN ChassisTask_callback */
  /* Infinite loop */
  for(;;)
  {
		    
       
	      OLED_refresh_gram();
    osDelay(1);
  }
  /* USER CODE END ChassisTask_callback */
}

/* USER CODE BEGIN Header_GimbalTask_callback */
/**
* @brief Function implementing the GimbalTask thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_GimbalTask_callback */
//烟雾传感器
void GimbalTask_callback(void *argument)
{
  /* USER CODE BEGIN GimbalTask_callback */
  /* Infinite loop */
  for(;;)
  {
		ir = IR_FireData();
		mq2 = MQ2_GetData();  
		if(ir == 0)
		{
			OLED_printf(0,0,"normal");
			BEEP_OFF();
		}
		else
		{
			OLED_printf(0,0,"warning");
			BEEP_ON();
		}
		
		OLED_printf(4,0,"mq2:%df",mq2);
		
	
		
    osDelay(1);
  }
  /* USER CODE END GimbalTask_callback */
}

/* USER CODE BEGIN Header_BluetoothTask_callback */
/**
* @brief Function implementing the BluetoothTask thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_BluetoothTask_callback */
//紫外线灯
void BluetoothTask_callback(void *argument)
{
  /* USER CODE BEGIN BluetoothTask_callback */
  /* Infinite loop */
  for(;;)
  {
		value = BODY_HW_GetData();
	  if (value == 1)  // 检测到人体
    {
        OLED_printf(0,2,"people");
			 HAL_GPIO_WritePin(GPIOC,GPIO_PIN_13,GPIO_PIN_RESET);
    }
    else
    {
       OLED_printf(0,2,"none");
			 HAL_GPIO_WritePin(GPIOC,GPIO_PIN_13,GPIO_PIN_RESET);
    }
    osDelay(1);
  }
  /* USER CODE END BluetoothTask_callback */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */

/* USER CODE END Application */


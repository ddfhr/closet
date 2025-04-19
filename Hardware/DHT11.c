/*
 * DHT11.c
 *
 *  Created on: Apr 18, 2025
 *      Author: luzhe
 */

#include "main.h"
#include "DHT11.h"
#include "Delay.h"
#include "stm32f1xx_hal.h"
#include "stm32f1xx_hal_gpio.h"
uint8_t DHT11_Init(){
	DHT11_Rst();
	return DHT11_Check();
}

void DHT11_Rst(){
	DHT11_Mode(OUT);
	DHT11_Low;
	HAL_Delay(20);
	DHT11_High;
	HAL_Delay(13);
}

void DHT11_Mode(uint8_t mode){
	GPIO_InitTypeDef GPIO_InitStructure;
	if(mode){
		GPIO_InitStructure.Pin= GPIO_PIN_6;
		 GPIO_InitStructure.Mode = GPIO_MODE_OUTPUT_PP;
		 GPIO_InitStructure.Speed = GPIO_SPEED_FREQ_LOW;
	}
	else{
		 GPIO_InitStructure.Pin = GPIO_PIN_6;
	    GPIO_InitStructure.Mode = GPIO_MODE_INPUT;
	}
	HAL_GPIO_Init(GPIOB, & GPIO_InitStructure);
}

uint8_t DHT11_Check(void){
	uint8_t retry=0;
	DHT11_Mode(IN);
	while(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_6)&&retry<100){
		retry++;
		delay_us(1);
	}
	if(retry>=100){
		return 1;
	}
	else{
		retry=0;
	}
	while(!HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_6)&&retry<100){
		retry++;
		delay_us(1);
	}
	if(retry>=100){
			return 1;
		}
	return 0;
}

uint8_t DHT11_Read_Bit(void){
	uint8_t retry=0;
	while(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_6)&&retry<100){
			retry++;
			delay_us(1);
		}
	if(retry>=100){
		return 1;
	}
	else{
	    retry=0;
	}
	while(!HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_6)&&retry<100){
		retry++;
		delay_us(1);
	}
	if(retry>=100){
			return 1;
		}
		return 0;
}

//从DHT11读取一个字节
//返回值：读到的数据
uint8_t DHT11_Read_Byte(void){
	uint8_t i,dat;
	dat=0;
	for(i=0;i<8;i++){
		dat<<=1;
		dat|=DHT11_Read_Bit();
	}
	return dat;
}

uint8_t DHT11_Read_Data(uint8_t *temp, uint8_t *humi){
	uint8_t buf[5];
	uint8_t i;
	DHT11_Rst();
	if(DHT11_Check()==0){
		for(i=0;i<5;i++)//读取四十位数据
		{
			buf[i]=DHT11_Read_Byte();
		}
		if(buf[0]+buf[1]+buf[2]+buf[3]==buf[4]){
			*humi=buf[0];
			*humi=buf[2];
		}
	}
	else return 1;
	return 0;
}


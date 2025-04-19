/*
 * DHT11.h
 *
 *  Created on: Apr 18, 2025
 *      Author: luzhe
 */
#include "main.h" //HAL¿âÎÄ¼þÉùÃ÷
#ifndef INC_DHT11_H_
#define INC_DHT11_H_

#define OUT 1
#define IN  0

#define DHT11_Low       HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, GPIO_PIN_RESET);
#define DHT11_High      HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, GPIO_PIN_SET);

uint8_t DHT11_Init();
void DHT11_Rst();
void DHT11_Mode(uint8_t mode);
uint8_t DHT11_Check(void);
uint8_t DHT11_Read_Bit(void);
uint8_t DHT11_Read_Byte(void);
uint8_t DHT11_Read_Data(uint8_t *temp, uint8_t *humi);

#endif /* INC_DHT11_H_ */

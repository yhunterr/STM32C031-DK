/*
 * spi.c
 *
 *  Created on: Feb 18, 2024
 *      Author: sw
 */
#include "spi.h"
extern SPI_HandleTypeDef hspi1;

void spi_cs(bool b)
{
		HAL_GPIO_WritePin(DOT_CS_GPIO_Port, DOT_CS_Pin, b);
}


void spi_transmit(uint16_t data)
{
	uint8_t data_to_send[2];
	data_to_send[0] = (uint8_t)(data >> 8);
	data_to_send[1] = (uint8_t)data;

	spi_cs(LOW);
	HAL_SPI_Transmit(&hspi1, data_to_send, 2, 100);
	spi_cs(HIGH);
}

void spi_transmit4(uint8_t digits, uint16_t data)
{
	if(digits == 1)
		digits = 4;
	else if(digits == 2)
		digits = 3;
	else if(digits == 3)
		digits = 2;
	else if(digits == 4)
		digits = 1;

	uint8_t digits_pass[2] ={0x00,0x00};
	uint8_t data_to_send[2];
	data_to_send[0] = (uint8_t)(data >> 8);
	data_to_send[1] = (uint8_t)data;

	spi_cs(LOW);
	for(int i=1; i<5; i++)
	{
		if(digits == i)
		{
			HAL_SPI_Transmit(&hspi1, data_to_send, 2, 100);
		}
		else
		{
			HAL_SPI_Transmit(&hspi1, digits_pass, 2, 100);
		}
	}
	spi_cs(HIGH);
}

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


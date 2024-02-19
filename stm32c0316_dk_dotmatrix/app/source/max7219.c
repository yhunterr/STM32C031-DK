/*
 * max7219.c
 *
 *  Created on: Feb 18, 2024
 *      Author: sw
 */


#include "max7219.h"
#include "spi.h"


void max7219_init()
{
	uint16_t init[] = {0x0900,0x0A01,0x0b07,0x0c01,0x0f00};
	uint8_t i;
	for(i=0; i<sizeof(init)/2; i++)
	{
		spi_transmit(init[i]);
	}
}

void max7219_data()
{
	uint16_t data1[] = {0x01c3,0x02c3,0x03c3,0x04ff,0x05ff,0x06c3,0x07c3,0x08c3};
	uint16_t data2[] = {0x01ff,0x02ff,0x0318,0x0418,0x0518,0x0618,0x07ff,0x08ff};
	uint8_t i;

	for(i=0; i<sizeof(data1)/2; i++)
	{
		spi_transmit(data1[i]);
	}
	HAL_Delay(1000);
	for(i=0; i<sizeof(data2)/2; i++)
	{
		spi_transmit(data2[i]);
	}
	HAL_Delay(1000);
}



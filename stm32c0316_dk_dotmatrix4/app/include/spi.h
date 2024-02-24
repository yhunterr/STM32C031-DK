/*
 * spi.h
 *
 *  Created on: Feb 18, 2024
 *      Author: sw
 */

#ifndef INCLUDE_SPI_H_
#define INCLUDE_SPI_H_

#include "def.h"


void spi_transmit(uint16_t data);
void spi_transmit4(uint8_t digits, uint16_t data);
void spi_cs(bool b);

#endif /* INCLUDE_SPI_H_ */

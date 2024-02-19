/*
 * ap.c
 *
 *  Created on: Feb 18, 2024
 *      Author: sw
 */


#include "ap.h"

void apInit(void)
{
	max7219_init();
}

void apMain(void)
{
  while(1)
  {
  	max7219_data();
  }
}

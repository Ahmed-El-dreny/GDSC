/*
 * main.c
 *
 *  Created on: Apr 13, 2023
 *      Author: ahmed
 */
#include <avr/io.h>
#include <util/delay.h>
#define DDRA *((uint8*)0x3A)
#define PORTA *((uint8*)0x3B)

typedef unsigned char uint8;

int main(void)
{
	uint8 bit = 0;
	//pin 0 in DDR is output
	DDRA = 255;

	while(1)
	{
		while(bit<=7)
		{
			PORTA |= (1<<bit);
			_delay_ms(200);
			bit++;
		}

		bit = 0;

		while(bit<=7)
		{
			PORTA &= ~(1<<bit);
			_delay_ms(200);

			bit++;
		}

		bit = 0;
	}

	while(1);

	return 0;
}


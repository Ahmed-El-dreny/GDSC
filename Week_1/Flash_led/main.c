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
	//pin 0 in DDR is output
	DDRA |= (1<<0);

	while(1)
	{
		//pin 0 in PORTA is output
		PORTA |= (1<<0);
		_delay_ms(1000);
		PORTA &= ~(1<<0);
		_delay_ms(1000);
	}

	while(1);

	return 0;
}

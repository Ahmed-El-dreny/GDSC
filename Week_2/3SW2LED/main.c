/*
 * main.c
 *
 *  Created on: Apr 17, 2023
 *      Author: ahmed
 */
#include <avr/io.h>
#include <util/delay.h>
#define DDRA *((uint8*)0x3A)
#define PORTA *((uint8*)0x3B)
#define PINA *((volatile uint8*)0x39)

#define DDRB *((uint8*)0x37)
#define PORTB *((uint8*)0x38)
#define PINB *((volatile uint8*)0x36)

#define DDRC *((uint8*)0x34)
#define PORTC *((uint8*)0x35)
#define PINC *((volatile uint8*)0x33)

#define DDRD *((uint8*)0x31)
#define PORTD *((uint8*)0x32)
#define PIND *((volatile uint8*)0x30)

typedef unsigned char uint8;

int main(void)
{
	uint8 pinState1 = ((PINB >> 0)&1), pinState2 = ((PINB >> 1)&1), pinState3 = ((PINB >> 2)&1);

	DDRB = 0;
	PORTB = 255;

	DDRA = 255;
	PORTA = 0;

	while(1)
	{
		if(((PINB >> 0)&1) == 0)
		{
			PORTA |= (1 << 0);
		}
		else
		{
			PORTA &= ~(1 << 0);
		}

		if(((PINB >> 1)&1) == 0)
		{
			PORTA |= (1 << 1);
		}
		else
		{
			PORTA &= ~(1 << 1);
		}

		if(((PINB >> 2)&1) == 0)
		{
			PORTA |= (1 << 0);
			PORTA |= (1 << 1);
		}
		else
		{
			PORTA &= ~(1 << 0);
			PORTA &= ~(1 << 0);
		}
	}
}


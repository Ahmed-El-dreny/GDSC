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
	uint8 digit[] = {0x3f,0x06,0x5b,
				   	 0x4f,0x66,0x6d,
					 0x7d,0x07,0x7f,
					 0x6f};
	static uint8 counter = 0;

	DDRA = 0;
	DDRC = 255;

	PORTA = 255;
	PORTC = 0;

	while(1)
	{
		while(counter <= 0)
		{
			PORTC = digit[0];
			if(((PINA >> 0)& 1) == 0)
			{
				counter++;
				while(((PINA >> 0)& 1) == 0);
			}

			else if(((PINA >> 1)& 1) == 0)
			{
				while(((PINA >> 1)& 1) == 0);
			}
		}


		while ( (0 < counter) && (counter < 9) )
		{
			if(((PINA >> 0)& 1) == 0)
			{
				counter++;
				while(((PINA >> 0)& 1) == 0);
			}

			else if(((PINA >> 1)& 1) == 0)
			{
				counter--;
				while(((PINA >> 1)& 1) == 0);
			}

			PORTC = digit[counter];
		}


		while(counter >= 9)
		{
			PORTC = digit[9];
			if(((PINA >> 0)& 1) == 0)
			{
				while(((PINA >> 0)& 1) == 0);
			}

			else if(((PINA >> 1)& 1) == 0)
			{
				counter--;
				while(((PINA >> 1)& 1) == 0);
			}
		}


	}
}

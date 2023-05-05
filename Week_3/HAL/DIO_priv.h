/*
 * DIO_priv.h
 *
 *  Created on: May 4, 2023
 *      Author: ahmed
 */

#ifndef DIO_PRIV_H_
#define DIO_PRIV_H_
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


typedef enum{
	EN_PORTA = 0,
	EN_PORTB,
	EN_PORTC,
	EN_PORTD
}EN_PORT;

typedef enum{
	PIN0 = 0,
	PIN1,
	PIN2,
	PIN3,
	PIN4,
	PIN5,
	PIN6,
	PIN7
}EN_PIN;

#define PORT_INPUT  0
#define PORT_OUTPUT 255
#define PIN_INPUT   0
#define PIN_OUTPUT  1

#define SET_PORT    255
#define CLEAR_PORT  0
#define MASK        1

#define INPUT   0
#define OUTPUT  1
#define FLOAT   0
#define PULL_UP 1
#define HIGH    1
#define LOW     0

#define CONC_HELP(b7,b6,b5,b4,b3,b2,b1,b0) 0b##b7##b6##b5##b4##b3##b2##b1##b0
#define CONC(b7,b6,b5,b4,b3,b2,b1,b0) CONC_HELP(b7,b6,b5,b4,b3,b2,b1,b0)

#endif /* DIO_PRIV_H_ */

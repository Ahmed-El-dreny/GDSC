/*
 * DIO_inter.h
 *
 *  Created on: May 4, 2023
 *      Author: ahmed
 */

#ifndef DIO_INTER_H_
#define DIO_INTER_H_

#include "ERROR_ST.h"

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

#define U_DIO_PORTA 0
#define U_DIO_PORTB 1
#define U_DIO_PORTC 2
#define U_DIO_PORTD 3

#define U_DIO_PIN0 0
#define U_DIO_PIN1 1
#define U_DIO_PIN2 2
#define U_DIO_PIN3 3
#define U_DIO_PIN4 4
#define U_DIO_PIN5 5
#define U_DIO_PIN6 6
#define U_DIO_PIN7 7

ES_t DIO_intial(void);

ES_t DIO_PortDir(uint8 portID, uint8 portVal);

ES_t DIO_PortValue(uint8 portID, uint8 portVal);

ES_t DIO_PortToggel(uint8 portID);

ES_t DIO_PortRead(uint8 Port_ID, uint8* pPort_Value);

/**************************************************************************************************/

ES_t DIO_PinDir(uint8 portID, uint8 pin_ID, uint8 pinVal);

ES_t DIO_PinValue(uint8 portID, uint8 pin_ID, uint8 pinVal);

ES_t DIO_PinToggel(uint8 portID, uint8 pinID);

ES_t DIO_PinRead(uint8 PortID, uint8 pinID, uint8* pPin_Value);

#endif /* DIO_INTER_H_ */

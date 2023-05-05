/*
 * DIO_prog.c
 *
 *  Created on: May 4, 2023
 *      Author: ahmed
 */

#ifndef DIO_PRIV_C_
#define DIO_PRIV_C_

#include "STD_types.h"
#include "ERROR_ST.h"
#include "DIO_priv.h"
#include "DIO_config.h"

ES_t DIO_intial(void)
{
    ES_t local_Error_state = ES_NOK;
    DDRA = CONC(PA_PIN7_DIR, PA_PIN6_DIR, PA_PIN5_DIR, PA_PIN4_DIR, PA_PIN3_DIR, PA_PIN2_DIR, PA_PIN1_DIR, PA_PIN0_DIR);
    DDRB = CONC(PB_PIN7_DIR, PB_PIN6_DIR, PB_PIN5_DIR, PB_PIN4_DIR, PB_PIN3_DIR, PB_PIN2_DIR, PB_PIN1_DIR, PB_PIN0_DIR);
    DDRC = CONC(PC_PIN7_DIR, PC_PIN6_DIR, PC_PIN5_DIR, PC_PIN4_DIR, PC_PIN3_DIR, PC_PIN2_DIR, PC_PIN1_DIR, PC_PIN0_DIR);
    DDRD = CONC(PD_PIN7_DIR, PD_PIN6_DIR, PD_PIN5_DIR, PD_PIN4_DIR, PD_PIN3_DIR, PD_PIN2_DIR, PD_PIN1_DIR, PD_PIN0_DIR);

    local_Error_state = ES_OK;
    return local_Error_state;
}


ES_t DIO_PortDir(uint8 portID, uint8 portVal)
{
	 ES_t local_Error_state = ES_NOK;

	 if (portID <= EN_PORTD)
	 {
		 switch(portID)
		 {
		 	 case EN_PORTA:
		 		  DDRA = portVal;
		 		  break;
		 	 case EN_PORTB:
		 		  DDRB = portVal;
		 		  break;
		 	 case EN_PORTC:
		 		  DDRC = portVal;
		 		  break;
		 	 case EN_PORTD:
		 		  DDRD = portVal;
		 		  break;
		 }
		 local_Error_state = ES_OK;
	 }

	 else
	 {
		 local_Error_state = ES_OUT_OF_RANGE;
	 }

	 return local_Error_state;
}


ES_t DIO_PortValue(uint8 portID, uint8 portVal)
{
	 ES_t local_Error_state = ES_NOK;

	 if (portID <= EN_PORTD)
	 {
		 switch(portID)
		 {
		 	 case EN_PORTA:
		 		  PORTA = portVal;
		 		  break;
		 	 case EN_PORTB:
		 		  PORTB = portVal;
		 		  break;
		 	 case EN_PORTC:
		 		  PORTC = portVal;
		 		  break;
		 	 case EN_PORTD:
		 		  PORTD = portVal;
		 		  break;
		 }
		 local_Error_state = ES_OK;
	 }

	 else
	 {
		 local_Error_state = ES_OUT_OF_RANGE;
	 }

	 return local_Error_state;
}


ES_t DIO_PortToggel(uint8 portID)
{
	 ES_t local_Error_state = ES_NOK;

	 if (portID <= EN_PORTD)
	 {
		 switch(portID)
		 {
		 	 case EN_PORTA:
		 		  PORTA = ~PORTA;
		 		  break;
		 	 case EN_PORTB:
		 		  PORTB = ~PORTB;
		 		  break;
		 	 case EN_PORTC:
		 		  PORTC = ~PORTC;
		 		  break;
		 	 case EN_PORTD:
		 		  PORTD = ~PORTD;
		 		  break;
		 }
		 local_Error_state = ES_OK;
	 }

	 else
	 {
		 local_Error_state = ES_OUT_OF_RANGE;
	 }

	 return local_Error_state;
}


ES_t DIO_PortRead(uint8 portID, uint8* PportVal)
{
	 ES_t local_Error_state = ES_NOK;

	 if((PportVal != NULL) && (portID <= EN_PORTD))
	 {
		 switch(portID)
		 {
		 	 case EN_PORTA:
		 		*PportVal = PORTA;
		 		  break;
		 	 case EN_PORTB:
		 		*PportVal = PORTB;
		 		  break;
		 	 case EN_PORTC:
		 		*PportVal = PORTC;
		 		  break;
		 	 case EN_PORTD:
		 		*PportVal = PORTD;
		 		  break;
		 }
		 local_Error_state = ES_OK;
	 }

	 else
	 {
		 if(PportVal == NULL)
			 local_Error_state = ES_NULL_PIONTER;
		 else
			 local_Error_state = ES_OUT_OF_RANGE;
	 }

	 return local_Error_state;
}

/**************************************************************************************************/

ES_t DIO_PinDir(uint8 portID, uint8 pinID, uint8 pinVal)
{
	 ES_t local_Error_state = ES_NOK;

	 if ((portID <= EN_PORTD) && (pinID <= PIN7))
	 {
		 switch(portID)
		 {
		 	 case EN_PORTA:
		 		  DDRA &= ~(MASK << pinID);
		 		  DDRA |= (pinVal << pinID);
		 		  break;
		 	 case EN_PORTB:
		 		  DDRB &= ~(MASK << pinID);
		 		  DDRB |= (pinVal << pinID);
		 		  break;
		 	 case EN_PORTC:
		 		  DDRC &= ~(MASK << pinID);
		 		  DDRC |= (pinVal << pinID);
		 		  break;
		 	 case EN_PORTD:
		 		  DDRD &= ~(MASK << pinID);
		 		  DDRD |= (pinVal << pinID);
		 		  break;
		 }
		 local_Error_state = ES_OK;
	 }

	 else
	 {
		 local_Error_state = ES_OUT_OF_RANGE;
	 }

	 return local_Error_state;
}


ES_t DIO_PinValue(uint8 portID, uint8 pinID, uint8 pinVal)
{
	 ES_t local_Error_state = ES_NOK;

	 if ((portID <= EN_PORTD) && (pinID <= PIN7))
	 {
		 switch(portID)
		 {
		 	 case EN_PORTA:
		 		  PORTA &= ~(MASK << pinID);
		 		  PORTA |= (pinVal << pinID);
		 		  break;
		 	 case EN_PORTB:
		 		  PORTB &= ~(MASK << pinID);
		 		  PORTB |= (pinVal << pinID);
		 		  break;
		 	 case EN_PORTC:
		 		  PORTC &= ~(MASK << pinID);
		 		  PORTC |= (pinVal << pinID);
		 		  break;
		 	 case EN_PORTD:
		 		  PORTD &= ~(MASK << pinID);
		 		  PORTD |= (pinVal << pinID);
		 		  break;
		 }
		 local_Error_state = ES_OK;
	 }

	 else
	 {
		 local_Error_state = ES_OUT_OF_RANGE;
	 }

	 return local_Error_state;
}


ES_t DIO_PinToggel(uint8 portID, uint8 pinID)
{
	 ES_t local_Error_state = ES_NOK;

	 if ((portID <= EN_PORTD) && (pinID <= PIN7))
	 {
		 switch(portID)
		 {
		 	 case EN_PORTA:
		 		  PORTA ^= (MASK << pinID);
		 		  break;
		 	 case EN_PORTB:
		 		  PORTB ^= (MASK << pinID);
		 		  break;
		 	 case EN_PORTC:
		 		  PORTC ^= (MASK << pinID);
		 		  break;
		 	 case EN_PORTD:
		 		  PORTD ^= (MASK << pinID);
		 		  break;
		 }
		 local_Error_state = ES_OK;
	 }

	 else
	 {
		 local_Error_state = ES_OUT_OF_RANGE;
	 }

	 return local_Error_state;
}


ES_t DIO_PinRead(uint8 portID, uint8 pinID, uint8* PpinVal)
{
	 ES_t local_Error_state = ES_NOK;

	 if((PpinVal != NULL) && (portID <= EN_PORTD))
	 {
		 switch(portID)
		 {
		 	 case EN_PORTA:
		 		*PpinVal = ((PORTA >> pinID) & MASK);
		 		  break;
		 	 case EN_PORTB:
		 		*PpinVal = ((PORTB >> pinID) & MASK);
		 		  break;
		 	 case EN_PORTC:
		 		*PpinVal = ((PORTC >> pinID) & MASK);
		 		  break;
		 	 case EN_PORTD:
		 		*PpinVal = ((PORTD >> pinID) & MASK);
		 		  break;
		 }
		 local_Error_state = ES_OK;
	 }

	 else
	 {
		 if(PpinVal == NULL)
			 local_Error_state = ES_NULL_PIONTER;
		 else
			 local_Error_state = ES_OUT_OF_RANGE;
	 }

	 return local_Error_state;
}

#endif /* DIO_PROG_C_ */

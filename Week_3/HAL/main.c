/*
 * main.c
 *
 *  Created on: May 4, 2023
 *      Author: ahmed
 */
#include "STD_types.h"
#include "ERROR_ST.h"
#include "DIO_inter.h"
#include "SW_config.h"
#include "SW_inter.h"
#include "LED_config.h"
#include "LED_inter.h"
#include <avr/io.h>
#include <util/delay.h>

extern SW_t switch_AstrSwitchState[SW_NUM];
//extern LED_t LED_AstrConfig[LED_NUM];
int main(void)
{
	DIO_intial();
	//LEDinit(LED_AstrConfig);
	Switch_enumInit(switch_AstrSwitchState);
	uint8 pin_state;

	while(1)
	{
		Switch_enumGetState(&switch_AstrSwitchState[1], &pin_state);
		if(pin_state == 0)
		{
			DIO_PinValue(U_DIO_PORTA, PIN0, HIGH);
		}
		else

		{
			DIO_PinValue(U_DIO_PORTA, PIN0, LOW);
		}

		return 0;
	}

}

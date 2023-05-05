/*
 * LED_prog.c
 *
 *  Created on: May 4, 2023
 *      Author: ahmed
 */
#include "STD_types.h"
#include "ERROR_ST.h"

#include "LED_priv.h"
#include "LED_config.h"

#include "DIO_inter.h"


ES_t LEDinit(LED_t* Copy_pstrLedConfig)
{
	ES_t local_Error_state = ES_NOK;

	if(Copy_pstrLedConfig != NULL)
	{
		uint8 Local_counter = 0;
		for(Local_counter = 0; Local_counter < LED_NUM; Local_counter++)
		{
			local_Error_state = DIO_PinDir(Copy_pstrLedConfig[Local_counter].LED_PortID, Copy_pstrLedConfig[Local_counter].LED_PinID, OUTPUT);
			if(Copy_pstrLedConfig[Local_counter].LED_Connection == LED_SINK)
			{
				if(Copy_pstrLedConfig[Local_counter].LED_InitState == LED_ON)
				{
					local_Error_state = DIO_PinValue(Copy_pstrLedConfig[Local_counter].LED_PortID, Copy_pstrLedConfig[Local_counter].LED_PinID, LOW);
				}
				else if(Copy_pstrLedConfig[Local_counter].LED_InitState == LED_OFF)
				{
					local_Error_state = DIO_PinValue(Copy_pstrLedConfig[Local_counter].LED_PortID, Copy_pstrLedConfig[Local_counter].LED_PinID, HIGH);
				}
				else
				{
					return ES_OUT_OF_RANGE;
				}
			}
		}
	}
	else
	{
		local_Error_state = ES_NULL_PIONTER;
	}
	return local_Error_state;
}

ES_t LEDON(LED_t* Copy_pstrLedID)
{
	ES_t local_Error_state = ES_NOK;

	if(Copy_pstrLedID != NULL)
	{
		if (Copy_pstrLedID->LED_Connection == LED_SINK)
		{
			local_Error_state = DIO_PinValue(Copy_pstrLedID->LED_PortID, Copy_pstrLedID->LED_PinID, LOW);
		}
		else if(Copy_pstrLedID->LED_Connection == LED_SOURCE)
		{
			local_Error_state = DIO_PinValue(Copy_pstrLedID->LED_PortID, Copy_pstrLedID->LED_PinID, HIGH);
		}
		else
		{
			local_Error_state = ES_OUT_OF_RANGE;
		}
	}
	else
	{
		local_Error_state = ES_NULL_PIONTER;
	}
	return local_Error_state;
}

ES_t LEDOFF(LED_t* Copy_pstrLedID)
{
	ES_t local_Error_state = ES_NOK;

	if(Copy_pstrLedID != NULL)
	{
		if (Copy_pstrLedID->LED_Connection == LED_SINK)
		{
			local_Error_state = DIO_PinValue(Copy_pstrLedID->LED_PortID, Copy_pstrLedID->LED_PinID, LOW);
		}
		else if(Copy_pstrLedID->LED_Connection == LED_SOURCE)
		{
			local_Error_state = DIO_PinValue(Copy_pstrLedID->LED_PortID, Copy_pstrLedID->LED_PinID, HIGH);
		}
		else
		{
			local_Error_state = ES_OUT_OF_RANGE;
		}
	}
	else
	{
		local_Error_state = ES_NULL_PIONTER;
	}
	return local_Error_state;
}

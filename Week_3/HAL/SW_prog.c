/*
 * SW_prog.c
 *
 *  Created on: May 4, 2023
 *      Author: ahmed
 */
#include "STD_types.h"
#include "ERROR_ST.h"

#include "SW_config.h"
#include "SW_priv.h"

#include "DIO_inter.h"

ES_t Switch_enumInit(SW_t* Copy_AstrSwitch)
{
	ES_t local_Error_state = ES_NOK;

	if(Copy_AstrSwitch != NULL)
	{
		uint8 Local_counter = 0;
		for(Local_counter = 0; Local_counter < SW_NUM; Local_counter++)
		{
			local_Error_state = DIO_PinDir(Copy_AstrSwitch[Local_counter].SW_portID, Copy_AstrSwitch[Local_counter].SW_pinID, Copy_AstrSwitch[Local_counter].SW_status);
			local_Error_state = DIO_PinValue(Copy_AstrSwitch[Local_counter].SW_portID, Copy_AstrSwitch[Local_counter].SW_pinID, Copy_AstrSwitch[Local_counter].SW_status);
		}
	}
	else
	{
		local_Error_state = ES_NULL_PIONTER;
	}
	return local_Error_state;
}


ES_t Switch_enumGetState(SW_t* Copy_AstrSwitch ,uint8* Copy_puint8SwState)
{
	ES_t local_Error_state = ES_NOK;

	if((Copy_AstrSwitch != NULL) && (Copy_puint8SwState != NULL))
	{
		local_Error_state = DIO_PinRead(Copy_AstrSwitch->SW_portID, Copy_AstrSwitch->SW_pinID, Copy_puint8SwState);
	}
	else
	{
		local_Error_state = ES_NULL_PIONTER;
	}
	return local_Error_state;
}


/*
 * LED_config.c
 *
 *  Created on: May 4, 2023
 *      Author: ahmed
 */
#include "STD_types.h"
#include "ERROR_ST.h"

#include "DIO_inter.h"
#include "LED_config.h"
#include "LED_priv.h"

LED_t LED_AstrConfig [LED_NUM] =
{
		{U_DIO_PORTA, U_DIO_PIN4, LED_SINK, LED_OFF},
		{U_DIO_PORTB, U_DIO_PIN2, LED_SOURCE, LED_ON},
		{U_DIO_PORTC, U_DIO_PIN1, LED_SOURCE, LED_OFF}
};


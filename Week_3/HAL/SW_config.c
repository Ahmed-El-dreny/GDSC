/*
 * SW_config.c
 *
 *  Created on: May 4, 2023
 *      Author: ahmed
 */
#include "STD_types.h"
#include "SW_priv.h"
#include "SW_config.h"
#include "DIO_inter.h"

SW_t switch_AstrSwitchState[SW_NUM] = {
		{U_DIO_PORTA, U_DIO_PIN4, FLOAT},
		{U_DIO_PORTD, U_DIO_PIN3, PULL_UP},
		{U_DIO_PORTC, U_DIO_PIN5, PULL_UP}
};



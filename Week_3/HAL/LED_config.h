/*
 * LED_config.h
 *
 *  Created on: May 4, 2023
 *      Author: ahmed
 */

#ifndef LED_CONFIG_H_
#define LED_CONFIG_H_

#define LED_NUM 3

typedef struct
{
	uint8 LED_PortID;
	uint8 LED_PinID;
	uint8 LED_Connection;
	uint8 LED_InitState;
}LED_t;

#endif /* LED_CONFIG_H_ */

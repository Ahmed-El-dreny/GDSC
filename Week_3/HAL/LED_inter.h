/*
 * LED_inter.h
 *
 *  Created on: May 4, 2023
 *      Author: ahmed
 */

#ifndef LED_INTER_H_
#define LED_INTER_H_

#include "ERROR_ST.h"

ES_t LEDinit(LED_t* Copy_pstrLedConfig);

ES_t LEDON(LED_t* Copy_pstrLedID);

ES_t LEDOFF(LED_t* Copy_pstrLedID);



#endif /* LED_INTER_H_ */

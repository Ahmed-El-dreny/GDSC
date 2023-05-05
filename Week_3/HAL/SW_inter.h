/*
 * SW_inter.h
 *
 *  Created on: May 4, 2023
 *      Author: ahmed
 */

#ifndef SW_INTER_H_
#define SW_INTER_H_
#include "STD_types.h"
#include "ERROR_ST.h"
#include "SW_config.h"

ES_t Switch_enumInit (SW_t* Copy_AstrSwitch);

ES_t Switch_enumGetState (SW_t* Copy_AstrSwitch, uint8* Copy_puint8SwState);


#endif /* SW_INTER_H_ */

/*=============================================================================
 * Copyright (c) 2019, Leo <lgassman@gmail.com>
 * All rights reserved.
 * License: gpl-3.0 (see LICENSE.txt)
 * Date: 2019/06/30
 * Version: 1.0
 *===========================================================================*/

/*=====[Inclusion of own header]=============================================*/

#include "../inc/ejercicio2Task.h"
 
/*=====[Inclusions of private function dependencies]=========================*/

/*=====[Definition macros of private constants]==============================*/

/*=====[Private function-like macros]========================================*/

/*=====[Definitions of private data types]===================================*/

/*=====[Definitions of external public global variables]=====================*/

/*=====[Definitions of public global variables]==============================*/

/*=====[Definitions of private global variables]=============================*/

/*=====[Prototypes (declarations) of private functions]======================*/

/*=====[Implementations of public functions]=================================*/

// Task implementation


void safeTaskDelayUntil(portTickType * base,  portTickType period);

void safeTaskDelayUntil(portTickType * base,  portTickType period) {
	if(period > 0) {
	      vTaskDelayUntil( base,  period);
	}
	else {
		*base = xTaskGetTickCount();
	}
}

void myTask( void* taskParmPtr )
{

   gpioMap_t led = *((gpioMap_t *)taskParmPtr);

   gpioWrite( led, ON);

   // Send the task to the locked state for 1 s (delay)
//  vTaskDelay( 1000 / portTICK_RATE_MS );

//   gpioWrite( led, OFF );

   portTickType xPeriodicity =  1000 / portTICK_RATE_MS;
   portTickType xLastWakeTime = xTaskGetTickCount();

   int ciclo = 1;

   // ----- Task repeat for ever -------------------------
   while(TRUE) {

      portTickType onPeriodicity =  (ciclo * 100) / portTICK_RATE_MS;
      portTickType offPeriodicity =  (1000 - (ciclo * 100)) / portTICK_RATE_MS;

      gpioWrite( led, ON);

      safeTaskDelayUntil( &xLastWakeTime,  onPeriodicity);

      gpioWrite( led, OFF);

      safeTaskDelayUntil( &xLastWakeTime, offPeriodicity );

      ciclo ++;
      if(ciclo >= 11) {
    	  ciclo = 1;
      }
   }
}

/*=====[Implementations of interrupt functions]==============================*/

/*=====[Implementations of private functions]================================*/


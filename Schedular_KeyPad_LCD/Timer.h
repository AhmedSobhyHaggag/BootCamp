/*
 * Timer.h
 *
 * Created: 2/14/2019 10:35:38 AM
 *  Author: AVE-LAP-032
 */ 


#ifndef TIMER_H_
#define TIMER_H_

#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_types.h"
#include "inc/hw_memmap.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"
#include "driverlib/systick.h"
#include "driverlib/interrupt.h"

#define INIT_COUNT        0
#define COMPARE_VALUE     124

#define TOP       2000
#define HIGH_REG  8

#define HIGH  1

#define TEN_SEC_DELAY  10000

void Set_Call_Back( volatile void (*Ptr) (void) );

void Timer_init_INT();


void DIO_INIT();

#endif /* TIMER_H_ */

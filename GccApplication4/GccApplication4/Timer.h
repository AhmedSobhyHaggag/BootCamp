/*
 * Timer.h
 *
 * Created: 2/14/2019 10:35:38 AM
 *  Author: AVE-LAP-032
 */ 


#ifndef TIMER_H_
#define TIMER_H_
#include "Types.h"


/* Memory Mapping Timer Register*/

#define TCNT0    (*(volatile uint8 *) 0x52)
#define TCCR0    (*(volatile uint8 *) 0x53)
#define MCUCSR   (*(volatile uint8 *) 0x54)
#define MCUCR    (*(volatile uint8 *) 0x55)
#define TIFR     (*(volatile uint8 *) 0x58)
#define TIMSK    (*(volatile uint8 *) 0x59)
#define OCR0     (*(volatile uint8 *) 0x5c)


void timer_init(void);

void timer_delay(uint32 mill);





#endif /* TIMER_H_ */
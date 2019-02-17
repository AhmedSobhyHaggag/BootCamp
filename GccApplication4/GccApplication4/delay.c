/*
 * delay.c
 *
 * Created: 2/13/2019 2:13:07 PM
 *  Author: AVE-LAP-032
 */ 

#include "Types.h"
#include "delay.h"

void delay(uint32 n)
{
	volatile uint32 i;
	
	for (i=0;i<n;i++);

}
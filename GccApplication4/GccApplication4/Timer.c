/*
 * Timer.c
 *
 * Created: 2/14/2019 3:44:00 PM
 *  Author: AVE-LAP-032
 */ 
#include "BitwiseOperations.h"
#include "Memory_Mapped_Register .h"
#include "delay.h"
#include "Timer.h"

void timer_init()
{
	TCCR0=0x8b;
	 
	OCR0=250;
	
	TCNT0=0;
}

void timer_delay(uint32 mill)
{
	uint32 M=0; M=mill;
	while(M>0)
	{
		while(Get_Bit(TIFR,1)==0); Set_Bit(TIFR,1);
		M--;
	}
}
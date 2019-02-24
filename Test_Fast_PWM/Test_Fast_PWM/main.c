/*
 * 7-segment.c
 *
 * Created: 2/18/2019 1:02:36 PM
 * Author : AVE-LAP-032
 */ 



#include <avr/io.h>
#include <util/delay.h>
#include "Timer.h"
#include "DIO.h"
#include <avr/interrupt.h>







void Test_Motor1(uint16 duty)
{
	
	INIT_FPWM(duty);
	
	DIO_WritePin(M1A,LOW);
	DIO_WritePin(M1B,HIGH);
	
	_delay_ms(TEN_SEC_DELAY);
}



int main(void)
{	


 Test_Motor1(HALF_DUTY);
 

}
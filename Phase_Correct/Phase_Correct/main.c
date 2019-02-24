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




void Test_Motor2(uint16 duty)
{
	INIT_Phase_Correct(duty);		 
    DIO_WritePin(M2A,LOW);
	DIO_WritePin(M2B,HIGH);
	_delay_ms(TEN_SEC_DELAY);	 
}






int main(void)
{	
	
  Test_Motor2(HALF_DUTY);

}
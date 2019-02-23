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


uint8  volatile state;


void Test_External_Interrupt()
{
	        INIT_INT2();
	        
	        DIO_SetPinDirection(PB5,OUTPUT);
	        DIO_SetPinDirection(PB6,OUTPUT);
	        DIO_SetPinDirection(PB7,OUTPUT);


	        
	        while(1)
	        {
		        switch(state)
		        {
			        case READY: DIO_WritePin(PB5,HIGH); DIO_WritePin(PB6,LOW);  DIO_WritePin(PB7,LOW); 
			        
			        break;
			        
			        case STEADY: DIO_WritePin(PB6,HIGH); DIO_WritePin(PB5,LOW);  DIO_WritePin(PB7,LOW);
			        
			        break;
			        
			        case GO: DIO_WritePin(PB7,HIGH); DIO_WritePin(PB6,LOW);  DIO_WritePin(PB5,LOW);
			        
			        break;
		        }
	        }
}


ISR(INT2_vect)
{		 
		 if(state==READY) state=STEADY;
		 else if(state==STEADY) state=GO;
		 else if(state==GO) state=READY;
}


int main(void)
{	
	Test_External_Interrupt();
}
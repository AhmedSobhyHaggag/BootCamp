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

#define NO_OF_COMPARES 1000

uint16 volatile Flag =0;

uint8  volatile state;

ISR(TIMER0_COMP_vect) 
{
 Flag++;
 if(Flag==NO_OF_COMPARES)
 {
	 Flag=LOW;
	 if(state==READY) state=STEADY;
	else if(state==STEADY) state=GO;
	else if(state==READY) state=READY;
 }
 
}

DIO_INIT()
{
	DIO_SetPinDirection(PB5,OUTPUT);
	DIO_SetPinDirection(PB6,OUTPUT);
	DIO_SetPinDirection(PB7,OUTPUT);
	DIO_SetPinDirection(PUSH_B1_INT2,INPUT);
	DIO_WritePin(PB5,LOW);
	DIO_WritePin(PB6,LOW);
	DIO_WritePin(PB7,LOW);
	
}

void Test_Internal_Interrupt()
{
/*Initialize Pins as Output and Write Ones*/	
DIO_INIT();	

/*INIT Timer Interrupt*/	
	timer_init_INT();

/*State Machine For All States*/
	while(HIGH)

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

   


int main(void)
{	
	
	Test_Internal_Interrupt();
	
}
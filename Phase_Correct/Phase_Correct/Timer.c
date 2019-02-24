/*
 * Timer.c
 *
 * Created: 2/14/2019 3:44:00 PM
 *  Author: AVE-LAP-032
 */ 
#include "BitwiseOperations.h"
#include "Memory_Mapped_Register .h"
#include "Timer.h"
#include <avr/interrupt.h>


/* Function to initialize Timer in compare match mode interrupt*/
void timer_init_INT()
{
	
	SET_BIT(TIMSK,OCIE0);
	
	
	SET_BIT(TCCR0,FOC0);
	CLEAR_BIT(TCCR0,WGM00);
	CLEAR_BIT(TCCR0,COM01);
	CLEAR_BIT(TCCR0,COM00);
	SET_BIT(TCCR0,WGM01);
	CLEAR_BIT(TCCR0,CS02);
	SET_BIT(TCCR0,CS01);
	SET_BIT(TCCR0,CS00);
		
	OCR0= COMPARE_VALUE; 
	
	TCNT0=INIT_COUNT;
	
	SET_BIT(SREG,GIE);
	
}

/* Function to initialize Motor1 Pins*/
void DIO_INIT_M1()
{
	DIO_SetPinDirection(M1A,OUTPUT);
	DIO_SetPinDirection(M1B,OUTPUT);
	DIO_SetPinDirection(M1_EN_OC1B,OUTPUT);

}


/* Function to initialize Motor2 Pins*/
void DIO_INIT_M2()
{
	DIO_SetPinDirection(M2_EN_OC1A,OUTPUT);
	DIO_SetPinDirection(M2A,OUTPUT);
	DIO_SetPinDirection(M2B,OUTPUT);
}

/* Function to initialize fast PWM*/
void INIT_FPWM(uint16 COMPARE)
{
	    DIO_INIT_M1();
	
		ICR1H=(TOP>>HIGH_REG);
		ICR1L=(TOP);
		
		OCR1AH=(COMPARE>>HIGH_REG);
		OCR1AL=(COMPARE);	
		
		SET_BIT(TCCR1B,CS10);
		
	    SET_BIT(TCCR1A,WGM11);
		SET_BIT(TCCR1B,WGM12);
		SET_BIT(TCCR1B,WGM13);

		SET_BIT(TCCR1A,COM1B0);
		SET_BIT(TCCR1A,COM1B1);
}

/* Function to initialize phase_correct*/
void INIT_Phase_Correct(uint16 COMPARE)
{
	DIO_INIT_M2();
	
   ICR1H=(TOP>>HIGH_REG);
   ICR1L=(TOP);
   
   OCR1AH=(COMPARE>>HIGH_REG);
   OCR1AL=(COMPARE);
   
   SET_BIT(TCCR1B,CS10);
	
   SET_BIT(TCCR1A,WGM11);
   SET_BIT(TCCR1B,WGM13);
	
   SET_BIT(TCCR1A,COM1A0);
   SET_BIT(TCCR1A,COM1A1);
}

/* Function to initialize External INT2*/
void INIT_INT2()
{
 DIO_SetPinDirection(PUSH_B1_INT2,INPUT);
 SET_BIT(GICR,INT2);
 SET_BIT(MCUCSR,ISC2);
 SET_BIT(SREG,GIE);
}


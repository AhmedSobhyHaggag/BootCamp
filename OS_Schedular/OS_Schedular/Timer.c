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

/*Pointer to Function used for calling the Set_Flag Function*/
volatile void (*Call_Back) (void) ;


/*********************************************************************************/
/* NAME:      Set_Call_Back                                                       */
/*DESCRIPTION:Initializes The call back function to be called in ISR Every OS_TICK*/
/*********************************************************************************/
void Set_Call_Back( void (*Ptr) (void) )
{
	Call_Back = Ptr ;
}


/**********************************************************************************/
/* NAME:      Timer_init_INT()                                                    */
/*DESCRIPTION:Function to initialize Timer in compare match mode with    interrupt*/
/**********************************************************************************/
void Timer_init_INT()
{
	/*enable Interrupt at output compare match */
	SET_BIT(TIMSK,OCIE0);
	
	/*NON_PWM mode*/
	SET_BIT(TCCR0,FOC0);
	
	/*set wave form generation mode to CTC */
	CLEAR_BIT(TCCR0,WGM00);
	SET_BIT(TCCR0,WGM01);
	
	/*OC0 pin not used */
	CLEAR_BIT(TCCR0,COM01);
	CLEAR_BIT(TCCR0,COM00);
	
	/*Prescale by 64*/
	CLEAR_BIT(TCCR0,CS02);
	SET_BIT(TCCR0,CS01); 
	SET_BIT(TCCR0,CS00);
	
	/*Set the value of output compare Register */
	OCR0= OS_TICK_INTERVAL_MSEC; 
	
	/*Initilaize the counter register to zero */
	TCNT0= INIT_COUNT ;
	
	/*Enable Global Interrupts in the status Register */
	SET_BIT(SREG,GIE);
	
}

/************************************************************************/
/*NAME:        ISR(TIMER0_COMP_vect)                                    */
/*DESCRIPTION:INTERRUPT Function That call the Set_Flag Function        */
/************************************************************************/
ISR(TIMER0_COMP_vect)
{
	Call_Back(); /*Call The Callback Function Which Is Set_flag Using Pointer to Function*/

}
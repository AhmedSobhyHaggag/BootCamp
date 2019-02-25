/*
 * Tasks.c
 *
 * Created: 2/23/2019 3:28:42 PM
 *  Author: AVE-LAP-032
 */ 
#include "Tasks.h"


/************************************************************************/
/* NAME:Toggle_LED1 ()                                                  */
/* DESCRIPTION:used as task to toggle led1                              */
/************************************************************************/

void Toggle_LED1 ()
{
	TOGGLE_BIT(PORTB,BIT5);	
}

/************************************************************************/
/* NAME:Toggle_LED2 ()                                                  */
/* DESCRIPTION:used as task to toggle led2                              */
/************************************************************************/

void Toggle_LED2 ()
{
	TOGGLE_BIT(PORTB,BIT6);
}

/************************************************************************/
/* NAME:Toggle_LED1 ()                                                  */
/* DESCRIPTION:used as task to toggle led3                              */
/************************************************************************/
void Toggle_LED3 ()
{
	TOGGLE_BIT(PORTB,BIT7);
}

/*************************************************************************************************************/
/* NAME:Check_Button ()                                                                                      */
/* DESCRIPTION:call scheduler_Remove_Task () function in the Schedular to remove a task if button1 is pressed*/
/*************************************************************************************************************/
void Check_Button ()
{
	/* Button1 is pressed remove a task */
	if ( DIO_ReadPin(PUSH_B1_INT2) == HIGH )
	{
		scheduler_Remove_Task ();
	}
	else
	 {
		 
	 };
	
}



/*
 * OS_Schedular.c
 *
 * Created: 2/23/2019 3:27:33 PM
 * Author : AVE-LAP-032
 */ 

#include "Tasks.h"
#include "TTC_Schedular.h"

/************************************************************************/
/* NAME:  DIO_INIT()                                                    */
/* DESCRIPTION:Initialize DIO For Used Pins                             */
/************************************************************************/

void DIO_INIT(void)
{
	/*Initialize led Pins as Output*/
	DIO_SetPinDirection(PB5,OUTPUT);    
	DIO_SetPinDirection(PB6,OUTPUT);
	DIO_SetPinDirection(PB7,OUTPUT);
	
	/*Initialize Button Pin as Input*/
	DIO_SetPinDirection(PUSH_B1_INT2,INPUT);

}


int main(void)
{
   /* Initialize the used pins in the project */
   DIO_INIT();
   
   /*Declare 4 Tasks*/
   
   Task task1,task2,task3,task4;
   
   /*Initialize 3 Tasks to toggle 3 leds*/
   task1.pointer=Toggle_LED1;
   task1.Periodicity=ONE_SECONDS;
   task1.Remain=ONE_SECONDS;
   task1.Priority=FIRST_PRIORITY;
   
   task2.pointer=Toggle_LED2;
   task2.Periodicity=TWO_SECONDS;
   task2.Remain=TWO_SECONDS;
   task2.Priority=SECOND_PRIORITY;
	  
   task3.pointer=Toggle_LED3;
   task3.Periodicity=THREE_SECONDS;
   task3.Remain=THREE_SECONDS;
   task3.Priority=THIRD_PRIORITY;
   
   /* Task 4 Removes Tasks if Button1 is Pressed */
   /*Note that you have to Multipress Button1 so that task one and two  be removed because of their higher priority*/
    task4.pointer=Check_Button;
    task4.Periodicity=ONE_OS_TICK;
	task4.Remain=ONE_OS_TICK;
    task4.Priority=FOURTH_PRIORITY;
   
   /*Pass the above tasks to the scheduler*/
   
   uint8 Result;
   
  Result= scheduler_Add_Task(&task1);
   
  Result=    scheduler_Add_Task(&task2);
	   
  Result= 	    scheduler_Add_Task(&task3);
		   
  Result= 		  scheduler_Add_Task(&task4) ;
  

	  
	   /*Initialize the scheduler*/
	   OS_scheduler_Init ();
	   
	   /*Start the scheduler*/
	   OS_scheduler_Start();
	  

	

		 	
}


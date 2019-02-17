/*
 * GccApplication4.c
 *
 * Created: 2/13/2019 10:56:41 AM
 * Author : AVE-LAP-032
 */ 

//#include <avr/io.h>
#include "Types.h"
#include "BitwiseOperations.h"
#include "Memory_Mapped_Register .h"
#include "delay.h"
#include "Timer.h"


int main(void)
{
	//DIO_SetPinDirection(uint8 PinNum,uint8 PinDirection);
	DIO_SetPinDirection(15,1);
	
    DIO_SetPinDirection(14,1);
	
	DIO_SetPinDirection(13,1);
	
	DIO_SetPinDirection(12,1);
    
	DIO_SetPinDirection(10,0);
	
	uint8 i=0;
	
	DIO_WritePin(13,0);
	DIO_WritePin(14,0);
	DIO_WritePin(15,0);
	    
	uint8 button = 0;	
	
    /* Replace with your application code */
    while (1) 
    {
	
	
	  /* switch(i)
	   {
		   case 0: DIO_WritePin(13,1); DIO_WritePin(14,0);  DIO_WritePin(15,0); delay(500000); i=1; break;
		  case 1: DIO_WritePin(14,1); DIO_WritePin(13,0);  DIO_WritePin(15,0); delay(500000); i=2; break;
		 case 2: DIO_WritePin(15,1); DIO_WritePin(14,0);  DIO_WritePin(13,0); delay(500000); i=0; break;
		   
	   }
		*/
	  if(  DIO_ReadPin(10) == 1 )
	  {
		  timer_delay(50);
		  if(DIO_ReadPin(10) == 1 )
		  {
			button =1;
		   while(DIO_ReadPin(10) == 1 && button==1);
		   if(DIO_ReadPin(10) == 0 && button==1) {i=1; button=0;}
		  }
			  
	  }
	  
	  timer_init();
	  
	   switch(i)
	   {
		   case 0: DIO_WritePin(13,1); DIO_WritePin(14,0);  DIO_WritePin(15,0); timer_delay(1000); i=1; break;
		   case 1: DIO_WritePin(14,1); DIO_WritePin(13,0);  DIO_WritePin(15,0); timer_delay(1000); i=2; break;
		   case 2: DIO_WritePin(15,1); DIO_WritePin(14,0);  DIO_WritePin(13,0); timer_delay(1000); i=0; break;
		   
	   }
		
		/*
		delay(9999999999999);
		
		DIO_WritePin(13,0);
		DIO_WritePin(14,0);
		DIO_WritePin(15,0);

        delay(9999999999999);
   
		DIO_WritePin(13,1);	
		DIO_WritePin(14,0);
		DIO_WritePin(15,0);
		
		delay(9999999999999);
		
		DIO_WritePin(13,0);
		DIO_WritePin(14,1);
		DIO_WritePin(15,0);
		
		delay(9999999999999);
		
		DIO_WritePin(13,0);
		DIO_WritePin(14,0);
		DIO_WritePin(15,1);
		
		delay(9999999999999);*/
		
			 
		 
   
  /* if(  DIO_ReadPin(20) == 1 )
   {
	    delay(100000000);
	      if(  DIO_ReadPin(20) == 1 )
         {
		     DIO_WritePin(14,1);
			 
		     delay(100000000000);
		     
		     DIO_WritePin(14,0);
		 }
	 
   }*/
	
/*	
	DIO_WritePin(15,0);
	delay(500000);
	
	DIO_WritePin(14,1);
	delay(500000);
	
	DIO_WritePin(14,0);
	delay(500000);
	
	DIO_WritePin(13,1);
	delay(500000);
	
	DIO_WritePin(13,0);
	delay(500000);
	
	DIO_WritePin(12,1);
	delay(500000);
	
	DIO_WritePin(12,0);
	delay(500000);*/
		
    }
}


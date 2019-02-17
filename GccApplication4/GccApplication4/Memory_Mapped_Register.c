/*
 * Memory_Mapped_Register.c
 *
 * Created: 2/13/2019 3:08:59 PM
 *  Author: AVE-LAP-032
 */ 
#include "Types.h"
#include "BitwiseOperations.h"
#include "Memory_Mapped_Register .h"




void DIO_WritePin(uint8 PinNum,uint8 PinValue)
{
	if (PinValue ==1)  
	{
		if(PinNum>=0 && PinNum<=7)
		Set_Bit(PORTA,(PinNum));
		
		else if (PinNum>=8 && PinNum<=15)
		Set_Bit(PORTB,(PinNum-8));
		
		else if (PinNum>=16 && PinNum<=23)
		Set_Bit(PORTC,(PinNum-16));
		
		else if (PinNum>=24 && PinNum<=31)
		Set_Bit(PORTD,(PinNum-24));
	}
	
	else if (PinValue ==0)
	{
		if(PinNum>=0 && PinNum<=7)
		Clear_Bit(PORTA,(PinNum));
		
		else if (PinNum>=8 && PinNum<=15)
		Clear_Bit(PORTB,(PinNum-8));
		
		else if (PinNum>=16 && PinNum<=23)
		Clear_Bit(PORTC,(PinNum-16));
		
		else if (PinNum>=24 && PinNum<=31)
		Clear_Bit(PORTD,(PinNum-24));
	}
	
	
}
uint8 DIO_ReadPin(uint8 PinNum)
{
  if(PinNum>=0 && PinNum<=7)
  return (Get_Bit(PinA, PinNum ) );
  
  else if (PinNum>=8 && PinNum<=15)
  return (Get_Bit(PinB,(PinNum- 8) ) );
  
  else if (PinNum>=16 && PinNum<=23)
  return (Get_Bit(PinC,(PinNum- 16 ) ) );
  
  else if (PinNum>=24 && PinNum<=31)
  return (Get_Bit(PinD, (PinNum- 24 ) ) );
  }
  
void DIO_SetPinDirection(uint8 PinNum,uint8 PinDirection)
{
		if (PinDirection ==1)
		{
			if(PinNum>=0 && PinNum<=7)
			Set_Bit(DDRA,(PinNum) );
			
			else if (PinNum>=8 && PinNum<=15)
			Set_Bit(DDRB,(PinNum-8) );
			
			else if (PinNum>=16 && PinNum<=23)
			Set_Bit(DDRC,(PinNum-16) );
			
			else if (PinNum>=24 && PinNum<=31)
			Set_Bit(DDRD,(PinNum-24) );
		}
		
		else if (PinDirection == 0)
		{
			if(PinNum>=0 && PinNum<=7)
			Clear_Bit(DDRA,PinNum);
			
			else if (PinNum>=8 && PinNum<=15)
			Clear_Bit(DDRB,(PinNum-8));
			
			else if (PinNum>=16 && PinNum<=23)
			Clear_Bit(DDRC,(PinNum-16));
			
			else if (PinNum>=24 && PinNum<=31)
			Clear_Bit(DDRD,(PinNum-24));
		}
}
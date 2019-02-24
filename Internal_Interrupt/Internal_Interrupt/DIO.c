/*
 * DIO.c
 *
 * Created: 2/18/2019 1:13:07 PM
 *  Author: AVE-LAP-032
 */ 
#include "DIO.h"

void DIO_WritePin(uint8 PinNum,uint8 PinValue)
{
	if (PinValue == HIGH)
	{
		if(PinNum>=PA0 && PinNum<=PA7)
		SET_BIT(PORTA,(PinNum));
		
		else if (PinNum>=PB0 && PinNum<=PB7)
		SET_BIT(PORTB,(PinNum-PB0));
		
		else if (PinNum>=PC0 && PinNum<=PC7)
		SET_BIT(PORTC,(PinNum-PC0));
		
		else if (PinNum>=PD0 && PinNum<=PD7)
		SET_BIT(PORTD,(PinNum-PD0));
	}
	
	else if (PinValue ==LOW)
	{
		if(PinNum>=PA0 && PinNum<=PA7)
		CLEAR_BIT(PORTA,(PinNum));
		
		else if (PinNum>=PB0 && PinNum<=PB7)
		CLEAR_BIT(PORTB,(PinNum-PB0));
		
		else if (PinNum>=PC0 && PinNum<=PC7)
		CLEAR_BIT(PORTC,(PinNum-PC0));
		
		else if (PinNum>=PD0 && PinNum<=PD7)
		CLEAR_BIT(PORTD,(PinNum-PD0));
	}
	
	
}
uint8 DIO_ReadPin(uint8 PinNum)
{
	if(PinNum>=PA0 && PinNum<=PA7)
	return (GET_BIT(PINA, PinNum ) );
	
	else if (PinNum>=PB0 && PinNum<=PB7)
	return (GET_BIT(PINB,(PinNum-PB0) ) );
	
	else if (PinNum>=PC0 && PinNum<=PC7)
	return (GET_BIT(PINC,(PinNum-PC0 ) ) );
	
	else if (PinNum>=PD0 && PinNum<=PD7)
	return (GET_BIT(PIND, (PinNum-PD0 ) ) );
}

void DIO_SetPinDirection(uint8 PinNum,uint8 PinDirection)
{
	if (PinDirection == OUTPUT)
	{
		if(PinNum>=PA0 && PinNum<=PA7)
		SET_BIT(DDRA,(PinNum) );
		
		else if (PinNum>=PB0 && PinNum<=PB7)
		SET_BIT(DDRB,(PinNum-PB0) );
		
		else if (PinNum>=PC0 && PinNum<=PC7)
		SET_BIT(DDRC,(PinNum-PC0) );
		
		else if (PinNum>=PD0 && PinNum<=PD7)
		SET_BIT(DDRD,(PinNum-PD0) );
	}
	
	else if (PinDirection == INPUT)
	{
		if(PinNum>=PA0 && PinNum<=PA7)
		CLEAR_BIT(DDRA,PinNum);
		
		else if (PinNum>=PB0 && PinNum<=PB7)
		CLEAR_BIT(DDRB,(PinNum-PB0));
		
		else if (PinNum>=PC0 && PinNum<=PC7)
		CLEAR_BIT(DDRC,(PinNum-PC0));
		
		else if (PinNum>=PD0 && PinNum<=PD7)
		CLEAR_BIT(DDRD,(PinNum-PD0));
	}
}
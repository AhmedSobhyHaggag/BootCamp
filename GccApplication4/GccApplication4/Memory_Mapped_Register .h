/*
 * Memory_Mapped_Register_.h
 *
 * Created: 2/13/2019 2:28:29 PM
 *  Author: AVE-LAP-032
 */ 


#ifndef MEMORY_MAPPED_REGISTER _H_
#define MEMORY_MAPPED_REGISTER _H_

#include "Types.h"

#define PORTA   (*(volatile uint8 *) 0x3B)
#define DDRA    (*(volatile uint8 *) 0x3A)
#define PinA    (*(volatile uint8 *) 0x39)

#define PORTB   (*(volatile uint8 *) 0x38)
#define DDRB    (*(volatile uint8 *) 0x37)
#define PinB    (*(volatile uint8 *) 0x36)

#define PORTC   (*(volatile uint8 *) 0x35)
#define DDRC    (*(volatile uint8 *) 0x34)
#define PinC    (*(volatile uint8 *) 0x33)

#define PORTD   (*(volatile uint8 *) 0x32)
#define DDRD    (*(volatile uint8 *) 0x31)
#define PinD    (*(volatile uint8 *) 0x30)


void DIO_WritePin(uint8 PinNum,uint8 PinValue);
uint8 DIO_ReadPin(uint8 PinNum);
void DIO_SetPinDirection(uint8 PinNum,uint8 PinDirection);


#endif /* MEMORY_MAPPED_REGISTER _H_ */
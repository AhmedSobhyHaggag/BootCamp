/*
 * DIO.h
 *
 * Created: 2/18/2019 1:13:25 PM
 *  Author: AVE-LAP-032
 */ 


#ifndef DIO_H_
#define DIO_H_

#include "Types.h"
#include "BitwiseOperations.h"
#include "Types.h"
#include "BitwiseOperations.h"
#include "Memory_Mapped_Register .h"

#define HIGH         1
#define LOW          0
#define INPUT        0
#define OUTPUT       1

#define PA0 0
#define PA1 1
#define PA2 2
#define PA3 3
#define PA4 4
#define PA5 5
#define PA6 6
#define PA7 7

#define PB0 8
#define PB1 9
#define PB2 10
#define PB3 11
#define PB4 12
#define PB5 13
#define PB6 14
#define PB7 15

#define PC0 16
#define PC1 17
#define PC2 18
#define PC3 19
#define PC4 20
#define PC5 21
#define PC6 22
#define PC7 23

#define PD0 24
#define PD1 25
#define PD2 26
#define PD3 27
#define PD4 28
#define PD5 29
#define PD6 30
#define PD7 31

void DIO_WritePin(uint8 PinNum,uint8 PinValue);

uint8 DIO_ReadPin(uint8 PinNum);

void DIO_SetPinDirection(uint8 PinNum,uint8 PinDirection);

#endif /* DIO_H_ */
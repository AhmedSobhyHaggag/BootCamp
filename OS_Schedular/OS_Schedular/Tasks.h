/*
 * Tasks.h
 *
 * Created: 2/23/2019 3:28:25 PM
 *  Author: AVE-LAP-032
 */ 


#ifndef TASKS_H_
#define TASKS_H_

#include "BitwiseOperations.h"
#include "DIO.h"
#include "Memory_Mapped_Register .h"
#include "Timer.h"



#define MAX_NO_OF_TASKS 4

/*Toggle Bits*/
#define BIT5 5
#define BIT6 6
#define BIT7 7

void Toggle_LED1 (void);

void Toggle_LED2 (void);

void Toggle_LED3 (void);

void Check_Button (void);


#endif /* TASKS_H_ */
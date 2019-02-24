/*
 * Timer.h
 *
 * Created: 2/14/2019 10:35:38 AM
 *  Author: AVE-LAP-032
 */ 


#ifndef TIMER_H_
#define TIMER_H_
#include "Types.h"
#include "BitwiseOperations.h"
#include "DIO.h"

/*Timer 0*/
#define TCNT0    (*(volatile uint8 *) 0x52)
#define TCCR0    (*(volatile uint8 *) 0x53)
#define MCUCR    (*(volatile uint8 *) 0x55)
#define TIFR     (*(volatile uint8 *) 0x58)
#define TIMSK    (*(volatile uint8 *) 0x59)
#define OCR0     (*(volatile uint8 *) 0x5c)

#define INIT_COUNT        0
#define COMPARE_VALUE     124

#define TOP       2000
#define HIGH_REG  8

#define TEN_SEC_DELAY  10000

#define Quarter_DUTY        500
#define HALF_DUTY           1000
#define THREE_Quarters_DUTY  1500

/*Timer 1*/
#define TCCR1A   (*(volatile uint8 *) 0x4F)
#define TCCR1B   (*(volatile uint8 *) 0x4E)
#define TCNT1H   (*(volatile uint8 *) 0x4D)
#define TCNT1L   (*(volatile uint8 *) 0x4C)
#define OCR1AH   (*(volatile uint8 *) 0x4B)
#define OCR1AL   (*(volatile uint8 *) 0x4A)
#define OCR1BH   (*(volatile uint8 *) 0x49)
#define OCR1BL   (*(volatile uint8 *) 0x48)
#define ICR1H    (*(volatile uint8 *) 0x47)
#define ICR1L    (*(volatile uint8 *) 0x46)

/*Motor signals*/
#define M1A              26
#define M1B              27
#define M1_EN_OC1B       28
#define M2_EN_OC1A       29
#define M2A              30
#define M2B              31 

/*TCCRA1*/
#define COM1A1  7
#define COM1A0  6
#define COM1B1  5
#define COM1B0  4
#define FOC1A   3
#define FOC1B   2
#define WGM11   1
#define WGM10   0

/*TCCR1B*/
#define ICNC1 7
#define ICES1 6
#define WGM13 4
#define WGM12 3
#define CS12 2
#define CS11 1
#define CS10 0

#define SREG     (*(volatile uint8 *) 0x5F)

/*TCCR0*/
#define CS00    0
#define CS01    1
#define CS02    2
#define WGM01   3
#define COM00   4
#define COM01   5
#define WGM00   6
#define FOC0    7


#define OCIE0        1
#define GIE          7

#define HIGH         1
#define LOW          0
#define INPUT        0
#define OUTPUT       1

#define BIT1         1

/*EXTERNAL INTTERUPT 2 PIN*/
#define PUSH_B1_INT2      10


/*GICR*/
#define  GICR            (*(volatile uint8 *) 0x5B)
#define  INT1           0
#define  INT0           1
#define  INT2           2
#define  IVSEL          6
#define  IVCE           7

/*MCUCSR*/
#define MCUCSR           (*(volatile uint8 *) 0x54)
#define JTD             0
#define ISC2            1


void timer_init(void);

void timer_delay(uint32 mil);

void timer_init_INT();

void timer_init_poll();

void INIT_INT2();

void DIO_INIT();

void INIT_FPWM(uint16 COMPARE);

void INIT_Phase_Correct(uint16 COMPARE);

#endif /* TIMER_H_ */
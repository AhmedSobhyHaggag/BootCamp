/*
 * Tasks.c
 *
 * Created: 2/23/2019 3:28:42 PM
 *  Author: AVE-LAP-032
 */ 
#include "Tasks.h"
#include "driverlib/sysctl.h"



#define RED_LED   GPIO_PIN_1
#define BLUE_LED  GPIO_PIN_2
#define GREEN_LED GPIO_PIN_3

void Toggle_RED (void)
{
       GPIOPinWrite(GPIO_PORTF_BASE, RED_LED|BLUE_LED|GREEN_LED, RED_LED);

       SysCtlDelay(2000000);

       GPIOPinWrite(GPIO_PORTF_BASE, RED_LED|BLUE_LED|GREEN_LED, ZERO);

       SysCtlDelay(2000000);
}


void Toggle_BLUE (void)
{
       GPIOPinWrite(GPIO_PORTF_BASE, RED_LED|BLUE_LED|GREEN_LED, BLUE_LED);

       SysCtlDelay(2000000);

       GPIOPinWrite(GPIO_PORTF_BASE, RED_LED|BLUE_LED|GREEN_LED, ZERO);

       SysCtlDelay(2000000);
}

void Toggle_GREEN (void)
{
       GPIOPinWrite(GPIO_PORTF_BASE, RED_LED|BLUE_LED|GREEN_LED, GREEN_LED);

       SysCtlDelay(2000000);

       GPIOPinWrite(GPIO_PORTF_BASE, RED_LED|BLUE_LED|GREEN_LED, ZERO);

       SysCtlDelay(2000000);
}


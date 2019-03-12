


#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_types.h"
#include "inc/hw_memmap.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"
#include "driverlib/systick.h"
#include "driverlib/interrupt.h"
#include "TTC_Schedular.h"
#include "Tasks.h"


#define RED_LED   GPIO_PIN_1
#define BLUE_LED  GPIO_PIN_2
#define GREEN_LED GPIO_PIN_3


void main ()
{

    //
       // Enable and wait for the port to be ready for access
       //
       SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);

       while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOF))
       {
       }

       //
       // Configure the GPIO port for the LED operation.
       //
       GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, RED_LED|BLUE_LED|GREEN_LED);


//       Timer_init_INT();

      Task task1,task2,task3;


         task1.pointer=Toggle_RED;
         task1.Periodicity=ONE_SECONDS;
         task1.Remain=ONE_SECONDS;
         task1.Priority=FIRST_PRIORITY;

         task2.pointer=Toggle_BLUE;
         task2.Periodicity=TWO_SECONDS;
         task2.Remain=TWO_SECONDS;
         task2.Priority=SECOND_PRIORITY;

         task3.pointer=Toggle_GREEN;
         task3.Periodicity=THREE_SECONDS;
         task3.Remain=THREE_SECONDS;
         task3.Priority=THIRD_PRIORITY;

       scheduler_Add_Task(&task1);

       scheduler_Add_Task(&task2);

       scheduler_Add_Task(&task3);

       OS_scheduler_Init ();

       OS_scheduler_Start();


       while(1)
       {

     /*  GPIOPinWrite(GPIO_PORTF_BASE, RED_LED|BLUE_LED|GREEN_LED, RED_LED);

       SysCtlDelay(200000);

       GPIOPinWrite(GPIO_PORTF_BASE, RED_LED|BLUE_LED|GREEN_LED, ZERO);

       SysCtlDelay(200000);*/
       }


}



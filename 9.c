#include <stdio.h>
#include "NUC1xx.h"
#include "Driver\DrvSYS.h"
#include "Driver\DrvGPIO.h"
#include "NUC1xx-LB_002\LCD_Driver.h"


int main (void)
{
int32_t number,n;volatile int32_t irqA_counter = 0;
    char TEXT0[16]="SmplKeypad";

char TEXT1[16];
    UNLOCKREG();                // unlock register for programming
  DrvSYS_Open(48000000);// set System Clock to run at 48MHz
                          // 12MHz crystal input, PLL output 48MHz
    LOCKREG();                    // lock register from programming

        // Initialize LEDs (four on-board LEDs below LCD panel)   
Initial_panel();
    clr_all_panel();   
       
    print_lcd(0,TEXT0); // print title
   
    while (1)                   // forever loop to keep flashing four LEDs one at a time
    {number=DrvGPIO_GetPortBits(E_GPA);
           
     sprintf(TEXT1,"%x",number); // print scankey input to string             
n=DrvGPIO_GetPortBits(E_GPC);
        print_lcd(1,TEXT1);

if(  number!=0xffff){
    //volatile uint32_t
    print_lcd(3,"s");
    irqA_counter++;sprintf(TEXT1,"%d",irqA_counter);print_lcd(2,TEXT1); }
//print_lcd(2,irqA_counter);}

if( n!=0xffff)
{
    DrvGPIO_Open(E_GPB, 11, E_IO_OUTPUT); // initial GPIO pin GPB11 for controlling Buzzer

   
  DrvGPIO_ClrBit(E_GPB,11); // GPB11 = 0 to turn on Buzzer
    DrvSYS_Delay(100000);        // Delay
    DrvGPIO_SetBit(E_GPB,11); // GPB11 = 1 to turn off Buzzer   
    DrvSYS_Delay(100000);        // Delay        
   

    }

    }
    DrvSYS_Delay(1000);
    }


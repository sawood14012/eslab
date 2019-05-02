

#include <stdio.h>																											 
#include "NUC1xx.h"
#include "Driver\DrvSYS.h"
#include "DrvPWM.h"
#include "DrvADC.h"
#include "LCD_Driver.h"
	 
 int32_t main (void)
{  char value[15];  
    			   
	
	UNLOCKREG();
	SYSCLK->PWRCON.XTL12M_EN = 1; 	//Enable 12Mhz and set HCLK->12Mhz
	SYSCLK->CLKSEL0.HCLK_S = 0;
	LOCKREG();
	//InitPWM();
	

	
	
	Initial_panel();  // initialize LCD pannel
  clr_all_panel();  // clear LCD panel 
  print_lcd(0,"variable reistor");

//DOUBT WHERE IS C15 ?
	
  

while(1)
   {
   int x=0xffff;
     PWMA->CMR0=x;
		 
		 
    DrvSYS_Delay(5000);
    x=x-1;
    }


}				 	
	 


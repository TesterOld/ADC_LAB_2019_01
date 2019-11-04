#include "delay.h"
#include "ADC.h"
#include "tm1637.h"
//ADS test and display to Tm 1637
// Display Tm 1637 shuld be:GNG-GND, VCC-5v, DIO - B6, CLC - B7

//// Two GPIO for SPI emul //GPIO_Pin_6|GPIO_Pin_7;//GPIOB


//A1 - ADC



unsigned int digit_display0 = 0;
unsigned int digit_display2 = 2222;
unsigned int ads_display =7777;



int main()
{
 	ADC_init();
  delay_ms(10);
	GPIOC_init_13_o ();
	TM1637_init();	
  TM1637_brightness(BRIGHT_TYPICAL); 
	delay_ms(10);
	TM1637_display_all(digit_display0);
	delay_ms(1000);
  TM1637_display_all(ads_display);
	delay_ms(1000);
	
	while (1)
	{
   TM1637_clearDisplay(); 
   delay_ms(1000);
   ads_display=ADC_read();
   delay_ms(10);
	 TM1637_display_all(ads_display);
	 delay_ms(1000);
	}
}



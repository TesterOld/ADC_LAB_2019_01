#include "buffer.h"
#include "delay.h"
#include "buffer.h"
#include "tm1637.h"
// Test buffer and display
// Display Tm 1637 shuld be:GNG-GND, VCC-5v, DIO - B6, CLC - B7

//#define BUF_SIZE_128 128
//#define BUF_SIZE_64  64
//#define BUF_SIZE_16  16
//#define BUF_SIZE_8   8
//#define BUF_SIZE_4   4
//// Two GPIO for SPI emul //GPIO_Pin_6|GPIO_Pin_7;//GPIOB



unsigned int digit_display0 = 0;
unsigned int digit_display2 = 2222;




int main()
{

	TM1637_init();	
  TM1637_brightness(BRIGHT_TYPICAL); 
	delay_ms(10);
	TM1637_display_all(digit_display0);
	delay_ms(1000);
	TM1637_display_all(digit_display2);
	delay_ms(1000);
	for (int i=0; i<BUF_SIZE_8; i++)
	{
			buffer_add(i);
	}

	while (1)
	{
		TM1637_display_all(buffer_read()); 
		delay_ms(300);
	}
}



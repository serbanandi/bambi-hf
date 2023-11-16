#include "em_device.h"
#include "em_chip.h"
#include "em_cmu.h"
#include "em_timer.h"
#include "em_lcd.h"
#include "bsp.h"
#include "bsp_stk_buttons.h"
#include "gpiointerrupt.h"
#include "button.h"
#include "segmentlcd.h"
#include "segmentlcd_individual.h"
#include "init_game.h"
#include "lcd.h"
#include "timer.h"

SegmentLCD_UpperCharSegments_TypeDef upperCharSegments[SEGMENT_LCD_NUM_OF_UPPER_CHARS];
SegmentLCD_LowerCharSegments_TypeDef lowerCharSegments[SEGMENT_LCD_NUM_OF_LOWER_CHARS];

void Init(void)
{

  CHIP_Init();
  BSP_ButtonsInit();

  /* Enable LCD without voltage boost */
  SegmentLCD_Init(false);
  SegmentLCD_AllOff();

  /* Register callbacks before setting up and enabling pin interrupt. */
  GPIOINT_CallbackRegister(9, btnCallback);
  GPIOINT_CallbackRegister(10, btnCallback);

  /* Enable interrupt in core for even and odd GPIO interrupts */
  NVIC_ClearPendingIRQ(GPIO_EVEN_IRQn);
  NVIC_EnableIRQ(GPIO_EVEN_IRQn);

  NVIC_ClearPendingIRQ(GPIO_ODD_IRQn);
  NVIC_EnableIRQ(GPIO_ODD_IRQn);

  //NVIC_SetPriority(SysTick_IRQn, 2);

  /* Set falling edge interrupt for both ports */
  GPIO_IntConfig(gpioPortB, 9, false, true, true);
  GPIO_IntConfig(gpioPortB, 10, false, true, true);

  //initTimer(1.0);
  /* Setup SysTick Timer for 1 msec interrupts  */
  if (SysTick_Config(CMU_ClockFreqGet(cmuClock_CORE) / 1000)) {
	while (1) ;
  }

}

int main(void)
{
	/* Chip errata */
	Init();

	while(!game_started)
	{
		LCD_display();
	}
	//Init_Timer(1000-level*100);
	while(1)
	{

		switch (banana_y)
		{
		case 3:
		  if(banana_x == basket)
			  result = result+100;
		  else
			  result = result + 1;
		  banana_y = 4;
		  break;
		case 4:
			banana_x = next_x;
			break;
		default: break;
		}
		if(result >= 2500)
			break;
		LCD_display();
		Delay(100);
	}
	LCD_display();
	SegmentLCD_Symbol(LCD_SYMBOL_GECKO,1);
	while(1);
}

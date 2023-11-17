#include "em_device.h"
#include "em_chip.h"
#include "em_cmu.h"
#include "em_timer.h"
#include "em_lcd.h"
#include "em_gpio.h"

#include "bsp.h"
#include "bsp_stk_buttons.h"
#include "gpiointerrupt.h"
#include "segmentlcd.h"
#include "segmentlcd_individual.h"

#include "init_game.h"
#include "button.h"
#include "lcd.h"
#include "timer.h"

SegmentLCD_UpperCharSegments_TypeDef upperCharSegments[SEGMENT_LCD_NUM_OF_UPPER_CHARS];
SegmentLCD_LowerCharSegments_TypeDef lowerCharSegments[SEGMENT_LCD_NUM_OF_LOWER_CHARS];

void Init(void)
{
	//Chip inicializalasa
	CHIP_Init();
	//Gombok inicializalasa
	BSP_ButtonsInit();

	// LCD incializalasa ás kikapcsolasa
	SegmentLCD_Init(false);
	SegmentLCD_AllOff();

	// Gombokhoz tartozo callback fuggveny regisztralasa
	GPIOINT_CallbackRegister(9, btnCallback);
	GPIOINT_CallbackRegister(10, btnCallback);

	//Paros es paratlan GPIO interruptok torlese és engedelyezese
	NVIC_ClearPendingIRQ(GPIO_EVEN_IRQn);
	NVIC_EnableIRQ(GPIO_EVEN_IRQn);

	NVIC_ClearPendingIRQ(GPIO_ODD_IRQn);
	NVIC_EnableIRQ(GPIO_ODD_IRQn);


	//Gombok lenyomasara erzekeny interruptok bekonfiguralasa
	GPIO_IntConfig(gpioPortB, 9, false, true, true);
	GPIO_IntConfig(gpioPortB, 10, false, true, true);

	// SysTick timer konfiguralasa ms-es megszakitasok kiadasara
	if (SysTick_Config(CMU_ClockFreqGet(cmuClock_CORE) / 1000)) {
		while (1) ;
	}

}

int main(void)
{
	//Inicializalas
	Init();

	//A PB1 gomb lenyomasaig csak meg kell jeleniteni a kezdokepernyot
	while(!game_started)
	{
		LCD_display();
		Delay_ms(100);
	}
	//A jatek addig tart, amig 25 banan le nem esett
	while(score/100 + score%100 < 25)
	{
		switch (banana_y)
		{
			case 3: 				//banan leert
				if(banana_x == basket)	//elkaptuk
					score = score+100;
				else					//nem kaptuk el
					score = score + 1;
				banana_y = 4;			//virtualis allapot hogy csak egyszer noveljuk a pontokat
				break;
			case 4:
				banana_x = next_x;		//random ertek felvetele
				break;
			default: break;
		}
		LCD_display();	//megjelenites
		Delay_ms(100);
	}
	//jatek vege
	LCD_display();
	SegmentLCD_Symbol(LCD_SYMBOL_GECKO,1);
	SegmentLCD_Write(" E N D ");
	while(1);
}

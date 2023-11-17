/*
 * button.c
 *
 *  Created on: 2023. nov. 15.
 *      Author: Petra
 *
 *  Gombokat kezelo callback fuggveny
 */
#include "em_device.h"
#include "em_chip.h"
#include "em_cmu.h"
#include "em_gpio.h"

#include "bsp_stk_buttons.h"
#include "bsp.h"

#include "button.h"
#include "init_game.h"


#if defined( BSP_GPIO_BUTTONS )

//gombok lenyomasakor meghivodo callback fuggveny, Init() regisztralja
void btnCallback(uint8_t pin)
{
	if(!game_started)	//meg nem inditottuk el a jatekot
	{
		if (pin == 9)	//PB0
		{
			level = level==7 ? 0 : level+1; //szint novelese, atfordul
		}
		if(pin == 10)	//PB1
		{
			game_started = true; //jatek indul
		}

	}
	else	//mar megy a jatek
	{
		if (pin == 9)	//PB0
		{
			basket = basket==0 ? 0 : basket-1;	//balra, nem fordul at
		}
		if(pin == 10)	//PB1
		{
			basket = basket==3 ? 3 : basket+1;	//jobbra, nem fordul at
		}

	}
}

#endif  /* BSP_GPIO_BUTTONS */




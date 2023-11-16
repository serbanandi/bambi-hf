
#include "em_device.h"
#include "em_chip.h"
#include "em_cmu.h"
#include "em_gpio.h"
#include "bsp_stk_buttons.h"
#include "bsp.h"
#include "button.h"
#include "init_game.h"


#if defined( BSP_GPIO_BUTTONS )

void btnCallback(uint8_t pin)
{
	if(!game_started)
	{
		if (pin == 9)
		{
			level = level==7 ? 0 : level+1;
		}
		if(pin == 10)
		{
			game_started = true;
		}

	}
	else
	{
		if (pin == 9)
		{
			basket = basket==0 ? 0 : basket-1;
		}
		if(pin == 10)
		{
			basket = basket==3 ? 3 : basket+1;
		}

	}
}

#endif  /* BSP_GPIO_BUTTONS */




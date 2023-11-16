#include <stdint.h>
#include <stdbool.h>
#include "em_device.h"
#include "em_chip.h"
#include "em_cmu.h"
#include "bsp.h"
#include "em_timer.h"
#include "init_game.h"
#include "timer.h"

volatile uint32_t msTicks; /* counts 1ms timeTicks */

/***************************************************************************//**
 * @brief SysTick_Handler
 *   Interrupt Service Routine for system tick counter
 * @note
 *   No wrap around protection
 ******************************************************************************/
void SysTick_Handler(void)
{
	if (msTicks%(1000-level*100) == 0){
		if (game_started)
			banana_y = banana_y == 4 ? 0 : banana_y+1;
	}
	msTicks++;       /* increment counter necessary in Delay()*/


	next_x = (msTicks/7)%4;
}

/***************************************************************************//**
 * @brief Delays number of msTick Systicks (typically 1 ms)
 * @param dlyTicks Number of ticks to delay
 ******************************************************************************/
void Delay(uint32_t dlyTicks)
{
  uint32_t curTicks;

  curTicks = msTicks;
  while ((msTicks - curTicks) < dlyTicks) ;
}


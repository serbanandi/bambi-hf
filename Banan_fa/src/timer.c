/*
 * timer.c
 *
 *  Created on: 2023. nov. 15.
 *      Author: Petra
 *
 *  Idoziteshez szukseges fuggvenyek
 */
#include <stdint.h>
#include <stdbool.h>

#include "em_device.h"
#include "em_chip.h"
#include "em_cmu.h"
#include "em_timer.h"

#include "bsp.h"

#include "init_game.h"
#include "timer.h"

//LCD peldaprogramban atvett kod, ms-enkent meghivodo timer interruptot general, ezt hasznalja a Delay_ms fuggveny impelementaciojahoz is

volatile uint32_t msTicks; /* counts 1ms timeTicks */

/***************************************************************************//**
 * @brief SysTick_Handler
 *   Interrupt Service Routine for system tick counter
 * @note
 *   No wrap around protection
 ******************************************************************************/
void SysTick_Handler(void)	//ms-enkent hivodik meg
{
	if (msTicks%(1000-level*100) == 0){		//nehezsegtol fuggo gyakorisag
		if (game_started)
			banana_y = banana_y == 4 ? 0 : banana_y+1; //bana egy szegmenssel lejjebb esik
	}
	msTicks++;       //delayhez, random generalashoz szukseges

	next_x = (msTicks/7)%4;	//"random" leendo pozicio
}

/***************************************************************************//**
 * @brief Delays number of msTick Systicks (typically 1 ms)
 * @param dlyTicks Number of ticks to delay
 ******************************************************************************/
void Delay_ms(uint32_t dlyTicks)
{
  uint32_t curTicks;

  curTicks = msTicks;
  while ((msTicks - curTicks) < dlyTicks) ;
}


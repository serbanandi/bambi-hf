/*
 * init_game.c
 *
 *  Created on: 2023. nov. 15.
 *      Author: Petra
 *
 *  Jatek adatait tartalmazo globalis valtozok, interruptok modositjak, kirajzolo fuggveny hasznalja
 */
#include <stdbool.h>
#include <stdint.h>
#include "init_game.h"

volatile bool game_started = false;		//false: nehezseg allitasa, true: jatek
volatile uint8_t level = 0;				//nehezseg: 0-7
volatile uint16_t score = 0;			//pontszam: /100 - elkapott, %100 - elejtett
volatile uint8_t banana_x = 0;			//banan melyik digiten esik le: 0-3
volatile uint16_t banana_y = 0;			//banan hol tart az esesben: 0-3, 4 (virtualis)
volatile uint8_t basket = 0;			//kosar melyik digiten van
volatile uint8_t next_x = 0;			//kovetkezo banan pozicioja, random

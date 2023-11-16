/*
 * init_game.c
 *
 *  Created on: 2023. nov. 15.
 *      Author: Petra
 */
#include <stdbool.h>
#include <stdint.h>
#include "init_game.h"

volatile bool game_started = false;
volatile uint8_t level = 0;
volatile uint16_t result = 0;
volatile uint8_t banana_x = 0;
volatile uint16_t banana_y = 0;
volatile uint8_t basket = 0;
volatile uint8_t next_x = 0;

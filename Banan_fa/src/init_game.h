/*
 * init_game.h
 *
 *  Created on: 2023. nov. 15.
 *      Author: Petra
 */

#ifndef SRC_INIT_GAME_H_
#define SRC_INIT_GAME_H_

volatile bool game_started;
volatile uint8_t level;
volatile uint16_t score;
volatile uint8_t banana_x;
volatile uint16_t banana_y;
volatile uint8_t basket;
volatile uint8_t next_x;

#endif /* SRC_INIT_GAME_H_ */

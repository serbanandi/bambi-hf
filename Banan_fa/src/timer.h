/*
 * timer.h
 *
 *  Created on: 2023. nov. 16.
 *      Author: Petra
 */

#ifndef SRC_TIMER_H_
#define SRC_TIMER_H_

volatile uint32_t msTicks;
void SysTick_Handler(void);
void Delay_ms(uint32_t dlyTicks);

#endif /* SRC_TIMER_H_ */

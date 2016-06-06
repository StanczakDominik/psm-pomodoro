/*
 * clock.h
 *
 *  Created on: 30-05-2016
 *      Author: psm11
 */

#ifndef CLOCK_H_
#define CLOCK_H_

#include "i2c.h"
#include "lcd.h"
#include <stdint.h>
#include <avr/io.h>
#include <stdio.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <string.h>

/* WYMAGANE POŁĄCZENIA:
 * patrz i2c.h
 */
extern volatile uint8_t time_data[7];
extern volatile uint8_t init_time_data[7];
extern char* dni_tygodnia[7];

uint8_t bcd2dec(uint8_t);
uint8_t dec2bcd(uint8_t);
void set_time(volatile uint8_t *);
void get_time(volatile uint8_t *);
void set_clock_interrupt();

#endif /* CLOCK_H_ */

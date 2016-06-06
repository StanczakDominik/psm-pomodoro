/*
 * main.c
 *
 *  Created on: 01-05-2016
 *      Author: psm11
 */

#include <stdint.h>
#include <avr/io.h>
#include <stdio.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <string.h>
#include "lcd.h"
#include "i2c.h"
#include "clock.h"
#include "pomodoro_common.h"
#include "usart.h"

/* WYMAGANE POŁĄCZENIA
 * przyciski: SW7 -> PD3 (INT1)
 * patrz pliki .h for more
 */


void set_button_interrupt()
{
	MCUCR &=~(1<<ISC11);
	MCUCR &=~(1<<ISC10);
	GICR |= (1<<INT1);
}

ISR(INT0_vect)
{
	print_time_mode();
	maybe_next_phase();
}


ISR(INT1_vect) //obsluga wcisniecia przycisku
{
	mode = (mode + 1) % 4;
	set_time(init_time_data);
	light_off();
	_delay_ms(500);
}

int main()
{
	i2c_init();
	lcd_init();
	lcd_clear();
	set_time(init_time_data);
	print_work_break_lengths();
	init_beeper();
	USART_Init(5);

	light_off();
	set_clock_interrupt();
	set_button_interrupt();
	while(1){
	}
}

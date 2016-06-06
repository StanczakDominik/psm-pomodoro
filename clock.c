/*
 * clock.c
 *
 *  Created on: 30-05-2016
 *      Author: psm11
 */

#include "clock.h"

/*
 * format: sekundy, minuty, godziny, dzień tygodnia (1: poniedziałek),
 *  dzień, miesiąc, rok
 */
volatile uint8_t time_data[7] = {0, 0, 0, 1, 31, 12, 16};
volatile uint8_t init_time_data[7] = {0, 0, 0, 1, 31, 12, 16};
char* dni_tygodnia[7] = {"Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun"};

uint8_t bcd2dec(uint8_t x)
{
	return (x >> 4) * 10 + (x & 0x0F);
}

uint8_t dec2bcd(uint8_t x)
{
	return ((x/10) << 4) | (x % 10);
}

void set_time(volatile uint8_t *time_data)
{
	i2c_start();
	i2c_write(0b11010000);
	i2c_write(0);
	for (int i = 0; i<7; i++)
	{
		i2c_write(dec2bcd(time_data[i]));
	}
	i2c_stop();
}

void get_time(volatile uint8_t *time_data)
{
	i2c_start();
	i2c_write(0b11010000); //adres slave'a + zapisujemy
	i2c_write(0); //adres w pamięci zegara
	i2c_start();
	i2c_write(0b11010001); //adres slave + odczytujemy
	for (int i = 0; i<6; i++)
	{
		time_data[i] = bcd2dec(i2c_read(1));
	}
	time_data[6] = bcd2dec(i2c_read(0));
	i2c_stop();
}


void set_clock_interrupt()
{
	sei();
	MCUCR |= (1<< ISC01);
	GICR |= (1<<INT0);

}

/*
 * lcd.h
 *
 *  Created on: 14-03-2016
 *      Author: psm11
 */

#ifndef PROJEKT_LCD_H_
#define PROJEKT_LCD_H_

#include <stdint.h>
#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>
#include <avr/pgmspace.h>

//WYMAGANE POŁĄCZENIA: RS -> PA2, E -> PA3, D4-7 -> PA4-7
#define LCD_PORT PORTA
#define LCD_RS 2
#define LCD_E 3
#define LCD_DDR DDRA

void lcd_init(void);
void lcd_write_instr(uint8_t);
void lcd_clear(void);
void lcd_write_data(uint8_t);
void lcd_set_xy(uint8_t, uint8_t);
void lcd_write_text_xy(uint8_t, uint8_t, char*);
int lcd_putc(char, FILE*);

extern FILE lcd_stream;

#endif /* PROJEKT_LCD_H_ */

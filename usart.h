/*
 * usart.h
 *
 *  Created on: 30-05-2016
 *      Author: psm11
 */

#ifndef USART_H_
#define USART_H_

#include <stdint.h>
#include <avr/io.h>
#include <stdio.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <string.h>
#include "pomodoro_common.h"

/* WYMAGANE POLACZENIA:
 * MISC RXD -> PD0 (RXD)
 * MISC TXD -> PD1 (TXD)
 */

void USART_Init( unsigned int baud ); //uruchamiac z 5
void USART_Transmit( unsigned char data );
unsigned char USART_Receive( void );

extern char bufor[20];
extern int i;

ISR(USART_RXC_vect);

#endif /* USART_H_ */

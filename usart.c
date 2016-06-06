/*
 * usart.c
 *
 *  Created on: 30-05-2016
 *      Author: psm11
 */

#include "usart.h"

void USART_Init( unsigned int baud )
{
	//PD1 na wyjscie
	DDRD |= (1<<PD1);


	/* Set baud rate */
	UBRRH = (unsigned char)(baud>>8);
	UBRRL = (unsigned char)baud;
	/* Enable receiver and transmitter */
	UCSRB = (1<<RXEN)|(1<<TXEN) | (1<<RXCIE);
	/* Set frame format: 8data, 2stop bit */
	UCSRC = (1<<URSEL)|(1<<USBS)|(3<<UCSZ0);
}
void USART_Transmit( unsigned char data )
{
	/* Wait for empty transmit buffer */
	while ( !( UCSRA & (1<<UDRE)) )
		;
	/* Put data into buffer, sends the data */
	UDR = data;
}

void USART_send_text(char* string)
{
	for (int i = 0; i<strlen(string); i++)
	{
		USART_Transmit(string[i]);
	}
}
unsigned char USART_Receive( void )
{
	/* Wait for data to be received */
	while ( !(UCSRA & (1<<RXC)) )
		;			//ale może czekać i ruski rok na tą daną, lepiej przerwaniem
	/* Get and return received data from buffer */
	return UDR;
}

char bufor[20];
int i = 0;



ISR(USART_RXC_vect)
{
	bufor[i] = UDR;
	if(bufor[i]==0x0A)
	{
		if(!strncmp((char*)bufor, "W", 1))
		{
			USART_send_text(bufor);
            int minutes = (int)(bufor[1] - '0')*10 + (int)(bufor[2] - '0');
            int seconds = (int)(bufor[3] - '0')*10 + (int)(bufor[4] - '0');
            minutes += seconds / 60;
            seconds %= 60;
            phase_minutes[0] = minutes;
            phase_seconds[0] = seconds;
            print_work_break_lengths();
		}
		else if(!strncmp((char*)bufor, "B", 1))
		{
			USART_send_text(bufor);
            int minutes = (int)(bufor[1] - '0')*10 + (int)(bufor[2] - '0');
            int seconds = (int)(bufor[3] - '0')*10 + (int)(bufor[4] - '0');
            minutes += seconds / 60;
            seconds %= 60;
            phase_minutes[1] = minutes;
            phase_seconds[1] = seconds;
            print_work_break_lengths();
            clear_time_data();
		}
		else
		{
			USART_send_text("Could not understand command. Set time for work\\break sessions via WMMSS or BMMSS, for example: W3000, then B0500.\n");
		}
		i=0;
	}
	else
	{
		i++;
	}
}

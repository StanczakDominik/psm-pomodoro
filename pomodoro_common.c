#include "pomodoro_common.h"

/*WYMAGANE POŁĄCZENIA
 *  dioda : PB0 -> LDx
 *  beeper: PB1 -> SPK (misc)
 */

volatile int mode = 0;
/* 0: work mode
 * 1: start break mode
 * 2: break mode
 * 3: cont work mode
 */

char* modes[7] = {"Work      ", "Strt brk? ", "Break     ", "Cont work?"};
volatile int phase_minutes[2] = {30, 5}; //30
volatile int phase_seconds[2] = {0, 0};
//volatile int total_phase_length[2] = {5*60+10, 1*60+5};


void clear_time_data()
{
	for (int i = 0; i<6; i++)
	{
		time_data[i] = init_time_data[i];
	}
}

void maybe_next_phase()
{
	if ((mode == 0) || (mode == 2)) //in work mode or in break mode
	{
		volatile int minutes = time_data[1];
		volatile int seconds = time_data[0];

		if (minutes*60 + seconds >= phase_minutes[mode/2]*60+phase_seconds[mode/2])
		{
			mode += 1; //goto start break mode or cont work mode
			set_time(init_time_data);
			light_on();
		}
	}
}

void print_time_mode()
{
	get_time(time_data);
	lcd_set_xy(0, 0);
	fprintf(&lcd_stream, "%02d:%02d %s", time_data[1], time_data[0], modes[mode]);
}

void print_work_break_lengths()
{
	lcd_set_xy(0, 1);
	fprintf(&lcd_stream, "W %02d:%02d B %02d:%02d ",
			phase_minutes[0], phase_seconds[0],
			phase_minutes[1], phase_seconds[1]);
}


void init_beeper()
{
	DDRB |= (1<<PB0) | (1<<PB1); //wyjscie
	PORTB |= (1<<PB1); //wyłącz brzęczyk
}

void beep()
{
	PORTB &=~ (1<<PB1); //włącz brzęczyk
	_delay_ms(50);      //poczekaj
	PORTB |= (1<<PB1);  //wyłącz brzęczyk
	_delay_ms(50);
}

void light_on()
{
	PORTB &=~ (1<<PB0);
	beep();

}
void light_off()
{
	PORTB |= (1<<PB0);
}

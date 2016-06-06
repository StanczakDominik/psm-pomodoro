#ifndef PROJEKT_POMODORO_COMMON_H_
#define PROJEKT_POMODORO_COMMON_H_

#include "lcd.h"
#include "clock.h"

extern volatile int mode;

extern char* modes[7];
extern volatile int phase_minutes[2];
extern volatile int phase_seconds[2];
extern volatile int total_phase_length[2];

void clear_time_data();
void maybe_next_phase();
void print_time_mode();
void print_work_break_lengths();

void init_beeper();
void beep();
void light_on();
void light_off();


#endif /* PROJEKT_POMODORO_COMMON_H_ */

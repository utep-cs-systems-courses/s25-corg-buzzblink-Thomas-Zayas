#ifndef buzzer_included
#define buzzer_included
#include <msp430.h>
void buzzer_init();
void buzzer_set_period(short cycles);
void buzz_update();
void update_note(int new);

extern const short notes[3];
#endif // included

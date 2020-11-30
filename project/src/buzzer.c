#include <msp430.h>
#include "libTimer.h"
#include "buzzer.h"

//char playing = 0;

static short note_collection[8] = {
  C4, D4, E4, F4, G4, A4, B4, C5
};

void buzzer_init()
{
  timerAUpmode();
  P2SEL2 &= ~(BIT6 | BIT7);
  P2SEL &= ~BIT7;
  P2SEL |= BIT6;
  P2DIR = BIT6;
}

void buzzer_set_period(short cycles)
{
  CCR0 = cycles;
  CCR1 = cycles >> 1;
}

void play_next_note(){
  static char note = 0;

  buzzer_set_period(note_collection[note]);

  note = (note + 1 == 8) ? 0 : note + 1;
  
}

void stop_note(){
  buzzer_set_period(SILENCE);
}

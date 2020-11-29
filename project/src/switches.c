#include <msp430.h>
#include "switches.h"
//#include "led.h"
//#include "buzzer.h"
//#include "song.h"

char switch_state_down, switch_state_changed;

static char switch_update_interrupt_sense()
{
  char p2val = P2IN;
  P2IES |= (p2val & SWITCHES);
  P2IES &- (p2val | ~SWITCHES);
  return p2val;
}

void switch_init()
{
  P2REN |= SWITCHES;
  P2IE |= SWITCHES;
  P2OUT |= SWITCHES;
  P2DIR &= ~SWITCHES;
  switch_update_interrupt_sense();
  //led_update();
}

void switch_interrupt_handler()
{
  char p2Val = switch_update_interrupt_sense();

  //Move Left

  if (!(p2Val & SW1)) {
 
  }

  //Move Down

  if (!(p2Val & SW2)) {

  }

  //Move Right

  if (!(p2Val & SW3)) {

  }
  
  //Move down
  if (!(p2Val & SW4)) {

  }

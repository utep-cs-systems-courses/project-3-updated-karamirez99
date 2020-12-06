#include <msp430.h>
#include "switches.h"
#include "snake.h"

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
}

void switch_interrupt_handler()
{
  char p2Val = switch_update_interrupt_sense();

  //Move Left

  if (!(p2Val & SW1)) {
    direction = 2;
  }

  //Move Down

  else if (!(p2Val & SW2)) {
    direction = 1;
  }

  //Move Up

  else if (!(p2Val & SW3)) {
    direction = 3;
  }
  
  //Move Right
  else if (!(p2Val & SW4)) {
    direction = 0;
  }
}

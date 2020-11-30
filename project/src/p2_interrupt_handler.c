#include <msp430.h>
#include "switches.h"
#include "led.h" 

/* Our switches connecting to P2 */

void __interrupt_vec(PORT2_VECTOR) Port_2(){
  green_on = 1;
  led_changed = 1;
  led_update();

  
  if (P2IFG & SWITCHES) {
    P2IFG &= ~SWITCHES;
    switch_interrupt_handler();
  }

  green_on = 0;
  led_changed = 1;
  led_update();
}

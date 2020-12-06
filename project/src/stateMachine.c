#include <msp430.h>
#include "stateMachine.h"
#include "led.h"

char on_ratio = 1;
//static char brightnessChange = 0;

/* In lightAdvance.s
char toggle_red(char value)
{
  if (on_ratio == 0) {        //on_ratio of 0 is just the led off
    red_on = 0;
    return 1;
  }

  if (value == 1) {           //the start of the led dim cycle is on
    red_on = 1;
    return 1;
  }

  if(value == on_ratio + 1){  //the end of the on_ratio cycle is an off led
    red_on = 0;
    return 1;
  }

  return 0;
}
*/

 /*
void show_redLED() {
  static char brightness_state = 0;
  char changed = 0;
  
  changed = toggle_red(brightness_state);
  // led_changed |= changed;
  show_redLED_s2(changed);
  brightness_state = (brightness_state == 4) ? 1 : brightness_state + 1;
  // led_update();
  show_redLED_s();
}
*/

/* In lightAdvance.s
void light_advance() {
  static char state = 0;

  switch(state) {
  case 0:
    state++;
    on_ratio = 1;
    break;
  case 1:
    state++;
    on_ratio = 2;
    break;
  case 2:
    state++;
    on_ratio = 3;
    break;
  case 3:
    state = 0;
    on_ratio = 4;
    break;
  }
}
*/

#include <msp430.h>
//#include "stateMachine.h"
#include "game.h"

void __interrupt_vec(WDT_VECTOR) WDT(){
  static unsigned char timeAdvance = 0;

    if (++timeAdvance == 20) {
      update_game();

    }
}

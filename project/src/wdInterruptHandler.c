#include <msp430.h>
#include "stateMachine.h"
#include "buzzer.h"

void __interrupt_vec(WDT_VECTOR) WDT(){
  static unsigned char timeAdvance = 0;

    if (++timeAdvance == 50) {
     

    }
}

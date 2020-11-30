#include <msp430.h>
#include "stateMachine.h"
#include "game.h"
#include "led.h"

//void __interrupt_vec(WDT_VECTOR) WDT(){
void wdt_c_handler(){
  static unsigned char timeAdvance = 0;
   green_on = 1;
    led_changed = 1;
    led_update();
  
  if (gameOver){
    end_game();
    green_on = 0;
    led_changed = 1;
    led_update();
    
    and_sr(~0x8);
    or_sr(0x10);
  }
  
  if (!updateGame && ++timeAdvance == 100) {
    updateGame = 1;
    timeAdvance = 0;
  }
   green_on = 0;
   led_changed = 1;
   led_update();
}

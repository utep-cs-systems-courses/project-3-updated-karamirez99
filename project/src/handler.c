#include <msp430.h>
#include "stateMachine.h"
#include "game.h"
#include "led.h"

//void __interrupt_vec(WDT_VECTOR) WDT(){
void wdt_c_handler(){
  static unsigned char timeAdvance = 0;
  static unsigned char redLEDTime = 0;
  static unsigned char led_enabled = 0;
  
  green_on = 1;
  led_changed = 1;
  led_update();
  
  if (gameOver && !led_enabled){
    end_game();
    led_enabled = 1;
  }
  
  if (!updateGame && !gameOver && ++timeAdvance == 100) {
    updateGame = 1;
    timeAdvance = 0;
  }
  
  if(led_enabled){
    show_redLED();
    if(redLEDTime++ == 250){
      light_advance();
      redLEDTime = 0;
    }
    
  }
   green_on = 0;
   led_changed = 1;
   led_update();
}

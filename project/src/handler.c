#include <msp430.h>
#include "stateMachine.h"
#include "game.h"
#include "led.h"

void wdt_c_handler(){
  static unsigned char timeAdvance = 0;
  static unsigned char led_enabled = 0;

  // CPU ON
  green_on = 1;
  led_changed = 1;
  led_update();

  //Display end screen and allow RED DIMMing
  if (gameOver && !led_enabled){
    end_game();
    led_enabled = 1;
    timeAdvance = 0;
  }

  //Move forward game time
  if (!updateGame && !gameOver && ++timeAdvance == 50) {
    updateGame = 1;
    timeAdvance = 0;
  }

  //For Led State machine at end of game
  if(led_enabled){
    show_redLED();
    if(++timeAdvance == 250){
      light_advance();
      timeAdvance = 0;
    }
    
  }

  //CPU OFF
   green_on = 0;
   led_changed = 1;
   led_update();
}

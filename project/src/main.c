#include <libTimer.h>
#include <lcdutils.h>
#include <lcddraw.h>
#include "buzzer.h"
#include "switches.h"
#include "led.h"
#include "game.h"

int main(void) {

  configureClocks();
  lcd_init();
  clearScreen(COLOR_BLACK);
  buzzer_init();

  led_init();
  switch_init();
  game_init();
  
  enableWDTInterrupts();
  or_sr(0x08);
  
  while(1){
    green_on = 0;
    led_changed = 1;
    led_update();
    or_sr(0x10);

    green_on = 1;
    led_changed = 1;
    led_update();    
    if(updateGame){
      update_game();
      updateGame = 0;
    }
  }
}

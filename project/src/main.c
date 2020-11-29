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
  //buzzer_init();

  //led_init();

  switch_init();
  game_init();
  
  enableWDTInterrupts();
  or_sr(0x18);
}

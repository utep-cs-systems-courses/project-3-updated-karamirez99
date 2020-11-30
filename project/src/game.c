#include "snake.h"
#include "game.h"
#include "buzzer.h" 
//#include "stateMachine.h"
#include <lcdutils.h>
#include <lcddraw.h>
#include <stdlib.h>
#include <msp430.h>


static u_int food[2];
char gameOver = 0;
short updateGame = 0;
void game_init()
{
  create_snake();
  draw_snake();
  u_int x = (rand() % 16) * 8 , y = (rand() % 16) * 8;
  food[0] = x;
  food[1] = y;
  draw_food();
  drawDiamond(screenWidth / 2, screenHeight / 2 + 40, 7, COLOR_YELLOW);
}

void draw_food(){
  u_int x = food[0];
  u_int y = food[1];
  fillRectangle(x, y, 8, 8, COLOR_WHITE);
}

void newFood(){
  u_int x = (rand() % 16) * 8;
  u_int y = (rand() % 16) * 8;
  food[0] = x;
  food[1] = y;
}

void update_game()
{
  stop_note();
  
  clearScreen(COLOR_BLACK);
  char impact = update_snake(food);
  if (impact == 2){
    newFood();
    // drawPixel(75, 75, COLOR_WHITE);
    // light_advance();
    play_next_note();
  }
  draw_food();
  draw_snake();

  if (impact == 1)
    gameOver = 1;
}

void end_game(){
  drawString8x12(50, 50, "RIP", COLOR_YELLOW, COLOR_BLACK);  //replace with the other font later
  drawDiamond(screenWidth / 2, screenHeight / 2 + 20, 14, COLOR_WHITE);
  drawDiamond(screenWidth / 2, screenHeight / 2 + 27, 7, COLOR_YELLOW);
  // ANd
  //And then just disable everything here lul
}

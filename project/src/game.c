#include "snake.h"
#include "game.h"
#include "buzzer.h" 
#include <lcdutils.h>
#include <lcddraw.h>

static u_int food[2];
char gameOver = 0;
short updateGame = 0;
void game_init()
{
  create_snake();
  draw_snake();
  u_int x = get_randomNum(), y = get_randomNum();
  food[0] = x;
  food[1] = y;
  draw_food();
}

void draw_food(){
  u_int x = food[0];
  u_int y = food[1];
  fillRectangle(x, y, 8, 8, COLOR_WHITE);
}

void newFood(){
  u_int x = get_randomNum();
  u_int y = get_randomNum();
  food[0] = x;
  food[1] = y;
}

void update_game()
{
  stop_note();
  
  clearScreen(COLOR_BLACK);
  char impact = update_snake(food);    //2 is food, 1 is self collision
  if (impact == 2){
    newFood();
    play_next_note();
  }
  draw_food();
  draw_snake();

  if (impact == 1)
    gameOver = 1;
}

u_int get_randomNum()
{
  static u_int pos = 0;
  u_int random;

  pos = ((pos * 5 + 3) % 17) % 16;   //16x16 board
  random = pos * 8;
  return random;
}
  

void end_game(){
  drawString8x12(50, 50, "RIP", COLOR_YELLOW, COLOR_BLACK);
  drawDiamond(screenWidth / 2, screenHeight / 2 + 20, 14, COLOR_WHITE);
  drawDiamond(screenWidth / 2, screenHeight / 2 + 27, 7, COLOR_YELLOW);
}

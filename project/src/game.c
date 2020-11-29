#include "snake.h"
#include "game.h"
#include <lcdutils.h>
#include <lcddraw.h>
#include <stdlib.h>

static u_int food[2];

void game_init()
{
  create_snake();
  draw_snake();
  u_int x = (rand() % 16) * 8 , y = (rand() % 16) * 8;
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
  u_int x = (rand() % 16) * 8;
  u_int y = (rand() % 16) * 8;
  food[0] = x;
  food[1] = y;
}

void update_game()
{
  clearScreen(COLOR_BLACK);
  char impact = update_snake(food);
  if (impact == 2)
    newFood();
  draw_food();
  draw_snake();
}

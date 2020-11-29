#include <lcdutils.h>
#include <lcddraw.h>
#include <shape.h>
#include <stdlib.h>
#include "snake.h"

static Snake *head;
u_char direction = 0;

void create_snake()
{
  head = malloc(sizeof(Snake));
  u_int x = 0, y = 0;
  u_int start = {x,y};
  head->position = &start;
  head->next = NULL;
}

void draw_snake()
{
  Snake *currNode = head;
  // drawPixel(50, 50, COLOR_WHITE);
  
  while(currNode != NULL){
    u_int x = currNode->position[0], y = currNode->position[1];
    fillRectangle(x, y, 8, 8, COLOR_BLUE);
    currNode = currNode->next;
  }
}

void update_snake(){
  u_int *position = head->position;
  
  switch (direction){
  case 0:
    position[0] += 8;
    position[0] %= screenWidth;
    break;
  case 1:
    position[1] += 8;
    break;
  case 2:
    position[0] -= 8;
    break;
  case 3:
    position[1] -= 8;
    break;
  }
}

void add_snake(){

}


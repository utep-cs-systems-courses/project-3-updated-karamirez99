#include <lcdutils.h>
#include <lcddraw.h>
#include <libTimer.h>
#include <shape.h>
#include <stdlib.h>
#include "snake.h"

static Snake *head;
u_char direction = 0;

void create_snake()
{
  head = malloc(sizeof(Snake));
  u_char x = 0, y = 0;
  head->position[0] = x;
  head->position[1] = y;
  head->next = NULL;
}

void draw_snake()
{
  Snake *currNode = head;
  
  while(currNode != NULL){
    u_char x = currNode->position[0], y = currNode->position[1];
    fillRectangle(x, y, 8, 8, COLOR_BLUE);
    currNode = currNode->next;
  }
}

char check_collision(u_int food[2]){
  u_int headx = head->position[0];
  u_int heady = head->position[1];

  Snake *current = head->next;
  while (current != NULL){  //check if head hits any location in list
    u_int currentX = current->position[0];
    u_int currentY = current->position[1];

    if(currentX == headx && currentY == heady)
      return 1;
    
    current = current->next;
  }

  //if the head position is at the food loc
  if((headx == food[0]) && (heady == food[1]))
    return 2;

  return 0;
}

char update_snake(u_int food[2]){
  u_char *position = head->position;
  u_char oldX = head->position[0];
  u_char oldY = head->position[1];

  switch (direction){  //0-right, 1-down, 2-left, 3 up
  case 0:               
    position[0] += 8;
    position[0] %= screenWidth;
    break;
  case 1:              
    position[1] += 8;
    position[1] %= screenHeight;
    break;
  case 2:
    position[0] -= 8;
    break;
  case 3:
    position[1] -= 8;
    break;
  }

  Snake *current = head->next;
  Snake *last = head;
  while(current != NULL){  //copy each position into the next node
    u_int tempX = current->position[0];
    u_int tempY = current->position[1];

    current->position[0] = oldX;
    current->position[1] = oldY;

    oldX = tempX;
    oldY = tempY;
    last = current;
    current = current->next;
  }

  char collision = check_collision(food);
  if (collision == 2)
    add_snake(oldX, oldY, last);

  return collision;
}

// add a new snake at the end of the list
void add_snake(u_int x, u_int y, Snake* last){
  Snake* newSnake = malloc(sizeof(Snake));
  newSnake->position[0] = x;
  newSnake->position[1] = y;
  newSnake->next = NULL;
  last->next = newSnake;
}


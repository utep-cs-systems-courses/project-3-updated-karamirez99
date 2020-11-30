#ifndef snake_included
#define snake_included

#include <shape.h>

typedef struct Snake_s {
  struct Snake_s *next;
  u_char position[2];
} Snake;

void create_snake();
void draw_snake();
char update_snake(u_int food[2]);
void add_snake(u_int x, u_int y, Snake* last);

extern u_char direction;
#endif

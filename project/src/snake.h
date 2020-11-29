#ifndef snake_included
#define snake_included

#include <shape.h>

typedef struct Snake_s {
  struct Snake_s *next;
  u_int *position;
} Snake;

void create_snake();
void draw_snake();
void update_snake();

extern u_char direction;
#endif

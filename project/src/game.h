#ifndef game_included
#define game_included

void game_init();
void update_game();
void draw_food();
void newFood();
void end_game();

u_int get_randomNum();

extern char gameOver;
extern short updateGame;
#endif

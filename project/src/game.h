#ifndef game_included
#define game_included

void game_init();
void update_game();
void draw_food();
void newFood();
void end_game();

extern char gameOver;
extern short updateGame;
#endif

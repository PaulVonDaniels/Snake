#ifndef SNAKE_H
#define SNAKE_H

#include "../game/game.h"

extern Segment snake[500];
extern int length;
extern int direction;

void snake_init(void);
void snake_move(int newDirection);
int snake_check_collision(int x, int y);
void snake_update_position(int x, int y);

#endif

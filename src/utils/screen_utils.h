#ifndef SCREEN_UTILS_H
#define SCREEN_UTILS_H

#include "../game/game.h"

void screen_init(void);
void screen_clear(void);
void screen_draw_border(void);
void screen_print(void);
int screen_draw(int x, int y);

#endif

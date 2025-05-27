#ifndef GAME_H
#define GAME_H

#define UP      1
#define DOWN    2
#define LEFT    3
#define RIGHT   4
#define STOP    100

#define HEIGHT  15
#define WIDTH   30
#define MAX_APPLES_ON_TREE 5

extern int picture[HEIGHT][WIDTH];

typedef struct {
    int x;
    int y;
} Segment;

typedef struct {
    int x;
    int y;
    int apples_left;
} AppleTree;

void game_init(void);
int game_loop(void);
void game_cleanup(void);

#endif

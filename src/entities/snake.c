#include "snake.h"
#include "../game/game.h"

Segment snake[500];
int length = 1;
int direction = RIGHT;

void snake_init(void) {
    snake[0].x = HEIGHT / 2;
    snake[0].y = WIDTH / 2;
    length = 1;
    direction = RIGHT;
}

void snake_move(int newDirection) {
    int prevX = snake[0].x;
    int prevY = snake[0].y;
    int tempX, tempY;
    
    switch(newDirection) {
        case UP:    snake[0].x--; break;
        case DOWN:  snake[0].x++; break;
        case LEFT:  snake[0].y--; break;
        case RIGHT: snake[0].y++; break;
    }
    
    for(int i = 1; i < length; i++) {
        tempX = snake[i].x;
        tempY = snake[i].y;
        snake[i].x = prevX;
        snake[i].y = prevY;
        prevX = tempX;
        prevY = tempY;
    }
}

int snake_check_collision(int x, int y) {
    if(x <= 0 || x >= HEIGHT-1 || y <= 0 || y >= WIDTH-1) {
        return 1;
    }
    
    for(int i = 1; i < length; i++) {
        if(snake[i].x == x && snake[i].y == y) {
            return 1;
        }
    }
    
    return 0;
}

void snake_update_position(int x, int y) {
    snake[0].x = x;
    snake[0].y = y;
}

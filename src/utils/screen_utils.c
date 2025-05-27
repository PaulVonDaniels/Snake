#include "screen_utils.h"
#include "../game/game.h"
#include "../entities/snake.h"
#include "../entities/apple_tree.h"
#include <stdio.h>
#include <stdlib.h>

void screen_init(void) {
    // Инициализация не требуется в текущей реализации
}

void screen_clear(void) {
    system("cls");
}

void screen_draw_border(void) {
    for(int j = 0; j < WIDTH; j++) {
        picture[0][j] = '#';
        picture[HEIGHT-1][j] = '#';
    }
    for(int i = 0; i < HEIGHT; i++) {
        picture[i][0] = '|';
        picture[i][WIDTH-1] = '|';
    }
}

int screen_draw(int x, int y) {
    for(int i = 0; i < HEIGHT; i++) {
        for(int j = 0; j < WIDTH; j++) {
            if(picture[i][j] == '.') {
                // Яблоки уже нарисованы
            }
        }
    }
    
    for (int t = 0; t < num_trees; t++) {
        picture[trees[t].x][trees[t].y] = 'T';
    }
    
    for(int i = 0; i < length; i++) {
        if(snake[i].x >= 0 && snake[i].x < HEIGHT && snake[i].y >= 0 && snake[i].y < WIDTH) {
            picture[snake[i].x][snake[i].y] = (i == 0) ? 'O' : 'o';
        }
    }
    
    if(x <= 0 || x >= HEIGHT-1 || y <= 0 || y >= WIDTH-1) {
        return 0;
    }
    return 1;
}

void screen_print(void) {
    for(int i = 0; i < HEIGHT; i++) {
        for(int j = 0; j < WIDTH; j++) {
            printf("%c", picture[i][j]);
        }
        printf("\n");
    }
}

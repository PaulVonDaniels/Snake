#include "../game/game.h"
#include "../entities/snake.h"
#include "../entities/apple_tree.h"
#include "../utils/screen_utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int picture[HEIGHT][WIDTH];

void game_init(void) {
    srand(time(NULL));
    snake_init();
    apple_trees_init();
    screen_init();
}

int game_loop(void) {
    // Основная игровая логика в main()
}

void game_cleanup(void) {
    // Очистка ресурсов
}

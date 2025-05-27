#include "../game/game.h"
#include "../entities/snake.h"
#include "../entities/apple_tree.h"
#include "../utils/screen_utils.h"
#include <conio.h>
#include <windows.h>

int picture[HEIGHT][WIDTH];

void game_init(void) {
    for(int i = 0; i < HEIGHT; i++) {
        for(int j = 0; j < WIDTH; j++) {
            picture[i][j] = ' ';
        }
    }
    
    srand(time(NULL));
    snake_init();
    apple_trees_init();
    screen_draw_border();
}

int game_loop(void) {
    int count_all_apples = 0;
    int conflict = 0;
    int is_all_apple = 0;
    
    apple_tree_generate();
    
    while(1) {
        screen_clear();
        printf("\nx: %i y: %i\n", snake[0].x, snake[0].y);
        
        if(!screen_draw(snake[0].x, snake[0].y)) {
            conflict = 1;
            break;
        }
        
        printf("\nApples collected: %i\n", count_all_apples);
        printf("Trees on field: %i\n", num_trees);
        
        if (_kbhit()) {
            char key = _getch();
            switch (key) {
                case 'w': if (direction != DOWN) direction = UP; break;
                case 's': if (direction != UP) direction = DOWN; break;
                case 'a': if (direction != RIGHT) direction = LEFT; break;
                case 'd': if (direction != LEFT) direction = RIGHT; break;
                case 'f': return 0;
            }
        }
        
        snake_move(direction);
        
        if (picture[snake[0].x][snake[0].y] == '.') {
            count_all_apples++;
            length++;
            apple_generate();
        }
        
        int tree_index = apple_tree_check(snake[0].x, snake[0].y);
        if (tree_index != -1) {
            int apples_eaten = trees[tree_index].apples_left;
            count_all_apples += apples_eaten;
            length += apples_eaten;
            
            for (int i = tree_index; i < num_trees - 1; i++) {
                trees[i] = trees[i + 1];
            }
            num_trees--;
            
            if (rand() % 2 == 0 && num_trees < 5) {
                apple_tree_generate();
            }
        }
        
        if (rand() % 100 == 0 && num_trees < 5) {
            apple_tree_generate();
        }
        
        if (snake_check_collision(snake[0].x, snake[0].y)) {
            conflict = 1;
            break;
        }
        
        screen_print();
        Sleep(200);
        
        if(count_all_apples >= 30) {
            is_all_apple = 1;
            break;
        }
    }
    
    screen_clear();
    printf("%s\n","-------------------------------------------------------");
    if(is_all_apple) {
        printf("%s\n","Congratulations! You have collected enough apples!");
    }
    else if(conflict == 1) {
        printf("%s\n", "Game Over: The snake collided with the wall or itself.");
    }
    printf("\nTotal apples collected: %d", count_all_apples);
    printf("\n%s","Game Over.");
    printf("\n%s\n","-------------------------------------------------------");
    
    return 0;
}

void game_cleanup(void) {
    // В текущей реализации не требуется очистка ресурсов
}

#include "apple_tree.h"
#include "../game/game.h"

AppleTree trees[5];
int num_trees = 0;

void apple_trees_init(void) {
    num_trees = 0;
}

void apple_tree_generate(void) {
    if (num_trees >= 5) return;
    
    int x, y;
    int attempts = 0;
    const int max_attempts = 50;
    
    do {
        x = 2 + rand() % (HEIGHT - 4);
        y = 2 + rand() % (WIDTH - 4);
        attempts++;
        
        if (attempts >= max_attempts) return;
    } while(picture[x][y] != ' ');
    
    trees[num_trees].x = x;
    trees[num_trees].y = y;
    trees[num_trees].apples_left = 1 + rand() % MAX_APPLES_ON_TREE;
    num_trees++;
}

int apple_tree_check(int x, int y) {
    for (int i = 0; i < num_trees; i++) {
        if (trees[i].x == x && trees[i].y == y) {
            return i;
        }
    }
    return -1;
}

void apple_generate(void) {
    int x, y;
    do {
        x = 1 + rand() % (HEIGHT - 2);
        y = 1 + rand() % (WIDTH - 2);
    } while(picture[x][y] != ' ');
    
    picture[x][y] = '.';
}

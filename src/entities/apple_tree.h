#ifndef APPLE_TREE_H
#define APPLE_TREE_H

#include "../game/game.h"

extern AppleTree trees[5];
extern int num_trees;

void apple_trees_init(void);
void apple_tree_generate(void);
int apple_tree_check(int x, int y);

#endif

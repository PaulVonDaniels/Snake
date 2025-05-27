#include "game/game.h"

int main(void) {
    game_init();
    int result = game_loop();
    game_cleanup();
    return result;
}

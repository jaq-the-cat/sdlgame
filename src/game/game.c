#include "../game.h"

#include <SDL2/SDL_image.h>

extern SDL_Renderer rend;

void start(entities *es) {
    eadd((entity) {
        .type = PLAYER,
        .origin = {10, 10},
        .velocity = {0, 0},
        .size = {64, 64},
        .gravity = 1,
        .texture = IMG_LoadTexture(&rend, "sprites/player.png"),
    }); // player
}

bool update(entities *es, SDL_Event *event) {
    switch (event->key.keysym.scancode) {
    case SDL_SCANCODE_ESCAPE:
        return true;
    default:
        break;
    }
    return false;
}

void end() {
}

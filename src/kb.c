#include "kb.h"
#include <SDL2/SDL_scancode.h>

extern bool close;
extern buttons keys;

void handleKey(SDL_Scancode scancode, int down) {
    switch (scancode) {
        case SDL_SCANCODE_Q:
        case SDL_SCANCODE_ESCAPE:
            close = true;
            break;
        case SDL_SCANCODE_W:
        case SDL_SCANCODE_UP:
            keys.w = down;
            break;
        case SDL_SCANCODE_A:
        case SDL_SCANCODE_LEFT:
            keys.a = down;
            break;
        case SDL_SCANCODE_S:
        case SDL_SCANCODE_DOWN:
            keys.s = down;
            break;
        case SDL_SCANCODE_D:
        case SDL_SCANCODE_RIGHT:
            keys.d = down;
            break;
        default:
            break;
    }
}

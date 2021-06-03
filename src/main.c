#include <SDL2/SDL.h>
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_timer.h>

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "conf.h"
#include "entity.h"
#include "kb.h"

// globals
extern bool close;
extern buttons keys;

SDL_Window *win;
SDL_Renderer *rend;

void init() {
    // window
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
        printf("Error initializing SDL: %s\n", SDL_GetError());
    win = SDL_CreateWindow(
        "SDL Game",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        WIDTH, HEIGHT,
        0);
    rend = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);
    IMG_Init(IMG_INIT_PNG);
}

int main() {
    init();

    int starting_tick = SDL_GetTicks();
    float new_time, delta;
    while (!close) {
        // Get FPS
        if ((1000 / MAXFPS) > SDL_GetTicks() - starting_tick)
            SDL_Delay(1000 / MAXFPS - (SDL_GetTicks() - starting_tick));

        SDL_Event event;

        // Clear screen
        SDL_SetRenderDrawColor(rend, BACKGROUND, 255);
        SDL_RenderClear(rend);
        // Render stuff

        // Draw to screen
        SDL_RenderPresent(rend);

        // Events mangement
        SDL_PollEvent(&event);
        switch (event.type) {
        case SDL_QUIT:
            close = true;
            break;
        case SDL_KEYDOWN:
            handleKey(event.key.keysym.scancode, true);
            break;
        case SDL_KEYUP:
            handleKey(event.key.keysym.scancode, false);
            break;
        }
    }

    /*SDL_DestroyTexture();*/
    IMG_Quit();
    SDL_DestroyRenderer(rend);
    SDL_DestroyWindow(win);
    SDL_Quit();

    return EXIT_SUCCESS;
}

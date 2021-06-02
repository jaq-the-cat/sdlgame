#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>
#include <stdbool.h>
#include "gjk.h"

#define WIDTH 1920/(1.2)
#define HEIGHT 1080/(1.2)

#define COLOR int r, int g, int b

enum ETYPE {
    PLAYER,
    GROUND,
};

typedef struct {
    enum ETYPE type;
    float x, y;
    float vx, vy;
    int w, h;
    bool grounded;
    SDL_Texture *sprite;
    int vertexcount;
    vec2 hitbox[4];
} Entity;

void clearScreen(COLOR);
void drawEntity(Entity *entity);
bool collide(Entity *a, Entity *b);

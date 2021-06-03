#pragma once

#include <SDL2/SDL_render.h>
#include <stdio.h>
#include "gjk.h"

typedef enum ENTITY_TYPE {
    ENEMY,
    OBJECT,
    OBJECT_DMG,
    OBJECT_MOV,
    OBJECT_MOV_DMG,
} ENTITY_TYPE;

typedef struct entity {
    ENTITY_TYPE type;
    vec2 origin;
    vec2 velocity;
    vec2 size;
    float gravity;
    SDL_Texture *texture;
} entity;

void tick(entity *e);

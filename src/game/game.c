#include "../game.h"

#include <SDL2/SDL_image.h>

extern SDL_Renderer *rend;

typedef enum ENTITY_TYPE {
    PLAYER,
    DMG,
    OBJECT,
} ENTITY_TYPE;

typedef struct entity {
    ENTITY_TYPE type;
    vec2 origin;
    vec2 velocity;
    vec2 size;
    float gravity;
    SDL_Texture *texture;
} entity;

void start(entities *es) {
    eadd(&(entity) {
        .type = PLAYER,
        .origin = {0, 0},
        .velocity = {0, 0},
        .size = {64, 64},
        .gravity = 1,
        .texture = IMG_LoadTexture(rend, "sprites/player.png"),
    }); // player

    eadd(&(entity) {
        .type = PLAYER,
        .origin = {65, 0},
        .velocity = {0, 0},
        .size = {64, 64},
        .gravity = 1,
        .texture = IMG_LoadTexture(rend, "sprites/player.png"),
    }); // player

    for (int i=0; i<20; i++) {
        eadd(&(entity) {
            .type = OBJECT,
            .origin = {i*64, 64*2},
            .velocity = {0, 0},
            .size = {64, 64},
            .gravity = 0,
            .texture = IMG_LoadTexture(rend, "sprites/ground.png"),
        }); // player
    }

    for (int i=0; i<20; i++) {
        eadd(&(entity) {
            .type = OBJECT,
            .origin = {i*64, 64*6},
            .velocity = {0, 0},
            .size = {64, 64},
            .gravity = 0,
            .texture = IMG_LoadTexture(rend, "sprites/ground.png"),
        }); // player
    }
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

void render(void *e) {
    entity *en = (entity*) e;
    printf("(%f, %f) (%f, %f)\n", en->origin.x, en->origin.y, en->size.x, en->size.y);
    SDL_Rect dst = {
        en->origin.x,
        en->origin.y,
        en->size.x,
        en->size.y,
    };
    /*SDL_RenderCopy(rend, en->texture, NULL, &dst);*/
}

void destroy(void *e) {
    SDL_DestroyTexture(((entity*) e)->texture);
}

void end() {
}

int main() {
    return run();
}

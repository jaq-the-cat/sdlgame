#include "util.h"
#include <stdio.h>
#include <SDL2/SDL_image.h>

extern SDL_Window *win;
extern SDL_Renderer *rend;

void clearScreen(COLOR) {
    SDL_SetRenderDrawColor(rend, r, g, b, 255);
    SDL_RenderClear(rend);
}

void drawEntity(Entity *entity) {
    SDL_Rect destination = {entity->x, entity->y, entity->w, entity->h};
    SDL_SetRenderTarget(rend, entity->sprite);
    SDL_RenderCopy(rend, entity->sprite, NULL, &destination);
    SDL_SetRenderTarget(rend, NULL);
}

void getMovedVertices(vec2 moved[], Entity *entity) {
    for (int i=0; i<entity->vertexcount; i++) {
        moved[i].x = entity->hitbox[i].x + entity->x;
        moved[i].y = entity->hitbox[i].y + entity->y;
    }
}

bool collide(Entity *a, Entity *b) {
    vec2 hitboxA[a->vertexcount];
    vec2 hitboxB[a->vertexcount];
    getMovedVertices(hitboxA, a);
    getMovedVertices(hitboxB, b);

    return gjk(
        hitboxA, a->vertexcount,
        hitboxB, b->vertexcount
    );
}

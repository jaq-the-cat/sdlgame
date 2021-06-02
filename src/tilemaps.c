#include "util.h"
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_render.h>

extern SDL_Renderer *rend;

void appendToTexture(SDL_Texture *origin, SDL_Texture *other, SDL_Rect transform) {
    SDL_SetRenderTarget(rend, origin);
    SDL_RenderCopy(rend, other, NULL, &transform);
    SDL_SetRenderTarget(rend, NULL);
}

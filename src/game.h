#pragma once
#include "entity.h"
#include <SDL2/SDL_events.h>
#include <stdbool.h>

void start();
bool update(SDL_Event *event, entities *es);
void end();

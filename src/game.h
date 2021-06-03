#pragma once
#include "entity.h"
#include <SDL2/SDL_events.h>
#include <stdbool.h>

int run();
void start(entities *es);
bool update(entities *es, SDL_Event *event);
void end();

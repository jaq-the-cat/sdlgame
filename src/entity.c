#include "entity.h"

void tick(entity *e) {
    e->origin.x += e->velocity.x;
    e->origin.y += e->velocity.y;

    e->velocity.y -= e->gravity;
}

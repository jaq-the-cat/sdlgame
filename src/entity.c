#include "entity.h"

void tick(entity *e) {
    e->origin.x += e->velocity.x;
    e->origin.y += e->velocity.y;

    e->velocity.y -= e->gravity;
}

void eadd(entities *es, entity e) {
    // create new node
    es->previous = malloc(sizeof(entities));
    // populate new node
    es->previous->previous = NULL;
    es->previous->e = e;
    es->previous->next = es;
    // set head to new node
    *es = *es->previous;
}

void eremove(entities *es, entity *e) {
    entities *node = es;
    // scroll through until node is e
    for (entities *node = es; node != NULL && &node->e != e; node = node->next);
    node->previous->next = node->next;
    free(node);
}

void efree(entities *es) {
    entities *node = es;
    while (node != NULL) {
        es = es->next;
        free(node);
        node = es;
    }
}

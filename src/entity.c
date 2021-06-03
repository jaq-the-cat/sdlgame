#include "entity.h"

extern entities *es;

void tick(entity *e) {
    e->origin.x += e->velocity.x;
    e->origin.y += e->velocity.y;

    e->velocity.y -= e->gravity;
}

void makenode(entities *node, entity e, entities *next) {
    node = malloc(sizeof(entities));
    node->previous = NULL;
    node->e = e;
    node->next = next;
}

void eadd(entity e) {
    // special case: first entity
    if (es == NULL) {
        makenode(es, e, NULL);
        return;
    }

    // create new node
    makenode(es->previous, e, es);

    // set head to new node
    es = es->previous;
}

void eremove(entity *e) {
    entities *node = es;
    // scroll through until node is e
    for (entities *node = es; node != NULL && &node->e != e; node = node->next);
    node->previous->next = node->next;
    free(node);
}

void efree() {
    entities *node = es;
    while (node != NULL) {
        es = es->next;
        free(node);
        node = es;
    }
}

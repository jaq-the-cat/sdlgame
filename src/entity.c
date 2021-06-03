#include "entity.h"

extern SDL_Renderer *rend;
extern entities *es;

void erender() {
    for (entities *node = es; node != NULL; node = node->next) {
        printf("rendering entity\n");
        // render node
        SDL_Rect dst = {
            node->e.origin.x,
            node->e.origin.y,
            node->e.size.x,
            node->e.size.y,
        };
        SDL_RenderCopy(rend, node->e.texture, NULL, &dst);
    }
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

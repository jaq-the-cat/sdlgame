#include <SDL2/SDL_render.h>
#include <stdlib.h>
#include "entity.h"

extern SDL_Renderer *rend;
extern entities es;

void erender() {
    int i=0;
    for (enode *node = es.head; node != NULL; node = node->next) {
        // render node
        SDL_Rect dst = {
            node->e.origin.x,
            node->e.origin.y,
            node->e.size.x,
            node->e.size.y,
        };
        SDL_RenderCopy(rend, node->e.texture, NULL, &dst);
        i++;
    }
}

enode* makenode(entity e, enode *next) {
    enode *node = malloc(sizeof(enode));
    node->previous = NULL;
    node->e = e;
    node->next = next;
    return node;
}

void eadd(entity e) {
    // special case: first entity
    if (es.length == 0) {
        es.head = makenode(e, NULL);
        es.length++;
        return;
    }

    printf("others\n");
    // create new node
    es.head->previous = makenode(e, es.head);
    es.head = es.head->previous;
    es.length++;
}

void eremove(entity *e) {
    enode *node = es.head;
    // special case: first item
    if (&node->e == e) {
        es.head = node->next;
        free(node);
        es.length--;
        return;
    }
    // scroll through until node is e
    for (; node != NULL && &node->e != e; node = node->next);
    node->previous->next = node->next;
    free(node);
    es.length--;
}

void efree() {
    enode *tofree = es.head;
    enode *node;
    while (tofree != NULL) {
        node = tofree->next;
        SDL_DestroyTexture(tofree->e.texture);
        free(tofree);
        tofree = node;
    }
    es.length = 0;
}

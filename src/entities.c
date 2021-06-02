#include "util.h"

Entity entities[] = {
    { // Player
        .type = PLAYER,
        .x = 0, .y = 0,
        .vx = 0, .vy = 0,
        .w = 64, .h = 64,
        .grounded = false,
        .sprite = NULL,
        .vertexcount = 4,
        .hitbox = {
            {0,  0}, // top left
            {64, 0}, // top right
            {64, 64}, // bottom right
            {0,  64}, // bottom left
        }
    },
    { // Ground
        .type = GROUND,
        .x = 0, .y = 0,
        .vx = 0, .vy = 0,
        .w = 64, .h = 64,
        .grounded = false,
        .sprite = NULL,
        .vertexcount = 4,
        .hitbox = {
            {0,  0}, // top left
            {64, 0}, // top right
            {64, 64}, // bottom right
            {0,  64}, // bottom left
        }
    },
    { // Other
        .type = GROUND,
        .x = 0, .y = 0,
        .vx = 0, .vy = 0,
        .w = 64, .h = 64,
        .grounded = false,
        .sprite = NULL,
        .vertexcount = 4,
        .hitbox = {
            {0,  0}, // top left
            {64, 0}, // top right
            {64, 64}, // bottom right
            {0,  64}, // bottom left
        }
    },
};

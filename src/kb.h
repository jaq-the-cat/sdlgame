#pragma once
#include <stdbool.h>

typedef struct {
    bool w, a, s, d,
        space;
} buttons;

void handleKey();

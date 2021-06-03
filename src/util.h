#include <math.h>
#include <stdio.h>

#define PI 3.141592653589
#define POLYGON(sides) {8, (point[sides]) {}};

typedef struct point {
    int x, y;
} point;

typedef struct polygon {
    int sides;
    point* points;
} polygon;

void polygen(polygon *dest, int xc, int yc, int x, int y, int n) {
    int lastx, lasty;
    double r = sqrt((x - xc) * (x - xc) + (y - yc) * (y - yc));
    double a = atan2(y - yc, x - xc);

    for (int i = 0; i < n; i++) {
        lastx = x; lasty = y;
        a = a + PI * 2 / n;
        x = round((double) xc + (double) r * cos(a));
        y = round((double) yc + (double) r * sin(a));
        dest->points[i] = (point) {x, y};
        printf("POINT: %d %d\n", x, y);
    }
}

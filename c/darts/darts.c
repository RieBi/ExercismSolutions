#include "darts.h"
#include <math.h>

uint8_t score(coordinate_t coordinate)
{
    float distance = sqrtf(coordinate.x * coordinate.x + coordinate.y * coordinate.y);

    if (distance <= 1) {
        return 10;
    } else if (distance <= 5) {
        return 5;
    } else if (distance <= 10) {
        return 1;
    } else {
        return 0;
    }
}

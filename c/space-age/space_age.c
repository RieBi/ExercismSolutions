#include "space_age.h"

#define YEAR_SECONDS 31557600

static float relative_periods[] = {
    0.2408467,
    0.61519726,
    1.0,
    1.8808158,
    11.862615,
    29.447498,
    84.016846,
    164.79132
};

float age(planet_t planet, int64_t seconds)
{
    if (planet < 0 || planet >= 8) {
        return -1;
    }

    return seconds / YEAR_SECONDS / relative_periods[planet];
}

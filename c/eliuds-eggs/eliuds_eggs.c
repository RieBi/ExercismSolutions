#include "eliuds_eggs.h"

unsigned int egg_count(int display)
{
    int result = 0;

    while (display) {
        if (display & 1) {
            result++;
        }

        display >>= 1;
    }

    return result;
}

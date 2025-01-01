#include "resistor_color_trio.h"

#include <math.h>
#include <stdio.h>

resistor_value_t color_code(resistor_band_t *bands)
{
    uint64_t value = *bands++;
    value *= 10;
    value += *bands++;
    value *= pow(10, *bands);

    int grade = 0;
    if (value) {
        while (value % 1000 == 0) {
            value /= 1000;
            grade++;
        }
    }

    resistor_value_t result;
    result.value = (uint16_t)value;
    result.unit = grade;

    return result;
}

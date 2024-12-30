#include "resistor_color.h"
#include "stdbool.h"

static resistor_band_t band_colors[10] = {
    RESISTOR_COLOR_MACRO
};


resistor_band_t *colors()
{
    return band_colors;
}

int color_code(resistor_band_t band)
{
    return (int)band;
}

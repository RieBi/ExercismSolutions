#include "resistor_color.h"
#include "stdbool.h"

static resistor_band_t band_colors[10];
static bool colors_initialized = false;

resistor_band_t *colors()
{
    if (!colors_initialized) {
        resistor_band_t *pointer = band_colors;
        int max = sizeof(band_colors) / sizeof(resistor_band_t);

        for (int i = 0; i < max; i++)
        {
            *pointer = i;
            pointer++;
        }

        colors_initialized = true;
    }

    return band_colors;
}

int color_code(resistor_band_t band)
{
    return (int)band;
}

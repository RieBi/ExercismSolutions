#include "resistor_color_duo.h"

#define single_color(band) (uint8_t)band

uint16_t color_code(resistor_band_t *bands)
{
    uint16_t code = single_color(*bands);
    code *= 10;

    return code + *(++bands);
}

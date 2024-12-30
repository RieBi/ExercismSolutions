#ifndef RESISTOR_COLOR_H
#define RESISTOR_COLOR_H

#define RESISTOR_COLOR_MACRO \
    BLACK, \
    BROWN, \
    RED, \
    ORANGE, \
    YELLOW, \
    GREEN, \
    BLUE, \
    VIOLET, \
    GREY, \
    WHITE

typedef enum {
    RESISTOR_COLOR_MACRO
} resistor_band_t;

resistor_band_t* colors();

int color_code(resistor_band_t band);

#endif

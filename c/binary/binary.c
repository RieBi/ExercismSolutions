#include "binary.h"

static int leftmost_bit = 1 << 30;

int convert(const char *input)
{
    int result = 0;

    while (*input) {
        if (*input & leftmost_bit) {
            return INVALID;
        }

        result <<= 1;
        if (*input == '1') {
            result |= 1;
        } else if (*input != '0') {
            return INVALID;
        }

        input++;
    }

    return result;
}

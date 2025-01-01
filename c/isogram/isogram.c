#include "isogram.h"
#include <stdint.h>
#include <ctype.h>

bool is_isogram(const char phrase[])
{
    if (!phrase) {
        return false;
    }

    int32_t map = 0;

    while (*phrase != '\0') {
        char ch = *phrase;

        if (isalpha(ch)) {
            int chmap = 1 << (tolower(ch) - 'a');
            if (map & chmap) {
                return false;
            } else {
                map |= chmap;
            }
        }

        phrase++;
    }

    return true;
}

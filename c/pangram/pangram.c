#include "pangram.h"

static const int32_t pangram_mask = (1 << 26) - 1;

bool is_pangram(const char *sentence)
{
    if (sentence == NULL) {
        return 0;
    }

    int32_t mask = 0;

    while (*sentence != '\0')
    {
        char cur = *sentence;

        if (cur >= 'a' && cur <= 'z')
        {
            mask |= 1 << (cur - 'a');
        }
        else if (cur >= 'A' && cur <= 'Z')
        {
            mask |= 1 << (cur - 'A');
        }

        sentence++;
    }

    return mask == pangram_mask;
}

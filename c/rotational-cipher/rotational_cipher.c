#include "rotational_cipher.h"
#include <string.h>
#include <stdlib.h>

char *rotate(const char *text, int shift_key)
{
    if (text == NULL) {
        return NULL;
    }

    shift_key %= 26;

    if (shift_key < 0) {
        shift_key = 26 - shift_key;
    }

    char *result = malloc(strlen(text) + 1);

    char *cur = result;

    char c;

    do {
        c = *text++;

        if (c >= 'a' && c <= 'z') {
            c += shift_key;
            if (c > 'z') {
                c -= 26;
            }
        }
        else if (c >= 'A' && c <= 'Z') {
            c += shift_key;
            if (c > 'Z') {
                c -= 26;
            }
        }

        *cur = c;
        cur++;

    } while (c);

    return result;
}

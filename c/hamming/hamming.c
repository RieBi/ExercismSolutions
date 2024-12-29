#include "hamming.h"

#define NIL '\0'

int compute(const char *lhs, const char *rhs)
{
    int distance = 0;

    while (*lhs != NIL && *rhs != NIL) {
        if (*lhs != *rhs) {
            distance++;
        }

        lhs++;
        rhs++;
    }

    if ((*lhs == NIL) ^ (*rhs == NIL)) {
        return -1;
    }

    return distance;
}

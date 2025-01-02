#include "luhn.h"
#include <stdlib.h>

bool luhn(const char *num)
{
    if (num == NULL) {
        return false;
    }

    const char *pointer = num;
    while (*pointer != '\0') {
        if ((*pointer < '0' || *pointer > '9') && *pointer != ' ') {
            return false;
        }

        pointer++;
    }

    int count = 1;
    int sum = 0;
    pointer--;
    while (pointer >= num)
    {
        if (*pointer != ' ') {
            count++;
            int digit = (*pointer - '0');

            if (count & 1) {
                digit <<= 1;
                if (digit >= 10) {
                    digit -= 9;
                }
            }

            sum += digit;
        }

        pointer--;
    }

    if (count <= 2) {
        return false;
    }

    return sum % 10 == 0;
}

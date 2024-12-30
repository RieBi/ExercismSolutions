#include "raindrops.h"
#include <stdio.h>

void convert(char result[], int drops)
{
    int length = sprintf(result, "%s%s%s", drops % 3 ? "\0" : "Pling", drops % 5 ? "\0" : "Plang", drops % 7 ? "\0" : "Plong");

    if (!length) {
        sprintf(result, "%d", drops);
    }
}

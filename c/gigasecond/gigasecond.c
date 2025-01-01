#include "gigasecond.h"
#include <time.h>
#include <stdio.h>

void gigasecond(time_t input, char *output, size_t size)
{
    input += 1000000000;
    struct tm *time = gmtime(&input);

    strftime(output, size, "%Y-%m-%d %H:%M:%S", time);
}

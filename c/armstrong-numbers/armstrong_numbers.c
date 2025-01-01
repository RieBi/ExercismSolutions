#include "armstrong_numbers.h"
#include <math.h>

bool is_armstrong_number(int candidate)
{
    int digits_count = 0;
    int num = candidate;
    while (num > 0) {
        num /= 10;
        digits_count++;
    }

    int sum = 0;
    num = candidate;
    while (num > 0)
    {
        int digit = num % 10;
        num /= 10;

        sum += pow(digit, digits_count);
    }

    return sum == candidate;
}

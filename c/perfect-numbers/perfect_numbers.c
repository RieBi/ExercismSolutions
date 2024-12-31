#include "perfect_numbers.h"

kind classify_number(int number)
{
    if (number == 1) {
        return DEFICIENT_NUMBER;
    } else if (number < 1) {
        return -1;
    }

    int result = 1;

    int num = 2;
    for (; num * num < number; num++) {
        if (!(number % num)) {
            result += num;
            result += number / num;
        }
    }

    if (num * num == number) {
        result += num;
    }

    if (result == number) {
        return PERFECT_NUMBER;
    } else if (result > number) {
        return ABUNDANT_NUMBER;
    } else {
        return DEFICIENT_NUMBER;
    }
}

#include "binary_search.h"

const int *binary_search(int value, const int *arr, size_t length)
{
    int left = 0;
    int right = length - 1;

    while (left <= right) {
        int middle = (left + right) / 2;
        int elem = arr[middle];

        if (elem == value) {
            return arr + middle;
        } else if (elem < value) {
            left = middle + 1;
        } else {
            right = middle - 1;
        }
    }

    return NULL;
}

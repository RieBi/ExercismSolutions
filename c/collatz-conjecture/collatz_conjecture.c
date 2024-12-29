#include "collatz_conjecture.h"

int steps(int start)
{
    if (start < 1) {
        return ERROR_VALUE;
    } else {
        int steps = 0;
        
        while (start > 1) {
            steps++;

            if (start & 1) {
                start = start * 3 + 1;
            } else {
                start >>= 1;
            }
        }

        return steps;
    }
}

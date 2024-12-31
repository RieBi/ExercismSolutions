#include "high_scores.h"

static int32_t max(const int32_t *array, size_t array_len)
{
    const int32_t *end = array + array_len;
    int32_t cur = *array;

    array++;

    while (array < end)
    {
        if (cur < *array)
        {
            cur = *array;
        }

        array++;
    }

    return cur;
}

/// Return the latest score.
int32_t latest(const int32_t *scores, size_t scores_len)
{
    return scores[scores_len - 1];
}

/// Return the highest score.
int32_t personal_best(const int32_t *scores, size_t scores_len)
{
    return max(scores, scores_len);
}

/// Write the highest scores to `output` (in non-ascending order).
/// Return the number of scores written.
size_t personal_top_three(const int32_t *scores, size_t scores_len,
                          int32_t *output)
{
    int init_count = scores_len > 3 ? 3 : scores_len;
    int32_t *init_output = output;
    const int32_t *scores_end = scores + scores_len;

    for (int i = 0; i < init_count; i++) {
        *output = *scores;

        scores++;
        output++;
    }

    output--;
    for (int32_t *i = output; i > init_output; i--)
    {
        for (int32_t *j = i; j > init_output; j--) {
            if (*j > *(j - 1)) {
                *(j - 1) += *j;
                *j = *(j - 1) - *j;
                *(j - 1) -= *j;
            }
        }
    }

    while (scores < scores_end) {
        if (*scores > *output) {
            *output = *scores;

            if (*output > *(output - 1)) {
                *(output - 1) += *output;
                *output = *(output - 1) - *output;
                *(output - 1) -= *output;

                if (*(output - 1) > *(output - 2)) {
                    *(output - 2) += *(output - 1);
                    *(output - 1) = *(output - 2) - *(output - 1);
                    *(output - 2) -= *(output - 1);
                }
            }
        }

        scores++;
    }

    return init_count;
}

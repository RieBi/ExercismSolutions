#include "allergies.h"

bool is_allergic_to(allergen_t allergen, int test_score)
{
    return test_score & (1 << allergen);
}

allergen_list_t get_allergens(int test_score)
{
    test_score %= 1 << ALLERGEN_COUNT;

    allergen_list_t list;
    int count = 0;

    bool *allergens = list.allergens;
    bool *end = allergens + 7;
    int mask = 1 << (ALLERGEN_COUNT - 1);

    while (end >= allergens) {
        *end = test_score & mask;
        if (test_score & mask) {
            count++;
        }

        mask >>= 1;
        end--;
    }

    list.count = count;
    return list;
}

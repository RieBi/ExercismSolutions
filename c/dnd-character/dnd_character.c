#include "dnd_character.h"
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <limits.h>

static int get_random_number()
{
    static int init = true;
    if (init) {
        srand(time(NULL) % INT_MAX);
        init = false;
    }

    return rand() % 6;
}

int ability(void)
{
    int min = INT_MAX;
    int sum = 0;

    for (int i = 0; i < 4; i++) {
        int roll = get_random_number();
        sum += roll;

        if (roll < min) {
            min = roll;
        }
    }

    return sum - min;
}

int modifier(int score)
{
    return (score - 10) >> 1;
}

dnd_character_t make_dnd_character(void)
{
    dnd_character_t result;

    result.charisma = ability();
    result.constitution = ability();
    result.dexterity = ability();
    result.intelligence = ability();
    result.strength = ability();
    result.wisdom = ability();

    result.hitpoints = 10 + modifier(result.constitution);

    return result;
}

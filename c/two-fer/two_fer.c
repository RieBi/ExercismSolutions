#include "two_fer.h"

static const char *part1 = "One for ";
static const char *part2 = ", one for me.";
static const char *you = "you";

static char *copy_advance(char *buffer, const char *value)
{
    while (*value) {
        *buffer = *value;
        buffer++;
        value++;
    }

    return buffer;
}

void two_fer(char *buffer, const char *name)
{
    char *pointer = copy_advance(buffer, part1);
    
    if (!name) {
        name = you;
    }

    pointer = copy_advance(pointer, name);
    pointer = copy_advance(pointer, part2);
    *pointer = '\0';
}

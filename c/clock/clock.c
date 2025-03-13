#include "clock.h"
#include <string.h>

int get_hour(char *text);
int get_minute(char *text);

clock_t clock_create(int hour, int minute)
{
    if (minute < 0 || hour < 0)
    {
        return clock_add(clock_create(0, 0), hour * 60 + minute);
    }

    hour = (hour + minute / 60) % 24;
    minute %= 60;

    return (clock_t) {
        .text = {
            hour / 10 + '0',
            hour % 10 + '0',
            ':',
            minute / 10 + '0',
            minute % 10 + '0',
            '\0'}};
}

clock_t clock_add(clock_t clock, int minute_add)
{
    if (minute_add < 0)
    {
        return clock_subtract(clock, -minute_add);
    }

    int hour = get_hour(clock.text);
    int minute = get_minute(clock.text);

    minute += minute_add;
    hour += minute / 60;
    minute %= 60;
    hour %= 24;

    return clock_create(hour, minute);
}

clock_t clock_subtract(clock_t clock, int minute_subtract)
{
    if (minute_subtract < 0)
    {
        return clock_add(clock, -minute_subtract);
    }

    int hour = get_hour(clock.text);
    int minute = get_minute(clock.text);

    minute -= minute_subtract;
    if (minute < 0)
    {
        minute = -minute;
        hour -= minute / 60 + 1;
        minute = 60 - minute % 60;
    }

    if (hour < 0)
    {
        hour = -hour;
        hour = 24 - hour % 24;
    }

    return clock_create(hour, minute);
}

bool clock_is_equal(clock_t a, clock_t b)
{
    return strcmp(a.text, b.text) == 0;
}

int get_hour(char *text)
{
    return (text[0] - '0') * 10 + text[1] - '0';
}

int get_minute(char *text)
{
    return (text[3] - '0') * 10 + text[4] - '0';
}

#include "leap.h"

bool leap_year(int year)
{
    return !(year % 100 ? year % 4 : year % 400);
}

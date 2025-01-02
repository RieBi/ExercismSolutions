#include "triangle.h"

static bool is_valid_triangle(triangle_t triangle)
{
    return triangle.a && triangle.b && triangle.c &&
           triangle.a + triangle.b >= triangle.c &&
           triangle.a + triangle.c >= triangle.b &&
           triangle.b + triangle.c >= triangle.a;
}

bool is_equilateral(triangle_t triangle)
{
    return triangle.a && triangle.a == triangle.b && triangle.a == triangle.c;
}

bool is_isosceles(triangle_t triangle)
{
    return is_valid_triangle(triangle) &&
           (triangle.a == triangle.b || triangle.a == triangle.c || triangle.b == triangle.c);
}

bool is_scalene(triangle_t triangle)
{
    return is_valid_triangle(triangle) &&
           (triangle.a != triangle.b && triangle.a != triangle.c && triangle.b != triangle.c);
}

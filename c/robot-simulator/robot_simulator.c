#include "robot_simulator.h"

robot_status_t robot_create(robot_direction_t direction, int x, int y)
{
    robot_status_t robot;
    robot.direction = direction;
    robot.position = (robot_position_t) {x, y};

    return robot;
}

static void move_0(int *x, int *y)
{
    (void)x;
    (*y)++;
}

static void move_1(int *x, int *y)
{
    (void)y;
    (*x)++;
}

static void move_2(int *x, int *y)
{
    (void)x;
    (*y)--;
}

static void move_3(int *x, int *y)
{
    (void)y;
    (*x)--;
}

void (*move_funcs[])(int *, int *) = {move_0, move_1, move_2, move_3};

void robot_move(robot_status_t *robot, const char *commands)
{
    if (!commands)
        return;
    
    robot_direction_t dir = robot->direction;
    int x = (robot->position).x;
    int y = (robot->position).y;

    while (*commands != '\0') {
        char command = *commands;
        if (command == 'L') {
            if (dir == 0) {
                dir = 3;
            } else {
                dir--;
            }
        } else if (command == 'R') {
            if (dir == 3) {
                dir = 0;
            } else {
                dir++;
            }
        } else if (command == 'A') {
            move_funcs[dir](&x, &y);
        } else {
            return;
        }

        commands++;
    }

    robot->direction = dir;
    (robot->position).x = x;
    (robot->position).y = y;
}

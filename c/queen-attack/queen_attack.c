#include "queen_attack.h"
#include <stdbool.h>

static bool is_invalid_position(position_t position)
{
    return position.row > 7 || position.column > 7;
}

static bool are_positions_equal(position_t pos1, position_t pos2)
{
    return pos1.column == pos2.column &&
           pos1.row == pos2.row;
}

attack_status_t can_attack(position_t queen_1, position_t queen_2)
{
    if (is_invalid_position(queen_1) || is_invalid_position(queen_2) || are_positions_equal(queen_1, queen_2)) {
        return INVALID_POSITION;
    }

    return queen_1.column == queen_2.column ||
                   queen_1.row == queen_2.row ||
                   queen_1.row + queen_1.column == queen_2.row + queen_2.column ||
                   (int)queen_1.row - queen_1.column == (int)queen_2.row - queen_2.column
               ? CAN_ATTACK
               : CAN_NOT_ATTACK;
}

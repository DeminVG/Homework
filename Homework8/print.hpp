#pragma once
#include "class&struct.hpp"

namespace My_Print_Function {
    void printHorizontalBorder(int size_field);
    void printField(const GameField& field, int size_field);
    void printGameOutcome(const TurnOutcome& outcome, Sign player_sign);
}
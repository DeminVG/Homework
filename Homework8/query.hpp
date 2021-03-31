#pragma once
#include "checks.hpp"
#include "query.hpp"

namespace My_Query_Function {
    bool askQuestion(char positive, char negative);
    Sign queryPlayerSign();
    int queryFieldSize();
    bool queryPlayAgain();
    void putSign(GameField& field, Sign sign, size_t row, size_t column, size_t size_field);
}
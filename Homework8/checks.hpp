#pragma once
#include "class&struct.hpp"

namespace My_Checks_Function {

bool isValidCell(size_t row, size_t column, size_t size_field);
CellState getCell(const GameField& field, size_t row, size_t column, size_t size_field);
bool isCellEmpty(const GameField& field, size_t row, size_t column, size_t size_field);
bool isDraw(const GameField& field, size_t size_field);
bool checkLine(const GameField& field, size_t start_row, size_t start_column, int delta_row, int delta_column, size_t size_field);

}

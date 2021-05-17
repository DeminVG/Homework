#include <iostream>
#include "checks.hpp"

namespace My_Checks_Function {

//  checking the correctness of the input of the row and column
bool isValidCell(size_t row, size_t column, size_t size_field) {   
    return row >= 0 && row < size_field && column >= 0 && column < size_field;
}

//  cell state
CellState getCell(const GameField& field, size_t row, size_t column, size_t size_field) {
    if (!isValidCell(row, column, size_field)) return CellState::Empty;
    return field.cells[column * size_field + row];
}

//  checking whether the cell is free
bool isCellEmpty(const GameField& field, size_t row, size_t column, size_t size_field) {   
    return getCell(field, row, column, size_field) == CellState::Empty;
}

// this is a draw, there are no free cells
bool isDraw(const GameField& field, size_t size_field) {   
    for (size_t i = 0; i < size_field * size_field; i++) {
        if (field.cells[i] == CellState::Empty) {
            return false;
        }
    }
    return true;
}

// Checking the winning line
bool checkLine(const GameField& field, size_t start_row, size_t start_column, int delta_row, int delta_column, size_t size_field) {
    size_t current_row = start_row;
    size_t current_column = start_column;
    auto first = getCell(field, start_row, start_column, size_field);
    if (first == CellState::Empty) {
        return false;
    }
    while (isValidCell(current_row, current_column, size_field)) {
        if (getCell(field, current_row, current_column, size_field) != first) {
            return false;
        }
        current_row += delta_row;
        current_column += delta_column;
    }
    return true;
}
}
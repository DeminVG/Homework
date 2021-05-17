#include <iostream>
#include "checks.hpp"

using namespace My_Checks_Function;

namespace My_Print_Function {

//  printing horizontal field borders
void printHorizontalBorder(int size_field) {
    std::cout << "===";
    for (size_t row = 0; row < size_field; row++) {
        std::cout << "==";
    }
    std::cout << "\n";
}

//  printing a field
void printField(const GameField& field, int size_field) {
    printHorizontalBorder(size_field);  //  printing the upper border of the field
    for (size_t row = 0; row < size_field; row++) {
        std::cout << "||";
        for (size_t column = 0; column < size_field; column++) {
            switch (getCell(field, row, column, size_field))
            {
            case CellState::Empty:
                std::cout << " ";
                break;
            case CellState::X:
                std::cout << "X";
                break;
            case CellState::O:
                std::cout << "O";
                break;
            }
            std::cout << "|";
        }
        std::cout << "|\n";
    }
    printHorizontalBorder(size_field);  //  printing the lower border of the field
}

// output of the game result
void printGameOutcome(const TurnOutcome& outcome, Sign player_sign) {
    if (outcome.isDraw) {   
        std::cout << "It's a draw.\n";
    } else if (outcome.victor == player_sign) { 
        std::cout << "Congrats! You're winner.\n";
    } else {
        std::cout << "No luck this time.\n";
    }
}

}
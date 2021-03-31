#include <iostream>
#include "query.hpp"
#include "checks.hpp"

using namespace My_Checks_Function;

namespace My_Query_Function {

//  request to enter a character
bool askQuestion(char positive, char negative) {   
    char sign {};
    std::cin >> sign;
    sign = tolower(sign);   // there is no difference between uppercase and lowercase letters

    while (sign != positive && sign != negative) {  // request to enter a character by looping to the correct one
        std::cout << "Wrong input: received '" << sign << "', should be one of " << positive << " or " << negative << "\n";
        std::cin >> sign;
        sign = tolower(sign);
    }
    return sign == positive;
}

//  request to select X or O from the user
Sign queryPlayerSign() {    
    std::cout << "Please input wheter you're X or O: ";
    bool isX = askQuestion('x', 'o');
    return isX ? Sign::X : Sign::O; //  returns true if X or false if Y
}

// request for field size
int queryFieldSize() {
    int max_size = 20;  // you can increase the size of the field without restrictions
    std::cout << "Please input size field (3..." << max_size << "): ";
    int size;
    std::cin >> size;
 
    while (size < 3 || size > max_size) {  //   request to enter a character by looping to the correct one
        std::cout << "Wrong input: received '" << size << "', the size field should be from 3 to 20:\n";
        std::cout << "Please input size field (3...20): ";
        std::cin >> size;
    }
    return size;
}

// request to continue the game
bool queryPlayAgain() {
    std::cout << "Want to play again? [y or n]: ";
    return askQuestion('y', 'n');
}

//  returning the value in the cell
void putSign(GameField& field, Sign sign, size_t row, size_t column, size_t size_field) {
    if (isValidCell(row, column, size_field)) {
        field.cells[column * size_field + row] = (sign == Sign::X) ? CellState::X : CellState::O;
    }
}
}
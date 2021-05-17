#include <iostream>
#include <random>
#include "checks.hpp"
#include "print.hpp"
#include "query.hpp"

using namespace My_Checks_Function;
using namespace My_Query_Function;
using namespace My_Print_Function;

namespace My_Game_Function {

#define CHECK_LINE(start_row, start_column, delta_row, delta_column, size_field) \
    if (checkLine(field, start_row, start_column, delta_row, delta_column, size_field)) { \
        outcome.isOver = true; \
        outcome.victor = getCell(field, start_row, start_column, size_field) == CellState::X ? Sign::X : Sign::O; \
        return outcome; \
    }
// checking the outcome of the game
TurnOutcome checkTurnOutcome(const GameField& field, const size_t size_field) {
    TurnOutcome outcome {}; 
    // checking the filling of lines by lines
    for (size_t row = 0; row < size_field; row++) {
        CHECK_LINE(row, 0, 0, 1, size_field)
    }
    // checking the filling of lines by lines
    for (size_t column = 0; column < size_field; column++) {
        CHECK_LINE(0, column, 1, 0, size_field)
    }
    // checking the filling of the lines along the diagonals
    CHECK_LINE(0, 0, 1, 1, size_field)
    CHECK_LINE(0, (size_field-1), 1, -1, size_field)
    // check for the absence of free cells for the move
    if (isDraw(field, size_field)) {
        outcome.isDraw = true;
    }
    return outcome;
}
#undef CHECK_LINE

    // computer progress
void processAiTurn(GameField& field, Sign ai_sign, size_t size_field) {    
    
    auto *empty_cells = new int[size_field * size_field];  //   allocating memory for a dynamic array of fields
    const size_t kInvalidCellIdx = 42;

    //  fill the array with the numbers 42, to return in case of an error
    std::fill_n(empty_cells, size_field * size_field, kInvalidCellIdx);  
    size_t last_empty_cell_idx = 0;

    //  fill the array with free cell indexes and count the number of free cells
    for (size_t i = 0; i < size_field * size_field; i++) {
        if (field.cells[i] == CellState::Empty) {
            empty_cells[last_empty_cell_idx] = i;
            last_empty_cell_idx++;
        }
    }
    //  we put our own sign in each free cell, if we win or draw, then we finish the check
    for (size_t i = 0; i < last_empty_cell_idx; i++) {
        size_t target = empty_cells[i];
        field.cells[target] = ai_sign == Sign::X ? CellState::X : CellState::O;
        auto outcome = checkTurnOutcome(field, size_field);
        if (outcome.isOver || outcome.isDraw) {
            delete [] empty_cells;    //    clearing the memory from the dynamic array
            return;
        }
        field.cells[target] = CellState::Empty;
    //  we put the opponent's sign in each free cell, if he wins, 
    //  then we finish the check and put our own sign here to prevent him from winning
        auto opposite_sign = ai_sign == Sign::X ? Sign::O : Sign::X;
        field.cells[target] = opposite_sign == Sign::X ? CellState::X : CellState::O;
        outcome = checkTurnOutcome(field, size_field);
        if (outcome.isOver) {
            field.cells[target] = ai_sign == Sign::X ? CellState::X : CellState::O;
            delete [] empty_cells;    //    clearing the memory from the dynamic array
            return;
        }
        field.cells[target] = CellState::Empty;
    }
    // we randomly select a free cell if the first two conditions are not met
    static std::random_device rd;
    static std::mt19937 mt(rd());
    std::uniform_int_distribution<size_t> dist(0, last_empty_cell_idx - 1);
    size_t target = empty_cells[dist(mt)];
    putSign(field, ai_sign, target % size_field, target / size_field, size_field);
    delete [] empty_cells;    //    clearing the memory from the dynamic array
}

//  player's turn
void processPlayerTurn(GameField& field, Sign player_sign, int size_field) {
    std::cout << "Enter row and column: ";

    int row, column;
    std::cin >> row >> column;

    while (!isValidCell(row - 1, column - 1, size_field) || !isCellEmpty(field, row - 1, column - 1, size_field)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Wrong input, please enter row and column of an empty cell: ";
        std::cin >> row >> column;
    }

    putSign(field, player_sign, row - 1, column - 1, size_field);
}

//  game cycle
TurnOutcome runGameLoop(Sign player_sign, int size_field) { 
    
    GameData game_data {size_field * size_field};    // creating a field with the size specified when entering

    TurnOutcome outcome {};

    while(true) {
        if(player_sign == Sign::X) {    //  selecting the player's move or the AI
            processPlayerTurn(game_data.field, Sign::X, size_field);        // the player walks
        } else {
            processAiTurn(game_data.field, Sign::X, size_field);            // walking AI
        }
        
        printField(game_data.field, size_field);
        outcome = checkTurnOutcome(game_data.field, size_field);
        if (outcome.isOver || outcome.isDraw) {
            return outcome;
        }

        if(player_sign == Sign::O) {
            processPlayerTurn(game_data.field, Sign::O, size_field);
        } else {
            processAiTurn(game_data.field, Sign::O, size_field);
        }
        
        printField(game_data.field, size_field);
        outcome = checkTurnOutcome(game_data.field, size_field);
        if (outcome.isOver || outcome.isDraw) {
            return outcome;
        }
    }
}
}
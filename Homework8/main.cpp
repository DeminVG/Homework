//  Tic tac Toe game on an endless field
#include <iostream>
#include "checks.hpp"
#include "query.hpp"
#include "print.hpp"
#include "game.hpp"

using namespace My_Checks_Function;
using namespace My_Query_Function;
using namespace My_Print_Function;
using namespace My_Game_Function;

int main() {    
    int  size_field = queryFieldSize();          // request for field size
    Sign player_sign = queryPlayerSign();        // the player chooses X or O

    bool shouldExit = false;
    //  game cycle by games
    while(!shouldExit) {    
        auto outcome = runGameLoop(player_sign, size_field);    //  calling the game loop
        printGameOutcome(outcome, player_sign);                 //  output of the current game result
        shouldExit = !queryPlayAgain();                         //  request to continue the game
    }
    return 0;
}
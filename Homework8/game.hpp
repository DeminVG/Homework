#pragma once
#include "class&struct.hpp"

namespace My_Game_Function {

    void processAiTurn(GameField& field, Sign ai_sign, size_t size_field);
    void processPlayerTurn(GameField& field, Sign player_sign, int size_field);
    TurnOutcome checkTurnOutcome(const GameField& field, const size_t size_field);
    TurnOutcome runGameLoop(Sign player_sign, int size_field);
    
}
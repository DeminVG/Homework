#pragma once

enum class CellState {  //  listing the state of a cell
    Empty, X, O
};

enum class Sign {       //  listing the player's status
    X, O
};

struct GameField {      //  game field
    int size = 0;
    CellState* cells = new CellState[size];
};

struct GameData {       //  game data
    GameField field;
    Sign player_sign;
};

struct TurnOutcome {
    bool isOver : 1;    // finished
    Sign victor;        // winner
    bool isDraw : 1;    // draw
};
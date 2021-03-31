#include <iostream>
#include <random>


enum class CellState {  //  перечисление состояния ячейки
    Empty, X, O
};

enum class Sign {   //  перечисление состояния игрока
    X, O
};

struct GameField {  //  поле игры 3х3 ячейки
    int size = 0;
    CellState* cells = new CellState[size];
};

struct GameData {
    GameField field;
    Sign player_sign;
};

struct TurnOutcome {
    bool isOver : 1;    // окончена
    Sign victor;    // победитель
    bool isDraw : 1;    // ничья
};

//  проверка корректности ввода строки и колонки
bool isValidCell(size_t row, size_t column, size_t size_field) {   
    return row >= 0 && row < size_field && column >= 0 && column < size_field;
}

//  состояние ячейки
CellState getCell(const GameField& field, size_t row, size_t column, size_t size_field) {
    if (!isValidCell(row, column, size_field)) return CellState::Empty;
    return field.cells[column * size_field + row];
}

//проверка свободна ли ячейка
bool isCellEmpty(const GameField& field, size_t row, size_t column, size_t size_field) {   
    return getCell(field, row, column, size_field) == CellState::Empty;
}

void putSign(GameField& field, Sign sign, size_t row, size_t column, size_t size_field) {
    if (isValidCell(row, column, size_field)) {
        field.cells[column * size_field + row] = (sign == Sign::X) ? CellState::X : CellState::O;
    }
}

 //  запрос на ввод символа
bool askQuestion(char positive, char negative) {   
    char sign {};
    std::cin >> sign;
    sign = tolower(sign);   // нет разницы между заглавными и строчными буквами

    while (sign != positive && sign != negative) {  //запрос на ввод символа циклом до правильного
        std::cout << "Wrong input: received '" << sign << "', should be one of " << positive << " or " << negative << "\n";
        std::cin >> sign;
        sign = tolower(sign);
    }
    return sign == positive;
}

//  запрос выбора Х или О у пользователя
Sign queryPlayerSign() {    
    std::cout << "Please input wheter you're X or O: ";
    bool isX = askQuestion('x', 'o');
    return isX ? Sign::X : Sign::O; //  возвращает true если Х или false, если Y
}

// запрос размера поля
int queryFieldSize() {
    std::cout << "Please input size field (3...20): ";
    int size;
    std::cin >> size;
 
    while (size < 3 || size > 20) {  //запрос на ввод символа циклом до правильного
        std::cout << "Wrong input: received '" << size << "', the size field should be from 3 to 20:\n";
        std::cout << "Please input size field (3...20): ";
        std::cin >> size;
    }
    return size;
}

TurnOutcome checkTurnOutcome(const GameField& field, size_t size_field);   //структура исхода игры

// ход ИИ
void processAiTurn(GameField& field, Sign ai_sign, size_t size_field) {    
    
    auto *empty_cells = new int[size_field * size_field];  //выделяем память под динамический массив поля
    const size_t kInvalidCellIdx = 42;
    std::fill_n(empty_cells, size_field * size_field, kInvalidCellIdx);   //заполняем массив числами 42, для возврата в случае ошибки
    size_t last_empty_cell_idx = 0;
    //заполняем массив индексами свободных клеток и считаем количество свободных клеток
    for (size_t i = 0; i < size_field * size_field; i++) {
        if (field.cells[i] == CellState::Empty) {
            empty_cells[last_empty_cell_idx] = i;
            last_empty_cell_idx++;
        }
    }
    //  ставим в каждую свободную клетку свой знак, если выигрываем или ничья,
    //  то заканчиваем проверку
    for (size_t i = 0; i < last_empty_cell_idx; i++) {
        size_t target = empty_cells[i];
        field.cells[target] = ai_sign == Sign::X ? CellState::X : CellState::O;
        auto outcome = checkTurnOutcome(field, size_field);
        if (outcome.isOver || outcome.isDraw) {
            delete [] empty_cells;    //очищаем память от динамического массива
            return;
        }
        field.cells[target] = CellState::Empty;
    //  ставим в каждую свободную клетку знак опонента, если он выигрывает,
    //  то заканчиваем проверку и ставим сюда свой знак, чтобы помешать выиграть
        auto opposite_sign = ai_sign == Sign::X ? Sign::O : Sign::X;
        field.cells[target] = opposite_sign == Sign::X ? CellState::X : CellState::O;
        outcome = checkTurnOutcome(field, size_field);
        if (outcome.isOver) {
            field.cells[target] = ai_sign == Sign::X ? CellState::X : CellState::O;
            delete [] empty_cells;    //очищаем память от динамического массива
            return;
        }
        field.cells[target] = CellState::Empty;
    }
    // выбираем случайно свободную клетку, если первые два условия не выполнились
    static std::random_device rd;
    static std::mt19937 mt(rd());
    std::uniform_int_distribution<size_t> dist(0, last_empty_cell_idx - 1);
    size_t target = empty_cells[dist(mt)];
    putSign(field, ai_sign, target % size_field, target / size_field, size_field);
    delete [] empty_cells;    //очищаем память от динамического массива
}

//ход игрока
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

void printField(const GameField& field, int size_field);

// это ничья, нет свободных ячеек
bool isDraw(const GameField& field, size_t size_field) {   
    for (size_t i = 0; i < size_field * size_field; i++) {
        if (field.cells[i] == CellState::Empty) {
            return false;
        }
    }
    return true;
}

// Проверка выигрышной линии
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

#define CHECK_LINE(start_row, start_column, delta_row, delta_column, size_field) \
    if (checkLine(field, start_row, start_column, delta_row, delta_column, size_field)) { \
        outcome.isOver = true; \
        outcome.victor = getCell(field, start_row, start_column, size_field) == CellState::X ? Sign::X : Sign::O; \
        return outcome; \
    }

// исход игры
TurnOutcome checkTurnOutcome(const GameField& field, const size_t size_field) {
    TurnOutcome outcome {}; 
    // проверяем заполнение линий по строкам
    for (size_t row = 0; row < size_field; row++) {
        CHECK_LINE(row, 0, 0, 1, size_field)
    }
    // проверяем заполнение линий по строкам
    for (size_t column = 0; column < size_field; column++) {
        CHECK_LINE(0, column, 1, 0, size_field)
    }
    // проверяем заполнение линий по диагоналям
    CHECK_LINE(0, 0, 1, 1, size_field)
    CHECK_LINE(0, (size_field-1), 1, -1, size_field)
    // проверяем на отсутствие свободных клеток для хода
    if (isDraw(field, size_field)) {
        outcome.isDraw = true;
    }
    return outcome;
}

#undef CHECK_LINE

//игоровой цикл
TurnOutcome runGameLoop(Sign player_sign, int size_field) { 
    
    GameData game_data {size_field * size_field};    //создаем поле с указанным при вводе размером

    TurnOutcome outcome {};

    while(true) {
        if(player_sign == Sign::X) {    //  выбор хода игрока или ИИ
            processPlayerTurn(game_data.field, Sign::X, size_field);        // ходит игрок
        } else {
            processAiTurn(game_data.field, Sign::X, size_field);            // ходит ИИ
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

//печать горизонтальных границ поля
void printHorizontalBorder(int size_field) {
    std::cout << "===";
    for (size_t row = 0; row < size_field; row++) {
        std::cout << "==";
    }
    std::cout << "\n";
}

//печать поля
void printField(const GameField& field, int size_field) {
    printHorizontalBorder(size_field);  //печать верхней границы поля
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
    printHorizontalBorder(size_field);  //печать нижней границы поля
}

// запрос на продолжение игры
bool queryPlayAgain() {
    std::cout << "Want to play again? [y or n]: ";
    return askQuestion('y', 'n');
}

// вывод результата игры
void printGameOutcome(const TurnOutcome& outcome, Sign player_sign) {
    if (outcome.isDraw) {   
        std::cout << "It's a draw.\n";
    } else if (outcome.victor == player_sign) { 
        std::cout << "Congrats! You're winner.\n";
    } else {
        std::cout << "No luck this time.\n";
    }
}

int main() {    
    int  size_field = queryFieldSize();          //запрос размера поля
    Sign player_sign = queryPlayerSign();        //игрок выбирает Х или О

    bool shouldExit = false;
    //игровой цикл по играм
    while(!shouldExit) {    
        auto outcome = runGameLoop(player_sign, size_field);    //вызов игрового цикла
        printGameOutcome(outcome, player_sign);                 //вывод результата текущей игры
        shouldExit = !queryPlayAgain();                         //запрос на продолжение игры
    }
    return 0;
}

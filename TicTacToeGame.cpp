#include "TicTacToeGame.h"
#include <sstream>

#define EMPTY_SQUARE '*'
#define CIRCLE 'O'
#define EX 'X'

using namespace std;

int TicTacToeGame::tieResult = 0;
int TicTacToeGame::difficulty = 0;

TicTacToeGame::TicTacToeGame() {
    for (int i = 0; i < TICTACTOEGAME_SIZE; i++) {
        for (int j = 0; j < TICTACTOEGAME_SIZE; j++) {
            board[i][j] = EMPTY_SQUARE;
        }
    }
}

bool TicTacToeGame::tie() const {
    for (int i = 0; i < TICTACTOEGAME_SIZE; i++) {
        for (int j = 0; j < TICTACTOEGAME_SIZE; j++) {
            if (board[i][j] == '*') {
                return false;
            }
        }
    }
    return true;
}

bool TicTacToeGame::isGameOver() const {
    char square = board[0][0];
    bool found = false;

    if (square != EMPTY_SQUARE) {
        // check the main diagonal
        for (int i = 1; i < TICTACTOEGAME_SIZE; i++) {
            if (board[i][i] != square) {
                found = true;
                break;
            }
        }
        if (!found)
            return true;
    }

    // check the secondary diagonal
    square = board[0][TICTACTOEGAME_SIZE - 1];
    if (square != EMPTY_SQUARE) {
        found = false;
        for (int i = 1; i < TICTACTOEGAME_SIZE; i++) {
            if (board[i][TICTACTOEGAME_SIZE - i - 1] != square) {
                found = true;
                break;
            }
        }
        if (!found)
            return true;
    }

    // check the lines
    for (int i = 0; i < TICTACTOEGAME_SIZE; i++) {
        square = board[i][0];
        if (square != EMPTY_SQUARE) {
            found = false;
            for (int j = 1; j < TICTACTOEGAME_SIZE; j++) {
                if (board[i][j] != square) {
                    found = true;
                    break;
                }
            }
            if (!found)
                return true;
        }
    }
    // check the columns
    for (int i = 0; i < TICTACTOEGAME_SIZE; i++) {
        square = board[0][i];
        if (square != EMPTY_SQUARE) {
            found = false;
            for (int j = 1; j < TICTACTOEGAME_SIZE; j++) {
                if (board[j][i] != square) {
                    found = true;
                    break;
                }
            }
            if (!found)
                return true;
        }
    }
    if (tie() == true) {
        tieResult = 1;
        return true;
    }
    return false;
}

void TicTacToeGame::playTurn() {
    // the computer is always O
    if (difficulty == 1) {
        while (true) {
            int i = rand() % TICTACTOEGAME_SIZE;
            int j = rand() % TICTACTOEGAME_SIZE;
            if (board[i][j] == EMPTY_SQUARE) {
                board[i][j] = CIRCLE;
                break;
            }
        }
    } else {

        // first importent move
        if (board[1][1] == EX && board[0][2] == EMPTY_SQUARE)
        {
            board[0][2] = CIRCLE;
            return;
        }

        if (board[0][1] == EX && board[1][1] == CIRCLE && board[2][2] == EX && board[1][2] == EMPTY_SQUARE)
        {
            board[1][2] = CIRCLE;
            return;
        }

        if (board[0][1] == EX && board[1][1] == CIRCLE && board[2][0] == EX && board[1][0] == EMPTY_SQUARE)
        {
            board[1][0] = CIRCLE;
            return;
        }

        if(board[0][1] == EX && board[1][1] == CIRCLE && board[2][2] == EX && board[1][2] == CIRCLE && board[2][0] == EMPTY_SQUARE) {
            board[2][0] = CIRCLE;
            return;
        }

        if(board[0][1] == EX && board[1][1] == CIRCLE && board[2][0] == EX && board[1][0] == CIRCLE && board[1][2] == EX && board[2][2] == EMPTY_SQUARE) {
            board[2][2] = CIRCLE;
            return;
        }

        //
        if (board[2][1] == EX && board[1][1] == CIRCLE && board[0][0] == EX && board[1][0] == EMPTY_SQUARE)
        {
            board[1][0] = CIRCLE;
            return;
        }

        if(board[2][1] == EX && board[1][1] == CIRCLE && board[0][0] == EX && board[1][0] == CIRCLE && board[2][0] == EMPTY_SQUARE) {
            board[2][0] = CIRCLE;
            return;
        }

        //
        if (board[2][1] == EX && board[1][1] == CIRCLE && board[0][2] == EX && board[1][2] == EMPTY_SQUARE)
        {
            board[1][2] = CIRCLE;
            return;
        }
        if(board[2][1] == EX && board[1][1] == CIRCLE && board[0][2] == EX && board[1][2] == CIRCLE && board[0][0] == EMPTY_SQUARE) {
            board[0][0] = CIRCLE;
            return;
        }


        // row

        if (board[0][0] == EX && board[0][1] == EX && board[0][2] == EMPTY_SQUARE) {
            board[0][2] = CIRCLE;
            return;
        }
        if (board[0][1] == EX && board[0][2] == EX && board[0][0] == EMPTY_SQUARE) {
            board[0][0] = CIRCLE;
            return;
        }
        if (board[0][0] == EX && board[0][2] == EX && board[0][1] == EMPTY_SQUARE) {
            board[0][1] = CIRCLE;
            return;
        }

        if (board[1][0] == EX && board[1][1] == EX && board[1][2] == EMPTY_SQUARE) {
            board[1][2] = CIRCLE;
            return;
        }
        if (board[1][1] == EX && board[1][2] == EX && board[1][0] == EMPTY_SQUARE) {
            board[1][0] = CIRCLE;
            return;
        }
        if (board[1][0] == EX && board[1][2] == EX && board[1][1] == EMPTY_SQUARE) {
            board[1][1] = CIRCLE;
            return;
        }

        if (board[2][0] == EX && board[2][1] == EX && board[2][2] == EMPTY_SQUARE) {
            board[2][2] = CIRCLE;
            return;
        }
        if (board[2][1] == EX && board[2][2] == EX && board[2][0] == EMPTY_SQUARE) {
            board[2][0] = CIRCLE;
            return;
        }
        if (board[2][0] == EX && board[2][2] == EX && board[2][1] == EMPTY_SQUARE) {
            board[2][1] = CIRCLE;
            return;
        }


        // col

        if (board[0][0] == EX && board[1][0] == EX && board[2][0] == EMPTY_SQUARE) {
            board[2][0] = CIRCLE;
            return;
        }
        if (board[1][0] == EX && board[2][0] == EX && board[0][0] == EMPTY_SQUARE) {
            board[0][0] = CIRCLE;
            return;
        }
        if (board[0][0] == EX && board[2][0] == EX && board[1][0] == EMPTY_SQUARE) {
            board[1][0] = CIRCLE;
            return;
        }

        if (board[0][1] == EX && board[1][1] == EX && board[2][1] == EMPTY_SQUARE) {
            board[2][1] = CIRCLE;
            return;
        }
        if (board[1][1] == EX && board[2][1] == EX && board[0][1] == EMPTY_SQUARE) {
            board[0][1] = CIRCLE;
            return;
        }
        if (board[0][1] == EX && board[2][1] == EX && board[1][1] == EMPTY_SQUARE) {
            board[1][1] = CIRCLE;
            return;
        }

        if (board[0][2] == EX && board[1][2] == EX && board[2][2] == EMPTY_SQUARE) {
            board[2][2] = CIRCLE;
            return;
        }
        if (board[1][2] == EX && board[2][2] == EX && board[0][2] == EMPTY_SQUARE) {
            board[0][2] = CIRCLE;
            return;
        }
        if (board[0][2] == EX && board[2][2] == EX && board[1][2] == EMPTY_SQUARE) {
            board[1][2] = CIRCLE;
            return;
        }

        // line
        if (board[0][0] == EX && board[1][1] == EX && board[2][2] == EMPTY_SQUARE) {
            board[2][2] = CIRCLE;
            return;
        }
        if (board[2][2] == EX && board[1][1] == EX && board[0][0] == EMPTY_SQUARE) {
            board[0][0] = CIRCLE;
            return;
        }
        if (board[0][0] == EX && board[2][2] == EX && board[1][1] == EMPTY_SQUARE) {
            board[1][1] = CIRCLE;
            return;
        }

        if (board[0][2] == EX && board[1][1] == EX && board[2][0] == EMPTY_SQUARE) {
            board[2][0] = CIRCLE;
            return;
        }
        if (board[2][0] == EX && board[1][1] == EX && board[0][2] == EMPTY_SQUARE) {
            board[0][2] = CIRCLE;
            return;
        }
        if (board[2][0] == EX && board[0][2] == EX && board[1][1] == EMPTY_SQUARE) {
            board[1][1] = CIRCLE;
            return;
        }

        while (true) {
            int i = rand() % TICTACTOEGAME_SIZE;
            int j = rand() % TICTACTOEGAME_SIZE;
            if (board[i][j] == EMPTY_SQUARE) {
                board[i][j] = CIRCLE;
                break;
            }
        }
    }

}

bool TicTacToeGame::playUserTurn(string str) {
    // the user is always X
    stringstream s(str);
    if (!s) {
        return false;
    }
    int i, j;
    s >> i;
    i--;
    if (!s) {
        return false;
    }

    s >> j;
    j--;
    if (!s) {
        cout << "Invalid move, please try again" << endl << endl;
        return false;
    }
    if ((i < 0) || (i >= TICTACTOEGAME_SIZE) || (j < 0) || (j >= TICTACTOEGAME_SIZE)) {
        cout << "Invalid move, please try again" << endl << endl;
        return false;
    }
    if (board[i][j] != EMPTY_SQUARE) {
        cout << "Invalid move, please try again" << endl << endl;
        return false;
    }
    board[i][j] = EX;
    return true;
}

string TicTacToeGame::show() {
    stringstream s;
    for (int i = 0; i < TICTACTOEGAME_SIZE; i++) {
        for (int j = 0; j < TICTACTOEGAME_SIZE; j++) {
            s << board[i][j];
        }
        s << endl;
    }
    s << endl;
    return s.str();
}

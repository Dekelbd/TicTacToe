#pragma once
#include "BoardGame.h"
#include <string>
#include <iostream>

using namespace std;


#define TICTACTOEGAME_SIZE 3


class TicTacToeGame :
	public BoardGame

{
public:
    static int tieResult;
    static int difficulty;
	TicTacToeGame();
	virtual bool isGameOver() const;
	virtual void playTurn();
	virtual bool tie() const;
	virtual bool playUserTurn(string);
	virtual string show();
private:
	char board[TICTACTOEGAME_SIZE][TICTACTOEGAME_SIZE];
};


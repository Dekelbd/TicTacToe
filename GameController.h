#pragma once

#include "UI.h"
#include "Game.h"
#include <string>

using namespace std;

class UI;
class Game;

class GameController
{
public:
	GameController(UI&, Game&);
	bool isGameOver() const;
	void playTurn();
	void showGame();
	bool playUserTurn(string);
private:
	UI& ui;
	Game& game;
};


#pragma once

#include "GameController.h"
#include "Game.h"

class GameController;
class Game;

class UI
{
public:
	virtual bool playTurn(GameController&) = 0;
	virtual void showGame(Game&) = 0;
};


#pragma once
#include "GameUI.h"
#include "GameController.h"
class GameController;

class Console :
	public GameUI
{
public:
	virtual bool playTurn(GameController&);
	virtual void showGame(Game&);
};


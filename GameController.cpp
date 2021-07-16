#include "GameController.h"
#include "Game.h"
#include "UI.h"

GameController::GameController(UI& u, Game& g) :
	ui(u), game(g)
{
}

bool GameController::isGameOver() const
{
	return game.isGameOver();
}

void GameController::playTurn()
{
	while (!ui.playTurn(*this));
	if (!game.isGameOver())
		game.playTurn();
}

void GameController::showGame()
{
	ui.showGame(game);
}

bool GameController::playUserTurn(std::string str)
{
	return game.playUserTurn(str);
}

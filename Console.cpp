#include "Console.h"
#include "GameController.h"
#include "Game.h"
#include <string>
#include <iostream>

using namespace std;

bool Console::playTurn(GameController& controller)
{
	string str;
	cout << "Enter your turn :" << endl << "row col";
	getline(cin, str);
	return controller.playUserTurn(str);
}

void Console::showGame(Game& game)
{
	string str;
	str = game.show();
	cout << str;
}

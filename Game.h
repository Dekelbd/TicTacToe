#pragma once
#include <string>

using namespace std;

class Game
{
public:
	virtual bool isGameOver() const = 0;
    virtual bool tie() const = 0;
	virtual void playTurn() = 0;
	virtual bool playUserTurn(string) = 0;
	virtual string show() = 0;
};

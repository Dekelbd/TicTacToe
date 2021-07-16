
#include "TicTacToeGame.h"
#include "Console.h"
#include "GameController.h"
#include <iostream>

using namespace std;
int main()
{
    int gameNumber=0;
    int gameDifficulty=0;
    int gameUi = 0;

    cout << "Welcome to our game app!" << endl << endl;
    cout << "please choose the game number you want to play :" << endl;
    cout << "1) TicTacToe" << endl << "2) no game available" << endl << "3) no game available" << endl;
    do
    {
        cin >> gameNumber;
        if (gameNumber != 1)
        {
        cout << "This game is not available, please choose another game :" << endl;
        cout << "1) TicTacToe" << endl << "2) no game available" << endl << "3) no game available" << endl;
        }
    }while(gameNumber != 1);
    cin.get();

    cout << "Lets play TicTacToe !" << endl << endl;

    cout << "Please choose the UI :" << endl << "1) Console interface" << endl << "2) Graphical user interface" << endl;
    do
    {
        cin >> gameUi;
        if (gameUi != 1)
        {
            cout << "This UI is not accepted right now, please choose again :" << endl;
            cout << "1) Console interface" << endl << "2) Graphical user interface" << endl;
        }
    }while(gameUi != 1);
    cin.get();


    cout << "Please choose game difficulty :" << endl << "1) Easy" << endl << "2) Hard" << endl;
    do
    {
        cin >> gameDifficulty;
        if (gameDifficulty != 1 && gameDifficulty != 2)
        {
            cout << "This game difficulty is not accepted, please choose again :" << endl;
            cout << "1) Easy" << endl << "2) Hard" << endl;
        }
    }while((gameDifficulty != 1) && (gameDifficulty != 2));
    TicTacToeGame::difficulty = gameDifficulty;
    cin.get();

    cout << endl;
	TicTacToeGame game;
	Console ui;
	GameController controller(ui, game);
	while (!controller.isGameOver())
	{
		controller.showGame();
		controller.playTurn();
		cout << endl << "During a game" << endl;
	}

	controller.showGame();
	if(TicTacToeGame::tieResult == 1)
    {
        cout << "tie" << endl;
    }
	cout << "Game Over !!!" << endl;
	char c;
	cin >> c;
	return 0;
}

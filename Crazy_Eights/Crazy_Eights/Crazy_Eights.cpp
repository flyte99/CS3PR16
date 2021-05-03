#include <iostream>
#include <cstdlib>
#include <cctype>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>

#include "player.h"
#include "card.h"
#include "game.h"

using namespace std;

int main()
{
	char choice;												//Program won't crash if a random character is entered (not a number)
	int bots = 0;

	do
	{
		cout << "Choose 1 to Start New Game" << endl;
		cout << "Choose 2 to Read Rules" << endl;
		cout << "Choose 3 to Exit" << endl;
		cin >> choice;
		
		switch (choice)
		{
			case '1':
			{
				cout << "New Game" << endl;

				Game NewGame;									//Game initialized
				NewGame.GenerateDeck();
				NewGame.ShuffleDeck();

				NewGame.CreatePlayer();							//Player initialized and added to game

				do
				{
					cout << "How many bots? (1-9)" << endl;
					cin >> bots;
					NewGame.CreateBots(bots);					//Bots initialized and added to game
				} while (bots == 0);							//Player must play against at least one bot

				NewGame.Deal();

				NewGame.SimulateGame();

				break;
			}

			case '2':
			{				
				cout << "Rules" << endl;
				
				string rules;
				ifstream rulefile;

				rulefile.open("Rules.txt");
				while (getline(rulefile, rules))
				{
					cout << rules << endl;
				}
				rulefile.close();
				cout << endl;

				break;
			}

			case '3':
			{
				cout << "You chose to exit the program" << endl;
				break;
			}

			default:
			{
				cout << "Invalid Command" << endl;
				break;
			}
		}
	} while (choice != '3');

	return 0;
}
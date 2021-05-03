#pragma once
#include <iostream>
#include <cstdlib>
#include <cctype>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>

#include "card.h"
#include "player.h"

#ifndef GAME_H
#define GAME_H

class Player;
class Game
{
public:
	void AddPlayer(Player player);
	void CreatePlayer();
	void CreateBots(int bots);
	void GenerateDeck();
	void ShuffleDeck();
	void DisplayDecks();
	void Deal();

	bool PutDownCard(Player &player, Card card);
	void BotPutDownCard(Player &player, Card card);
	bool PickUpCard(Player &player);

	void SkipPlayer();					//When a player plays an ace
	void PickUpTwo();					//When a player plays a two
	void ChangeSuit();					//When a player plays an eight
	void ReverseOrder();				//When a player plays a jack

	void SimulateGame();

	void EndTurn();
	bool CheckEndGame();
	void ListPlayersScores();

	std::vector<Card> discardpile;		//Where the players put their cards down

private:
	std::vector<Card> deck;				//Contains a standard deck of cards
	std::vector<Card> stockpile;		//After deck is dealt the remaining cards are put in the stockpile

	static int playercounter;			//Used to determine which player's go it is
	std::vector<Player> playerorder;	//Contains each player
};

#endif
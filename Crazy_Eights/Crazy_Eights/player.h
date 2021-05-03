#pragma once
#include <iostream>
#include <cstdlib>
#include <cctype>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>

#include "card.h"

#ifndef PLAYER_H
#define PLAYER_H

class Player
{
public:
	Player();							//Default Contructor
	Player(int id);						//Constructor

	void AddCard(Card card);
	bool RemoveCard(Card card);
	
	void ListHand();
	void SortHand();
	int ScoreHand();

	int GetID();
	int GetNumberofCards();
	void GetSameRank(Card card);
	bool GetPlayableCards(Card discardcard);
	
	std::vector<Card> sameranks;		//Used as an intermediate to contain cards of the same rank
	std::vector<Card> playablecards;	//Lists the cards in the player's hand that can be played

private:
	int id;

	std::vector<Card> playerhand;		//Contains player's hand
};

#endif
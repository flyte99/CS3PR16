#include <iostream>
#include <cstdlib>
#include <cctype>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>

#include "player.h"
#include "card.h"

using namespace std;

Player::Player() {}
Player::Player(int id) //Constructor
{
	this->id = id;
}
void Player::AddCard(Card card)
{
	playerhand.push_back(card);	//Add card to end of the vector
}
bool Player::RemoveCard(Card card)
{
	char removevalue = card.GetValue();								//Get value for card to be removed
	char removesuit = card.GetSuit();								//Get suit for card to be removed

	for (int i = 0; i < playerhand.size(); i++)						//Cycles through the player's hand
	{
		char checkvalue = playerhand[i].GetValue();					//Get value for card in player's hand
		char checksuit = playerhand[i].GetSuit();					//Get suit for card in player's hand

		if (checkvalue == removevalue && checksuit == removesuit)	//If the card is in the player's hand
		{
			playerhand.erase(playerhand.begin() + i);				//Remove the card

			return true;											//Signals the card removal is successful
		}
	}
}

void Player::ListHand()
{
	cout << "[Player " << GetID() << "]" << endl;
	for (int i = 0; i < playerhand.size(); i++)	//Loops listing all the cards in the player's hand
	{
		cout << "\t" << playerhand[i].GetValue() << playerhand[i].GetSuit() << endl;
	}
	if (playerhand.size() == 0)					//If there are no cards
	{
		cout << "\tNo Cards" << endl;
	}
}
void Player::SortHand()
{
	for (int i = 0; i < playerhand.size(); i++)
	{
		int c, d;
		Card swap;
		int n = playerhand.size();

		for (c = 0; c < (n - 1); c++)													//Simple bubble sort algorithm
		{
			for (d = 0; d < n - c - 1; d++)
			{
				if (playerhand[d].ConvertValue() > playerhand[d + 1].ConvertValue())	//Sorts in ascending order
				{
					swap = playerhand[d];
					playerhand[d] = playerhand[d + 1];
					playerhand[d + 1] = swap;
				}
			}
		}
	}
}
int Player::ScoreHand()
{
	int cardsum = 0;									//Initializes sum of the cards

	for (int i = 0; i < playerhand.size(); i++)
	{
		int cardvalue = playerhand[i].ConvertValue();	//Gets value of each card and converts it to an int

		cardsum += cardvalue;							//Adds values to cardsum
	}

	return cardsum;										//Returns the sum of all cards in the hand
}

int Player::GetID()
{
	return id;
}
int Player::GetNumberofCards()
{
	return playerhand.size();		//Number of cards in hand = the size of the vector
}
void Player::GetSameRank(Card card)
{
	char removevalue = card.GetValue();								//Multiple cards must have the same value
	char removesuit = card.GetSuit();

	for (int i = 0; i < playerhand.size(); i++)						//Cycles through the player's hand
	{
		char checkvalue = playerhand[i].GetValue();					//Get value for card in player's hand
		card = playerhand[i];

		if (checkvalue == removevalue)								//Finds all the cards in the hand with the same value
		{
			sameranks.push_back(card);
		}
	}
}
bool Player::GetPlayableCards(Card discardcard)
{
	char topvalue = discardcard.GetValue();
	char topsuit = discardcard.GetSuit();
	
	for (int j = 0; j < playerhand.size(); j++)
	{
		Card checkcard = playerhand[j];

		char checkvalue = checkcard.GetValue();
		char checksuit = checkcard.GetSuit();

		if (checkvalue == topvalue || checksuit == topsuit || checkvalue == '8')
		{
			playablecards.push_back(checkcard);												//Add playable cards to vector
		}
	}
	for (int i = 0; i < playablecards.size(); i++)
	{
		int c, d;
		Card swap;
		int n = playablecards.size();

		for (c = 0; c < (n - 1); c++)														//Simple bubble sort algorithm
		{
			for (d = 0; d < n - c - 1; d++)
			{
				if (playablecards[d].ConvertValue() > playablecards[d + 1].ConvertValue())	//Sorts in ascending order
				{
					swap = playablecards[d];
					playablecards[d] = playablecards[d + 1];
					playablecards[d + 1] = swap;
				}
			}
		}
	}
	if (playablecards.size() > 0)															//If there are playable cards
	{
		return true;
	}
	else 
	{
		return false;
	}
}
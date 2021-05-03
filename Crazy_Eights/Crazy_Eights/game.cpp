#include <iostream>
#include <cstdlib>
#include <cctype>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>

#include "game.h"
#include "card.h"
#include "player.h"

using namespace std;

int Game::playercounter = 0;	//Sets player counter to 0

void Game::AddPlayer(Player player)	//Adds a player into the game
{
	playerorder.insert(playerorder.end(),player);
}
void Game::CreatePlayer()	//Creates the player and adds them to the game
{
	Player player1(1);
	AddPlayer(player1);
}
void Game::CreateBots(int bots)	//Creates the desired number of bots and adds them to the game
{
	switch (bots)
	{
	case 1:						//Creates 1 bot
		{
			Player bot1(playerorder.size() + 1);
			AddPlayer(bot1);
			break;
		}
	case 2:						//Creates 2 bots
		{
			Player bot1(playerorder.size() + 1);
			Player bot2(playerorder.size() + 2);
			AddPlayer(bot1);
			AddPlayer(bot2);
			break;
		}
	case 3:						//Creates 3 bots
		{
			Player bot1(playerorder.size() + 1);
			Player bot2(playerorder.size() + 2);
			Player bot3(playerorder.size() + 3);
			AddPlayer(bot1);
			AddPlayer(bot2);
			AddPlayer(bot3);
			break;
		}
	case 4:						//Creates 4 bots
		{
			Player bot1(playerorder.size() + 1);
			Player bot2(playerorder.size() + 2);
			Player bot3(playerorder.size() + 3);
			Player bot4(playerorder.size() + 4);
			AddPlayer(bot1);
			AddPlayer(bot2);
			AddPlayer(bot3);
			AddPlayer(bot4);
			break;
		}
	case 5:						//Creates 5 bots
		{
			Player bot1(playerorder.size() + 1);
			Player bot2(playerorder.size() + 2);
			Player bot3(playerorder.size() + 3);
			Player bot4(playerorder.size() + 4);
			Player bot5(playerorder.size() + 5);
			AddPlayer(bot1);
			AddPlayer(bot2);
			AddPlayer(bot3);
			AddPlayer(bot4);
			AddPlayer(bot5);
			break;
		}
	case 6:						//Creates 6 bots
		{
			Player bot1(playerorder.size() + 1);
			Player bot2(playerorder.size() + 2);
			Player bot3(playerorder.size() + 3);
			Player bot4(playerorder.size() + 4);
			Player bot5(playerorder.size() + 5);
			Player bot6(playerorder.size() + 6);
			AddPlayer(bot1);
			AddPlayer(bot2);
			AddPlayer(bot3);
			AddPlayer(bot4);
			AddPlayer(bot5);
			AddPlayer(bot6);
			break;
		}
	case 7:						//Creates 7 bots
		{
			Player bot1(playerorder.size() + 1);
			Player bot2(playerorder.size() + 2);
			Player bot3(playerorder.size() + 3);
			Player bot4(playerorder.size() + 4);
			Player bot5(playerorder.size() + 5);
			Player bot6(playerorder.size() + 6);
			Player bot7(playerorder.size() + 7);
			AddPlayer(bot1);
			AddPlayer(bot2);
			AddPlayer(bot3);
			AddPlayer(bot4);
			AddPlayer(bot5);
			AddPlayer(bot6);
			AddPlayer(bot7);
			break;
		}
	case 8:						//Creates 8 bots
		{
			Player bot1(playerorder.size() + 1);
			Player bot2(playerorder.size() + 2);
			Player bot3(playerorder.size() + 3);
			Player bot4(playerorder.size() + 4);
			Player bot5(playerorder.size() + 5);
			Player bot6(playerorder.size() + 6);
			Player bot7(playerorder.size() + 7);
			Player bot8(playerorder.size() + 8);
			AddPlayer(bot1);
			AddPlayer(bot2);
			AddPlayer(bot3);
			AddPlayer(bot4);
			AddPlayer(bot5);
			AddPlayer(bot6);
			AddPlayer(bot7);
			AddPlayer(bot8);
			break;
		}
	case 9:						//Creates 9 bots
		{
			Player bot1(playerorder.size() + 1);
			Player bot2(playerorder.size() + 2);
			Player bot3(playerorder.size() + 3);
			Player bot4(playerorder.size() + 4);
			Player bot5(playerorder.size() + 5);
			Player bot6(playerorder.size() + 6);
			Player bot7(playerorder.size() + 7);
			Player bot8(playerorder.size() + 8);
			Player bot9(playerorder.size() + 9);
			AddPlayer(bot1);
			AddPlayer(bot2);
			AddPlayer(bot3);
			AddPlayer(bot4);
			AddPlayer(bot5);
			AddPlayer(bot6);
			AddPlayer(bot7);
			AddPlayer(bot8);
			AddPlayer(bot9);
			break;
		}
	default:
		{
			cout << "Invalid Number of Bots" << endl;
			break;
		}
	}
}
void Game::GenerateDeck()														//https://stackoverflow.com/questions/234388/generating-a-deck-of-cards
{
	char suit[5] = { 'H','D','C','S' };											//Array of suits
	char value[14] = { 'A', '2','3','4','5','6','7','8','9','T','J','Q','K' };	//Array of card values
	
	for (int i = 0; i < 4; i++)													//Loops assigning a suit to each value
	{
		for (int j = 0; j < 13; j++)											//Loops the values
		{
			Card temp(value[j], suit[i]);										//Creates 52 different cards

			deck.push_back(temp);												//Adds the cards to the deck vector
		}
	}
}
void Game::ShuffleDeck()
{
	for (int i = 0; i < deck.size(); i++)	//Loops through the whole deck
	{
		Card swap;
		int shuffle = deck.size() - 1;
		int d = rand() % shuffle;			//Chooses random number 

		swap = deck[i];						//Swaps the first card with a random card in the deck (shuffles the deck)
		deck[i] = deck[d];
		deck[d] = swap;
	}
}
void Game::DisplayDecks()
{
	cout << "Deck: " << endl;
	for (int i = 0; i < deck.size(); i++)			//Loops listing all the cards in the main deck
	{
		cout << "[Card " << i + 1 << "]: " << deck[i].GetValue() << deck[i].GetSuit() << endl;
	}
	if (deck.size() == 0)
	{
		cout << "\tNo Cards" << endl;
	}
	
	cout << "Stock Pile: " << endl;
	for (int i = 0; i < stockpile.size(); i++)		//Loops listing all the cards in the stock pile
	{
		cout << "[Card " << i + 1 << "]: " << stockpile[i].GetValue() << stockpile[i].GetSuit() << endl;
	}
	if (stockpile.size() == 0)
	{
		cout << "\tNo Cards" << endl;
	}

	cout << "Discard Pile: " << endl;
	for (int i = 0; i < discardpile.size(); i++)	//Loops listing all the cards in the discard pile
	{
		cout << "[Card " << i + 1 << "]: " << discardpile[i].GetValue() << discardpile[i].GetSuit() << endl;
	}
	if (discardpile.size() == 0)
	{
		cout << "\tNo Cards" << endl;
	}

	cout << "Player Decks: " << endl;
	for (int i = 0; i < playerorder.size(); i++)	//Loops listing the cards in each players hand
	{
		playerorder[i].ListHand();
	}
	if (playerorder.size() == 0)
	{
		cout << "\tNo Players" << endl;
	}
}
void Game::Deal()
{
	for (int i = 0; i < playerorder.size(); i++)		//Cycles through the players
	{
		int l = deck.size() - 6;						//Ensures the correct number of cards are dealt (5 per player)
		for (int k = deck.size() - 1; k > l; k--)
		{
			Card deal = deck[k];
			playerorder[i].AddCard(deal);				//Adds card to players hand
			deck.pop_back();							//Removes card from deck
		}
	}
	deck.swap(stockpile);								//Transfers remaining cards in deck to stockpile
	
	int topcard = stockpile.size()-1;					//Top card of the stockpile
	Card firstcard = stockpile[topcard];

	if (firstcard.GetValue() == '8')					//If the top card is an eight another card must be chosen
	{
		for (int i = 0; i < stockpile.size(); i++)		//Loops through the whole deck
		{
			Card swap;
			int shuffle = stockpile.size() - 1;
			int d = rand() % shuffle;					//Chooses random number 

			swap = stockpile[i];						//Swaps the first card with a random card in the deck (shuffles the deck)
			stockpile[i] = stockpile[d];
			stockpile[d] = swap;
		}

		int topcard = stockpile.size() - 1;				//Repeats picking the top card
		Card anothercard = stockpile[topcard];
		discardpile.push_back(anothercard);
		stockpile.pop_back();							//Card removed from stockpile
	}
	else
	{
		discardpile.push_back(firstcard);				//Top card 'turned over' to start game
		stockpile.pop_back();
	}
}

bool Game::PutDownCard(Player &player, Card card)
{
	char topvalue = discardpile.back().GetValue();								//Value of the top card of the discard pile
	char topsuit = discardpile.back().GetSuit();								//Suit of the top card of the discard pile

	char checkvalue = card.GetValue();											//Value of the card to be put down
	char checksuit = card.GetSuit();											//Suit of the card to be put down


	if (checkvalue == topvalue || checksuit == topsuit || checkvalue == '8')	//Card being played must have the same suit, value or be an eight
	{
		player.GetSameRank(card);												//Puts all the cards with the same rank in a vector within the player class

		if (player.RemoveCard(card) == true)									//Checks if the player has the card
		{					
			for (int i = 0; i < player.sameranks.size(); i++)
			{
				Card cardrank = player.sameranks[i];
				
				discardpile.push_back(cardrank);								//Adds all cards with the same rank to discard pile
				player.RemoveCard(cardrank);									//Remove cards from player's hand
			}							

			cout << "[Player " << playerorder[playercounter].GetID() << "] (you): ";
			cout << discardpile.back().GetValue() << discardpile.back().GetSuit() << endl;
			playerorder[playercounter].sameranks.clear();						//Empty vector containing the same ranks
			playerorder[playercounter].playablecards.clear();					//Empty vector containing playable cards

			if (checkvalue == 'A')												//If the card is an ace, the next player is skipped
			{
				SkipPlayer();
			}
			else if (checkvalue == '2')											//If the card is a two, the next player picks up 2 cards
			{
				PickUpTwo();
			}
			else if (checkvalue == '8')											//If the card is an eight, the suit changes
			{
				ChangeSuit();
			}
			else if (checkvalue == 'J')											//If the card is a jack, the order is reversed
			{
				ReverseOrder();
			}
			return true;														//Card can be played
		}
		else
		{
			cout << "Error: Card not in hand" << endl;
			return false;
		}
	}
	else																		//Card cannot be played
	{
		cout << "Error: Illegal Card" << endl;
		cout << "Play a different card" << endl;
		return false;
	}
}
void Game::BotPutDownCard(Player &player, Card card)
{
	playerorder[playercounter].GetSameRank(card);								//Puts all the cards with the same rank in a vector within the player class

	if (playerorder[playercounter].RemoveCard(card) == true)					//Checks if the player has the card
	{
		for (int i = 0; i < playerorder[playercounter].sameranks.size(); i++)	//Cycles through same rank vector to remove all cards with the same rank
		{
			Card cardrank = playerorder[playercounter].sameranks[i];
			discardpile.push_back(cardrank);									//Adds all cards with the same rank to discard pile
			playerorder[playercounter].RemoveCard(cardrank);					//Remove cards from player's hand
		}
	}
	cout << "[Player " << playerorder[playercounter].GetID() << "]: ";
	cout << discardpile.back().GetValue() << discardpile.back().GetSuit() << endl;
	playerorder[playercounter].sameranks.clear();								//Empty vector containing the same ranks
	playerorder[playercounter].playablecards.clear();							//Empty vector containing playable cards

	if (card.GetValue() == 'A')												//If the card is an ace, the next player is skipped
	{
		SkipPlayer();
	}
	else if (card.GetValue() == '2')										//If the card is a two, the next player picks up 2 cards
	{
		PickUpTwo();
	}
	else if (card.GetValue() == 'J')										//If the card is a jack, the order is reversed
	{
		ReverseOrder();
	}																		//If bot plays an eight they don't change the suit
}
bool Game::PickUpCard(Player &player)
{
	if (stockpile.size() > 0)																	//If there are cards able to be picked up from the stock pile
	{
		Card pickup = stockpile.back();
		player.AddCard(pickup);																	//Top card added to player's hand
		stockpile.pop_back();																	//Remove card from stockpile
		
		if (player.GetID() == 1)
		{
			cout << pickup.GetValue() << pickup.GetSuit() << " picked up" << endl;
		}
	
		char topvalue = discardpile.back().GetValue();											//Value of the top card of the discard pile
		char topsuit = discardpile.back().GetSuit();											//Suit of the top card of the discard pile

		char checkvalue = pickup.GetValue();													//Value of the card to be put down
		char checksuit = pickup.GetSuit();														//Suit of the card to be put down


		if (checkvalue == topvalue || checksuit == topsuit || checkvalue == '8')				//Card being played must have the same suit, value or be an eight
		{
			if (player.GetID() == 1)
			{
				PutDownCard(player, pickup);
			}
			else
			{
				Card discardcard = discardpile.back();											//Top card of discard pile

				if (playerorder[playercounter].GetPlayableCards(discardcard) == true)			//If there are playable cards
				{
					Card playcard = playerorder[playercounter].playablecards.back();
					BotPutDownCard(playerorder[playercounter], playcard);
				}
			}
			return true;
		}
		else
		{
			return false;																		//Player continues picking up cards until they can play or there are no cards left in the stock pile	
		}
	}
	else
	{
		discardpile.swap(stockpile);															//Transfers cards from discard pile back into the stockpile

		for (int i = 0; i < stockpile.size(); i++)												//Shuffles the stockpile
		{
			Card swap;
			int shuffle = stockpile.size() - 1;
			int d = rand() % shuffle;															//Chooses random number 

			swap = stockpile[i];																//Swaps the first card with a random card in the deck (shuffles the deck)
			stockpile[i] = stockpile[d];
			stockpile[d] = swap;
		}	
		int topcard = stockpile.size() - 1;														//Top card of the stockpile
		Card firstcard = stockpile[topcard];
		discardpile.push_back(firstcard);														//Top card 'turned over' to start game
		stockpile.pop_back();
		return false;
	}
}

void Game::SkipPlayer()
{
	EndTurn();	//Next player doesn't get a turn
	cout << "[Player " << playerorder[playercounter].GetID() << "]" << " skipped" << endl;
}
void Game::PickUpTwo()
{
	for (int i = 0; i < 2; i++)														//Player forced to pick up two cards
	{
		if (stockpile.size() > 0)													//If there are cards able to be picked up from the stock pile
		{
			if (playercounter + 1 > playerorder.size() - 1)
			{
				Card pickup = stockpile.back();
				playerorder[0].AddCard(pickup);										//Top card added to player's hand
				stockpile.pop_back();												//Remove card from stockpile

				if (playerorder[0].GetID() == 1)									//If the player that has to pick up is not a bot, it tells them the cards they pick up
				{
					cout << pickup.GetValue() << pickup.GetSuit() << " picked up" << endl;;
				}
				else																//If the player is a bot
				{
					cout << "[Player " << playerorder[0].GetID() << "]" << " forced to pick up two cards" << endl;
				}
			}
			else
			{
				Card pickup = stockpile.back();
				playerorder[playercounter + 1].AddCard(pickup);						//Top card added to player's hand
				stockpile.pop_back();												//Remove card from stockpile
				
				if (playerorder[playercounter + 1].GetID() == 1)					//If the player that has to pick up is not a bot, it tells them the cards they pick up
				{
					cout << pickup.GetValue() << pickup.GetSuit() << " picked up" << endl;;
				}
				else																//If the player is a bot
				{
					cout << "[Player " << playerorder[playercounter + 1].GetID() << "]" << " forced to pick up two cards" << endl;
				}
			}
		}
		else
		{
			discardpile.swap(stockpile);											//Transfers cards from discard pile back into the stockpile

			for (int i = 0; i < stockpile.size(); i++)								//Shuffles the stockpile
			{
				Card swap;
				int shuffle = stockpile.size() - 1;
				int d = rand() % shuffle;											//Chooses random number 

				swap = stockpile[i];												//Swaps the first card with a random card in the deck (shuffles the deck)
				stockpile[i] = stockpile[d];
				stockpile[d] = swap;
			}
			int topcard = stockpile.size() - 1;										//Top card of the stockpile
			Card firstcard = stockpile[topcard];
			discardpile.push_back(firstcard);										//Top card 'turned over' to start game
			stockpile.pop_back();
			
			i--;																	//Player will pick up another card 
		}
	}
}
void Game::ChangeSuit()
{
	char suit;
	cout << "Pick a Suit (H/D/C/S)" << endl;				//Player picks the next suit
	cin >> suit;

	char currentvalue = discardpile.back().GetValue();		//Retains the current value of the card

	Card newsuit(currentvalue, suit);						//Suit changed

	discardpile.back() = newsuit;
}
void Game::ReverseOrder()
{
	cout << endl;
	cout << "Reverse Order" << endl;
	
	switch (playerorder.size())								//Changes playercounter so that the order is correct once vector is reversed
	{
		case 2:												//1 Bot
		{
			switch (playercounter)
			{
				case 0: playercounter = 1;
						break;
				case 1: playercounter = 0;
						break;	
			}
			break;
		}
		case 3:												//2 Bots
		{
			switch (playercounter)							
			{
				case 0: playercounter = 2;
						break;
				case 1: playercounter = 1;
						break;	
				case 2: playercounter = 0;
						break;
			}
			break;
		}
		case 4:												//3 Bots
		{
			switch (playercounter)
			{
				case 0: playercounter = 3;
						break;
				case 1: playercounter = 2;
						break;
				case 2: playercounter = 1;
						break;
				case 3: playercounter = 0;
						break;
			}
			break;
		}
		case 5:												//4 Bots
		{
			switch (playercounter)
			{
				case 0: playercounter = 4;
						break;
				case 1: playercounter = 3;
						break;
				case 2: playercounter = 2;
						break;
				case 3: playercounter = 1;
						break;
				case 4: playercounter = 0;
						break;
			}
			break;
		}
		case 6:												//5 Bots
		{
			switch (playercounter)							
			{
				case 0: playercounter = 5;
						break;
				case 1: playercounter = 4;
						break;
				case 2: playercounter = 3;
						break;
				case 3: playercounter = 2;
						break;
				case 4: playercounter = 1;
						break;
				case 5: playercounter = 0;
						break;
			}
			break;
		}
		case 7:												//6 Bots
		{
			switch (playercounter)							
			{
				case 0: playercounter = 6;
						break;
				case 1: playercounter = 5;
						break;
				case 2: playercounter = 4;
						break;
				case 3: playercounter = 3;
						break;
				case 4: playercounter = 2;
						break;
				case 5: playercounter = 1;
						break;
				case 6: playercounter = 0;
						break;
			}
			break;
		}
		case 8:												//7 Bots 
		{
			switch (playercounter)						
			{
				case 0: playercounter = 7;
						break;
				case 1: playercounter = 6;
						break;
				case 2: playercounter = 5;
						break;
				case 3: playercounter = 4;
						break;
				case 4: playercounter = 3;
						break;
				case 5: playercounter = 2;
						break;
				case 6: playercounter = 1;
						break;
				case 7: playercounter = 0;
						break;
			}
			break;
		}
		case 9:												//8 Bots
		{
			switch (playercounter)
			{
				case 0: playercounter = 8;
						break;
				case 1: playercounter = 7;
						break;
				case 2: playercounter = 6;
						break;
				case 3: playercounter = 5;
						break;
				case 4: playercounter = 4;
						break;
				case 5: playercounter = 3;
						break;
				case 6: playercounter = 2;
						break;
				case 7: playercounter = 1;
						break;
				case 8: playercounter = 0;
						break;
			}
			break;
		}
		case 10:											//9 Bots
		{
			switch (playercounter)			 
			{
				case 0: playercounter = 9;
						break;
				case 1: playercounter = 8;
						break;
				case 2: playercounter = 7;
						break;
				case 3: playercounter = 6;
						break;
				case 4: playercounter = 5;
						break;
				case 5: playercounter = 4;
						break;
				case 6: playercounter = 3;
						break;
				case 7: playercounter = 2;
						break;
				case 8: playercounter = 1;
						break;
				case 9: playercounter = 0;
						break;
			}
			break;
		}
	}
	reverse(playerorder.begin(), playerorder.end());		//Reverses playerorder vector (http://www.cplusplus.com/reference/algorithm/reverse/)
}

void Game::SimulateGame()
{
	//DisplayDecks();
	do
	{
		if (playerorder[playercounter].GetID() == 1)
		{	
			cout << "Discard Pile: " << endl;													//Displays top card so player knows what to play
			cout << " \t [Top Card]: " << discardpile.back().GetValue() << discardpile.back().GetSuit() << endl;

			Card discardcard = discardpile.back();												//Top card of discard pile

			if (playerorder[playercounter].GetPlayableCards(discardcard) == true)				//If there are playable cards
			{
				char answer;
				cout << "Do you want to sort your hand? (y/n)" << endl;
				cin >> answer;

				if (answer == 'y' || answer == 'Y')
				{
					playerorder[playercounter].SortHand();										//Sorts player's hand
				}
				
				playerorder[playercounter].ListHand();											//List player's hand
				
				char cardvalue, cardsuit;

				cout << "Which card would you like to put down" << endl;
				cin >> cardvalue >> cardsuit;

				Card card(cardvalue, cardsuit);

				while (PutDownCard(playerorder[playercounter], card) == false)					//If card cannot be played try again
				{
					playerorder[playercounter].ListHand();

					char cardvalue, cardsuit;

					cout << "Which card would you like to put down" << endl;
					cin >> cardvalue >> cardsuit;

					Card card2(cardvalue, cardsuit);

					if (PutDownCard(playerorder[playercounter], card2) == true)					//If card can be played, break
					{
						break;
					}
				}
			}
			else
			{
				do
				{
					cout << "Pick Up a Card" << endl;											//If card cannot be played, pick up
				} while (PickUpCard(playerorder[playercounter]) == false);
			}
			EndTurn();																			//End player's turn
		}
		else																					//Player is a bot
		{
			while (playerorder[playercounter].GetID() != 1)										//Cycles through the bots
			{
				Card discardcard = discardpile.back();											//Top card of discard pile

				if (playerorder[playercounter].GetPlayableCards(discardcard) == true)			//If there are playable cards
				{
					Card playcard = playerorder[playercounter].playablecards.back();			//Highest value playable card is played
					BotPutDownCard(playerorder[playercounter], playcard);
				}
				else
				{
					do
					{
						cout << "[Player " << playerorder[playercounter].GetID() << "]" << " picked up" << endl;
					} while (PickUpCard(playerorder[playercounter]) == false);					//If there are no playable cards, pick up
				}
				EndTurn();																		//End of player's turn
			}
		}
	} while (CheckEndGame() == false);
	ListPlayersScores();																		//List score table
}

void Game::EndTurn()
{
	playercounter++;									//Goes to the next player

	if (playercounter > playerorder.size() - 1)			//Resets playercounter when all players have had a turn (goes back to first player)
	{
		playercounter = 0;
	}
}
bool Game::CheckEndGame()
{
	for (int i = 0; i < playerorder.size(); i++)													//Checks each player
	{
		if (playerorder[i].GetNumberofCards() == 0)													//If a player has no cards remaining
		{
			playercounter = 0;																		//Counter reset for new game
			return true;
		}
		else
		{
			return false;
		}
	}
}
void Game::ListPlayersScores()
{
	for (int i = 0; i < playerorder.size(); i++)	//Sorts players by increasing scores
	{
		int c, d;
		int n = playerorder.size();
		Player swap;

		for (c = 0; c < (n - 1); c++)				//Sort player's scores using basic bubble sort
		{
			for (d = 0; d < n - c - 1; d++)
			{
				if (playerorder[d].ScoreHand() > playerorder[d + 1].ScoreHand())
				{
					swap = playerorder[d];
					playerorder[d] = playerorder[d + 1];
					playerorder[d + 1] = swap;
				}
			}
		}
	}
	cout << endl;
	cout << "Player Rankings:" << endl;
	for (int i = 0; i < playerorder.size(); i++)	//Loops listing all the players and their scores
	{
		if (playerorder[i].GetNumberofCards() == 0)
		{
			cout << "WINNER: [Player " << playerorder[i].GetID() << "]" << ": " << playerorder[i].ScoreHand() << endl;
		}
		else
		{
			cout << i + 1 << ". [Player " << playerorder[i].GetID() << "]" << ": " << playerorder[i].ScoreHand() << endl;
		}
	}
}
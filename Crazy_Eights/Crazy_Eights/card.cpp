#include <iostream>
#include <cstdlib>
#include <cctype>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>

#include "card.h"

using namespace std;

Card::Card()
{
	value = 'z';	//Invalid value
	suit = 'z';		//Invalid suit
}
Card::Card(char value, char suit)
{
	this->value = value;
	this->suit = suit;
}

char Card::GetValue()
{
	return value;
}
char Card::GetSuit()
{
	return suit;
}

int Card::ConvertValue()
{
	int returnvalue;

	if (value == 'A')				//If value of card is an ace
	{
		returnvalue = 1;

		return returnvalue;
	}
	else if (value == '8')
	{
		returnvalue = 50;			//Eights are worth 50 points

		return returnvalue;
	}
	else if (value == 'T')			//If value of card is 10
	{
		returnvalue = 10;

		return returnvalue;
	}
	else if (value == 'J')			//If value of card is a jack
	{
		returnvalue = 11;

		return returnvalue;
	}
	else if (value == 'Q')			//If value of card is a queen
	{
		returnvalue = 12;

		return returnvalue;
	}
	else if (value == 'K')			//If value of card is a king
	{
		returnvalue = 13;

		return returnvalue;
	}
	else							//If value of card is anything else
	{
		returnvalue = value - 48;	//ASCII code values for number characters are 48 characters ahead of the numbers 

		return returnvalue;
	}
}
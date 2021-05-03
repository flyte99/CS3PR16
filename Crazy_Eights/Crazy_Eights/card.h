#pragma once
#include <iostream>
#include <cstdlib>
#include <cctype>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>

#ifndef CARD_H
#define CARD_H

class Card
{
public:
	Card();							//Default Constructor
	Card(char value, char suit);	//Constructor

	char GetValue();
	char GetSuit();

	int ConvertValue();

protected:
	char suit;
	char value;
};

#endif
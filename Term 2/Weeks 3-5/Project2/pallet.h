#pragma once
#ifndef PALLET_H
#define PALLET_H

#include <iostream>
#include <string>
#include <vector>

class Pallet
{
public:
	Pallet(); //Default Constructor
	Pallet(int id, int maxWeight); //Constructor

	bool AddItem(std::string item);
	void RemoveTopItem();

	std::string GetItemAtPosition(int position);

	void ListAllItems();

	int GetCurrentWeight();
	int GetMaxWeight();

	int GetID();

protected:
	std::vector<std::string> palletContents;
	int id;
	int maxWeight;
};

#endif


#ifndef PALLET_H
#define PALLET_H

#include <vector>
#include <string>
#include <iostream>

class Pallet
{
public:
	Pallet(int id, int maxWeight);
	
	void AddItem(std::string item);
	void RemoveTopItem(std::string item);
	
	std::string GetItemAtPosition(int position);
	
	void ListAllItems();
	
	int GetCurrentWeight();
	int GetMaxWeight();

protected:
	std::vector<std::string> contents;

private:
	int pallet_id;
	int pallet_maxWeight;
};

#endif


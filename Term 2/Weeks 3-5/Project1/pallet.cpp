#include "pallet.h"
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

Pallet::Pallet(int id, int maxWeight)
{
	pallet_id = id;
	pallet_maxWeight = maxWeight;
}
void Pallet::AddItem(string item)
{
	if (contents.size() < pallet_maxWeight)
	{
		contents.push_back(item);

		cout << "Add Item: TRUE" << endl;
	}
	else
	{
		cout << "Error: Max Weight Reached" << endl;
		cout << "Add Item: FALSE" << endl;
	}
}
void Pallet::RemoveTopItem(string item)
{
	contents.pop_back();
}
string Pallet::GetItemAtPosition(int position)
{		
	if (position > contents.size())
	{
		cout << "Error: No Item at this Position" << endl;
	}
	else
	{
		return contents[position];
	}
}
void Pallet::ListAllItems()
{
	for (int i = 0; i < contents.size(); i++)
	{
		std::cout << contents[i] << endl;
	}

	if (contents.size() == 0)
	{
		cout << "Contents: EMPTY" << endl;
	}
}
int Pallet::GetCurrentWeight()
{
	return contents.size();
}
int Pallet::GetMaxWeight()
{
	return pallet_maxWeight;
}
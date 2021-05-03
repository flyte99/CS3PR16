#include "pallet.h"
#include "cargostorage.h"
#include "simpletruck.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

CargoStorage::CargoStorage()
{
}
bool CargoStorage::AddPalletAtPosition(int position, Pallet Pallet)
{
	if (!storage.empty()) /*Will only add a pallet if the position is empty*/
	{
		storage.insert(storage.begin() + position, Pallet);
		cout << "\tTRUE" << endl;
		return true;
	}
	else
	{
		cout << "Error: Pallet already in this position" << endl;
		cout << "\tFALSE" << endl;
		return false;
	}
}
Pallet CargoStorage::RetrievePalletFromPosition(int position)
{
	if (storage.empty()) /*Checks to see whether there is a pallet at this position*/
	{
		cout << ("Error: No Pallet at this Position") << endl;
	}
	else
	{
		return storage[position];
		storage.erase(storage.begin() + position);
	}
}
void CargoStorage::ListContents()
{
	for (int j = 0; j < storage.size(); j++)
	{
		if (!storage.empty())
		{
			storage[j].ListAllItems();
		}
		else
		{
			cout << "Storage: Empty" << endl;
		}
	}
}

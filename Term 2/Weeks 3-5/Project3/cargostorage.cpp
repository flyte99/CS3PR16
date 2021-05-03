#include "pallet.h"
#include "cargostorage.h"
#include "simpletruck.h"
#include "palletgenerator.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

CargoStorage::CargoStorage()
{
	slotFull.resize(10, false);

	Pallet invalidPallet(-1, -1);

	storage.resize(10, invalidPallet);
}
bool CargoStorage::AddPalletAtPosition(int position, Pallet pallet)
{
	if (position >= 0 && position <= 9)
	{
		if (slotFull[position] == false)
		{
			// Everything is ok, add the pallet
			storage[position] = pallet;

			// Now this slot is full
			slotFull[position] = true;
			//cout<< slotFull[position]<<endl;
			return true;
		}
		else
		{
			cout << "Error: Position Full" << endl;
		}

		cout << "Error: Cargo Storage Full" << endl;
		return false;
	}
}
Pallet CargoStorage::RetrievePalletFromPosition(int position)
{
	Pallet palletToReturn(-1, -1);

	if (position >= 0 && position <= 9)
	{
		// slot is full: slotFull is true
		if (slotFull[position] == true)
		{
			// Copy the pallet we want into palletToReturn
			palletToReturn = storage[position];

			// Replace the original with an invalid pallet
			// (not strictly needed if I always check slotFull before doing anything to contents,
			// but it makes it easier to spot errors if I make a mistake later)
			storage[position] = Pallet(-1, -1);

			// Now this slot is empty
			slotFull[position] = false;
		}
		else
		{
			cout << "Error: No pallet in this position" << endl;
		}
	}
	return palletToReturn;
}
void CargoStorage::ListContents()
{
	for (int i = 0; i < 10; i++)
	{
		// i+1 because humans count 1 to 10, not 0 to 9
		cout << "[Slot " << i + 1 << "]" << endl;
		// See if there is a pallet there or not:
		if (slotFull[i] == true)
		{
			// This slot is full == there is something here
			// Pallets can take care of listing their own contents
			storage[i].ListAllItems();
		}
		else
		{
			// Nothing here: slot is free
			cout << "[FREE]" << endl;
		}

		// spotted in testing: I need an extra newline to format everything right
		cout << endl;
	}
}

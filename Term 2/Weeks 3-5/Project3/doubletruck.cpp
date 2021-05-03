#include "pallet.h"
#include "cargostorage.h"
#include "simpletruck.h"
#include "loadingbay.h"
#include "doubletruck.h"
#include "palletgenerator.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

DoubleTruck::DoubleTruck(){}
bool DoubleTruck::PickUpItem(int position, CargoStorage &storage)
{
	if (forklift1.GetMaxWeight() != -1) // if forklift1 is full then add to forklift2
	{
		if (forklift2.GetMaxWeight() != -1) //if forklift2 is also full then return false
		{
			return false;
		}
		else //adds to forklift2
		{
			Pallet p = storage.RetrievePalletFromPosition(position);

			if (p.GetMaxWeight() == -1)
			{
				return false;
			}
			else
			{
				forklift2 = p;

				return true;
			}
		}
	}
	else //if forklift1 is empty then add pallet to it
	{
		Pallet p = storage.RetrievePalletFromPosition(position);

		if (p.GetMaxWeight() == -1)
		{
			return false;
		}
		else
		{
			forklift1 = p;

			return true;
		}
	}
}

bool DoubleTruck::PutDownItem(int position, CargoStorage &storage)
{
	if (forklift1.GetMaxWeight() == -1) // if forklift1 is empty then move on
	{
		if (forklift2.GetMaxWeight() == -1) // if forklift2 is also empty then return false
		{
			return false;
		}
		
		bool status = storage.AddPalletAtPosition(position, forklift2); // put down item from forklift2
		if (status == true)
		{
			forklift2 = Pallet(-1, -1);
			return true;
		}
		return false;
	}

	bool status = storage.AddPalletAtPosition(position, forklift1); // put down item from forklift1

	if (status == true)
	{
		forklift1 = Pallet(-1, -1);
		return true;
	}

	return false;
}

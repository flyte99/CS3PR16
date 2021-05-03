#include "pallet.h"
#include "cargostorage.h"
#include "simpletruck.h"
#include "palletgenerator.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

SimpleTruck::SimpleTruck() : forklift(-1, -1) {}
bool SimpleTruck::PickUpItem(int position, CargoStorage &storage)
{
	if (forklift.GetMaxWeight() != -1) // Weight or ID of -1 means "not valid"
	{
		return false;
	}

	Pallet p = storage.RetrievePalletFromPosition(position);

	if (p.GetMaxWeight() == -1)
	{
		return false;
	}
	else
	{
		// Update our internal item
		forklift = p;

		return true;
	}
}
bool SimpleTruck::PutDownItem(int position, CargoStorage &storage)
{
	if (forklift.GetMaxWeight() == -1)
	{
		// no item
		return false;
	}

	// Try and put it down, and listen to whether or not storage is happy with us
	bool status = storage.AddPalletAtPosition(position, forklift);

	if (status == true)
	{
		forklift = Pallet(-1, -1);
		return true;
	}

	// We only get here if status was false
	// i.e. the CargoStorage unit rejected the request to add the item
	// Therefore, we have failed to put down the item, and should return an appropriate status
	return false;
}

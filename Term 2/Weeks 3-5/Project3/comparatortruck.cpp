#include "pallet.h"
#include "cargostorage.h"
#include "simpletruck.h"
#include "loadingbay.h"
#include "doubletruck.h"
#include "comparatortruck.h"
#include "palletgenerator.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

ComparatorTruck::ComparatorTruck() {}
bool ComparatorTruck::PutDownItem(int position, CargoStorage &storage)
{
	if (forklift1.GetCurrentWeight() > forklift2.GetCurrentWeight())
	{
		bool status1 = storage.AddPalletAtPosition(position, forklift1); // put down item from forklift1 first
		if (status1 == true)
		{
			forklift1 = Pallet(-1, -1);
			return true;
		}
		return false;

		if (forklift2.GetMaxWeight() == -1) // if forklift2 is empty then return false
		{
			return false;
		}

		bool status2 = storage.AddPalletAtPosition(position, forklift2); // put down item from forklift2 after forklift1
		if (status2 == true)
		{
			forklift2 = Pallet(-1, -1);
			return true;
		}
		return false;
	}
	else if (forklift1.GetCurrentWeight() < forklift2.GetCurrentWeight())
	{
		bool status2 = storage.AddPalletAtPosition(position, forklift2); // put down item from forklift2 first
		if (status2 == true)
		{
			forklift2 = Pallet(-1, -1);
			return true;
		}
		return false;

		if (forklift1.GetMaxWeight() == -1) // if forklift1 is empty then return false
		{
			return false;
		}

		bool status1 = storage.AddPalletAtPosition(position, forklift1); // put down item from forklift1 after forklift2
		if (status1 == true)
		{
			forklift1 = Pallet(-1, -1);
			return true;
		}
		return false;
	}
	else
	{
		PutDownItem(position, storage);
		return  true;
	}
}
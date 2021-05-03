#include "pallet.h"
#include "cargostorage.h"
#include "simpletruck.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

SimpleTruck::SimpleTruck() {}
bool SimpleTruck::PickUpItem(int position, CargoStorage &storage)
{
	Pallet item = storage.RetrievePalletFromPosition(position);
	forklift=item;
	int forklift_Weight = forklift.GetCurrentWeight();
	if (forklift_Weight > 0)
	{
		return true;
		cout << "\tTRUE" << endl;
	}
	else
	{
		return false;
		cout << "\tFALSE" << endl;
	}
}
bool SimpleTruck::PutDownItem(int position, CargoStorage &storage) 
{
	storage.AddPalletAtPosition(position, forklift);

	int forklift_Weight = forklift.GetCurrentWeight();
	if (forklift_Weight == 0)
	{
		return true;
		cout << "\tTRUE" << endl;
	}
	else
	{
		return false;
		cout << "\tFALSE" << endl;
	}
}

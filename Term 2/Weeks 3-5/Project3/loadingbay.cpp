#include "pallet.h"
#include "cargostorage.h"
#include "simpletruck.h"
#include "loadingbay.h"
#include "palletgenerator.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

LoadingBay::LoadingBay(){}
void LoadingBay::Arrive()
{
	for (int i = 0; i < storage.size(); i++)
	{
		Pallet p = GeneratePallet();
		AddPalletAtPosition(i, p);
		//cout << contents.AddPalletAtPosition(i, p) << endl;
	}
	//ListContents();
}
void LoadingBay::Leave()
{
	for (int i = 0; i < storage.size(); i++)
	{
		Pallet result = RetrievePalletFromPosition(i);
		cout << "Pallet " << result.GetID() << " retrieved" << endl;
	}
}
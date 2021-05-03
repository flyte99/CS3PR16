#include "pallet.h"
#include "cargostorage.h"
#include "simpletruck.h"
#include <iostream> /*C++ input and output stream*/
#include <string>
#include <vector>

using namespace std;

int main()
{
	// Create new pallet (expecting no output)
	cout << "Test 1.1: Create Pallet" << endl;
	Pallet p1(0, 10);
	cout << endl;

	// Expecting list of no items
	cout << "Test 1.2: Empty Listing" << endl;
	p1.ListAllItems();
	cout << endl;

	// Adding an item
	cout << "Test 1.3: Adding Item" << endl;
	p1.AddItem("Box of live scorpions");

	// Expect to see a list only containing box of live scorpions
	cout << "Test 1.4: List Item" << endl;
	p1.ListAllItems();
	cout << endl;

	// Adding multiple items
	cout << "Test 1.5: Adding Multiple Items" << endl;
	p1.AddItem("Box of live crickets");
	p1.AddItem("Box of live mice");
	cout << endl;

	// Expect to see a list containing boxes of live scorpions, crickets and mice
	cout << "Test 1.6: List Items" << endl;
	p1.ListAllItems();
	cout << endl;

	// Removing an item (expecting no output)
	cout << "Test 1.7: Removing Top Item" << endl;
	p1.RemoveTopItem();
	cout << endl;

	// Expect to see a list not showing the item removed
	cout << "Test 1.8: List Items" << endl;
	p1.ListAllItems();
	cout << endl;

	// Create second pallet (expecting no output)
	cout << "Test 1.9: Create New Pallet" << endl;
	Pallet p2(1, 5);
	cout << endl;

	// Expecting list of no items
	cout << "Test 1.10: Empty Listing" << endl;
	p2.ListAllItems();
	cout << endl;

	// Expecting box of live crickets
	cout << "Test 1.11: Get Item At Position" << endl;
	cout << p1.GetItemAtPosition(1) << endl;
	cout << endl;

	//Expect to see that the list of items has not changed
	cout << "Test 1.12: List Items" << endl;
	p1.ListAllItems();
	cout << endl;

	// Expect to see the current weight of the pallet
	cout << "Test 1.13: Get Current Weight" << endl;
	cout << "Current Weight of pallet 1: " << p1.GetCurrentWeight() << " units" << endl;
	cout << "Current Weight of pallet 2: " << p2.GetCurrentWeight() << " units" << endl;
	cout << endl;

	// Expect to see the maximum weight of the pallet
	cout << "Test 1.14: Get Max Weight" << endl;
	cout << "Max Weight of pallet 1: " << p1.GetMaxWeight() << " units" << endl;
	cout << "Max Weight of pallet 2: " << p2.GetMaxWeight() << " units" << endl;
	cout << endl;

	//Expecting the program not to crash when there is no item in the position
	cout << "Test 1.15: Get Item at Position" << endl;
	cout << p1.GetItemAtPosition(4) << endl;
	cout << endl;

	//Expecting to see ID of pallet displayed
	cout << "Test 1.16: Get ID" << endl;
	cout << "Pallet ID: " << p1.GetID() << endl;
	cout << "Pallet ID: " << p2.GetID() << endl;
	cout << endl;

	//Create a cargo storage (expecting no output)
	cout << "Test 2.1: Create Cargo Storage" << endl;
	CargoStorage s;
	cout << endl;

	//Adding a pallet to a position
	cout << "Test 2.2: Add Pallet to Storage" << endl;
	s.AddPalletAtPosition(1, p1);
	cout << endl;

	//Expecting to see the added pallet in its position
	cout << "Test 2.3: Retrieve Pallet from Position" << endl;
	Pallet result = s.RetrievePalletFromPosition(1);
	cout << "Pallet " << result.GetID() << " retrieved" << endl;
	cout << endl;

	//Expecting to see no pallet in the previous postion (the pallet has been removed)
	cout << "Test 2.4: Check Pallet has been Retrieved" << endl;
	result = s.RetrievePalletFromPosition(1);
	cout << "Pallet " << result.GetID() << " retrieved" << endl;
	cout << endl;

	//Expecting to see a list of all pallets and their contents
	cout << "Test 2.5: List Pallets" << endl;
	s.ListContents();
	cout << endl;

	//Create simple truck
	cout << "Test 3.1: Create Simple Truck" << endl;
	SimpleTruck truck;
	cout << endl;

	//Picking up item
	cout << "Test 3.2: Pick Up Item" << endl;
	truck.PickUpItem(1, s);
	cout << endl;

	//Expecting to see no pallet in position 1
	cout << "Test 3.3: Check Pallet has been picked up" << endl;
	result = s.RetrievePalletFromPosition(1);
	cout << "Pallet " << result.GetID() << " picked up" << endl;
	cout << endl;

	//Putting down item
	cout << "Test 3.4: Put Down Item" << endl;
	truck.PutDownItem(2, s);
	cout << endl;

	//Expecting to see pallet from position 1 in position 2
	cout << "Test 3.5: Check Pallet has been put down" << endl;
	result = s.RetrievePalletFromPosition(2);
	cout << "Pallet " << result.GetID() << " put down" << endl;
	cout << endl;

	return 0;
}

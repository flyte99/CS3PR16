#include "pallet.h"
#include "cargostorage.h"
#include "simpletruck.h"
#include "loadingbay.h"
#include "doubletruck.h"
#include "comparatortruck.h"
#include "palletgenerator.h"
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

	// Create several pallets (expecting no output)
	cout << "Test 1.9: Create New Pallet" << endl;
	Pallet p2(1, 5);
	Pallet p3(2, 5);
	Pallet p4(3, 15);
	Pallet p5(4, 10);
	Pallet p6(5, 3);
	Pallet p7(6, 10);
	Pallet p8(7, 20);
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

	// Adding items to pallets
	cout << "Test 1.13: Adding Multiple Items to Multiple Pallets" << endl;
	p2.AddItem("Box of footballs");
	p2.AddItem("Box of hamsters");
	p2.AddItem("Box of pencils");
	p2.AddItem("Box of computers"); 
	
	p3.AddItem("Box of plants");
	
	p4.AddItem("Box of pens");
	p4.AddItem("Box of books");
	p4.AddItem("Box of monkeys");
	p4.AddItem("Box of woodlice");
	p4.AddItem("Box of lightbulbs");
	
	p5.AddItem("Box of tennis balls");
	p5.AddItem("Box of rackets");
	
	p6.AddItem("Box of burgers");
	p6.AddItem("Box of hot dogs");
	p6.AddItem("Box of sweets");
	
	p8.AddItem("Box of milk");
	p8.AddItem("Box of slime");

	// Expect to see the current weight of the pallets
	cout << "Test 1.14: Get Current Weight" << endl;
	cout << "Current Weight of pallet 0: " << p1.GetCurrentWeight() << " units" << endl;
	cout << "Current Weight of pallet 1: " << p2.GetCurrentWeight() << " units" << endl;
	cout << "Current Weight of pallet 2: " << p3.GetCurrentWeight() << " units" << endl;
	cout << "Current Weight of pallet 3: " << p4.GetCurrentWeight() << " units" << endl;
	cout << "Current Weight of pallet 4: " << p5.GetCurrentWeight() << " units" << endl;
	cout << "Current Weight of pallet 5: " << p6.GetCurrentWeight() << " units" << endl;
	cout << "Current Weight of pallet 6: " << p7.GetCurrentWeight() << " units" << endl;
	cout << "Current Weight of pallet 7: " << p8.GetCurrentWeight() << " units" << endl;
	cout << endl;

	// Expect to see the maximum weight of the pallet
	cout << "Test 1.15: Get Max Weight" << endl;
	cout << "Max Weight of pallet 0: " << p1.GetMaxWeight() << " units" << endl;
	cout << "Max Weight of pallet 1: " << p2.GetMaxWeight() << " units" << endl;
	cout << "Max Weight of pallet 2: " << p3.GetMaxWeight() << " units" << endl;
	cout << "Max Weight of pallet 3: " << p4.GetMaxWeight() << " units" << endl;
	cout << "Max Weight of pallet 4: " << p5.GetMaxWeight() << " units" << endl;
	cout << "Max Weight of pallet 5: " << p6.GetMaxWeight() << " units" << endl;
	cout << "Max Weight of pallet 6: " << p7.GetMaxWeight() << " units" << endl;
	cout << "Max Weight of pallet 7: " << p8.GetMaxWeight() << " units" << endl;

	cout << endl;

	//Expecting the program not to crash when there is no item in the position
	cout << "Test 1.16: Get Item at Position" << endl;
	cout << p1.GetItemAtPosition(4) << endl;
	cout << endl;

	//Expecting to see ID of pallets displayed
	cout << "Test 1.17: Get ID" << endl;
	cout << "Pallet ID: " << p1.GetID() << endl;
	cout << "Pallet ID: " << p2.GetID() << endl;
	cout << "Pallet ID: " << p3.GetID() << endl;
	cout << "Pallet ID: " << p4.GetID() << endl;
	cout << "Pallet ID: " << p5.GetID() << endl;
	cout << "Pallet ID: " << p6.GetID() << endl;
	cout << "Pallet ID: " << p7.GetID() << endl;
	cout << "Pallet ID: " << p8.GetID() << endl;
	cout << endl;

////////////////////////////////////////////////////////////////////////////////////////////////////////////

	//Create a cargo storage (expecting no output)
	cout << "Test 2.1: Create Cargo Storage" << endl;
	CargoStorage s;
	cout << endl;

	//Adding pallets to a position
	cout << "Test 2.2: Add Pallet to Storage" << endl;
	s.AddPalletAtPosition(0, p1);
	s.AddPalletAtPosition(1, p3);
	s.AddPalletAtPosition(2, p6);
	s.AddPalletAtPosition(3, p8);
	s.AddPalletAtPosition(4, p2);
	s.AddPalletAtPosition(5, p4);
	s.AddPalletAtPosition(6, p7);
	s.AddPalletAtPosition(7, p5);
	cout << endl;

	//Expecting to see the added pallets in their positions
	cout << "Test 2.3: Retrieve Pallet from Position" << endl;
	Pallet result = s.RetrievePalletFromPosition(1);
	cout << "Pallet " << result.GetID() << " retrieved" << endl;
	cout << endl;

	//Expecting to see no pallet in the previous postion (the pallet has been removed)
	cout << "Test 2.4: Check Pallet has been Retrieved" << endl;
	result = s.RetrievePalletFromPosition(1);
	cout << endl;

	//Expecting to see a list of all pallets and their contents
	cout << "Test 2.5: List Pallets" << endl;
	s.ListContents();
	cout << endl;

///////////////////////////////////////////////////////////////////////////////////////////////////////////

	//Create simple truck
	cout << "Test 3.1: Create Simple Truck" << endl;
	SimpleTruck st;
	cout << endl;

	//Picking up item
	cout << "Test 3.2: Pick Up Item" << endl;
	st.PickUpItem(0, s);
	cout << endl;

	//Expecting to see no pallet in position 4
	cout << "Test 3.3: Check Pallet has been picked up" << endl;
	s.ListContents();
	cout << endl;

	//Putting down item
	cout << "Test 3.4: Put Down Item" << endl;
	st.PutDownItem(1, s);
	cout << endl;

	//Expecting to see pallet from position 1 now in position 2
	cout << "Test 3.3: Check Pallet has been put down" << endl;
	s.ListContents();
	cout << endl;

////////////////////////////////////////////////////////////////////////////////////////////////////////////

	//Create a loading bay (expecting no output)
	cout << "Test 4.1: Create LoadingBay" << endl;
	LoadingBay bay;
	cout << endl;

	//Arriving at loading bay
	cout << "Test 4.2: Arrival at LoadingBay" << endl;
	bay.Arrive();
	cout << endl;
	
	//Expecting to see 10 random pallets
	cout << "Test 4.3: Check Pallets have Arrived at LoadingBay" << endl;
	bay.ListContents();
	cout << endl;

	//Leaving loading bay
	cout << "Test 4.4: Leave LoadingBay" << endl;
	bay.Leave();
	cout << endl;
	
	//Expecting to see pallets removed
	cout << "Test 4.5: Check Pallets have Left LoadingBay" << endl;
	bay.ListContents();
	cout << endl;

////////////////////////////////////////////////////////////////////////////////////////////////////////////

	//Create double truck
	cout << "Test 5.1: Create Simple Truck" << endl;
	DoubleTruck dt;
	cout << endl;

	//Picking up items
	cout << "Test 5.2: Pick Up Items" << endl;
	dt.PickUpItem(5, s);
	dt.PickUpItem(2, s);
	cout << endl;

	//Expecting to see no pallets in slots 6 and 3
	cout << "Test 5.3: Check Pallets have been picked up" << endl;
	s.ListContents();
	cout << endl;

	//Putting down items
	cout << "Test 5.4: Put Down Items" << endl;
	dt.PutDownItem(8, s);
	dt.PutDownItem(9, s);
	cout << endl;

	//Expecting to see pallets from slots 6 and 3 now in slots 9 and 10
	cout << "Test 5.3: Check Pallets have been put down" << endl;
	s.ListContents();
	cout << endl;

////////////////////////////////////////////////////////////////////////////////////////////////////////////

	//Create comparator truck
	cout << "Test 6.1: Create Comparator Truck" << endl;
	ComparatorTruck ct;
	cout << endl;

	//Picking up item
	cout << "Test 6.2: Pick Up Items" << endl;
	ct.PickUpItem(9, s);
	ct.PickUpItem(8, s);
	
	cout << endl;

	//Expecting to see no pallets in slots 9 and 10
	cout << "Test 6.3: Check Pallets have been picked up" << endl;
	s.ListContents();
	cout << endl;

	//Putting down items
	cout << "Test 6.4: Put Down Items" << endl;
	ct.PutDownItem(5, s);
	ct.PutDownItem(2, s);

	cout << endl;

	//Expecting to see pallet from slot 9 now in slot 6 and pallet from slot 10 now in slot 3 (reversed from order they were picked up)
	cout << "Test 6.3: Check Pallets have been put down" << endl;
	s.ListContents();
	cout << endl;


	return 0;
}

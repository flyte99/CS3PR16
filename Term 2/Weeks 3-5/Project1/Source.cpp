#include <iostream> /*C++ input and output stream*/
#include <string>
#include "pallet.h"
#include <vector>

using namespace std;

int main()
{
	// Create new pallet (expecting no output)
	cout << "Test 1: Create Pallet" << endl;
	Pallet p1(1, 100);

	// Expecting list of no items (expecting no output)
	cout << "Test 2: Empty Listing" << endl;
	p1.ListAllItems();

	// Adding an item (expecting no output)
	cout << "Test 3: Adding Item" << endl;
	p1.AddItem("Box of live scorpions");

	// Expect to see a list only containing box of live scorpions
	cout << "Test 4: List Item" << endl;
	p1.ListAllItems();

	// Adding multiple items (expecting no output)
	cout << "Test 5: Adding Multiple Items" << endl;
	p1.AddItem("Box of live crickets");
	p1.AddItem("Box of live mice"); 

	// Expect to see a list containing boxes of live scorpions, crickets and mice
	cout << "Test 6: List Items" << endl;
	p1.ListAllItems();

	// Removing an item (expecting no output)
	cout << "Test 7: Removing Top Item" << endl;
	p1.RemoveTopItem("Box of live mice");

	// Expect to see a list not showing the item removed
	cout << "Test 8: List Items" << endl;
	p1.ListAllItems();

	// Create second pallet (expecting no output)
	cout << "Test 9: Create New Pallet" << endl;
	Pallet p2(2, 50);

	// Expecting list of no items (expecting no output)
	cout << "Test 10: Empty Listing" << endl;
	p2.ListAllItems();

	// Expecting box of live crickets
	cout << "Test 11: Get Item At Position" << endl;
	cout << p1.GetItemAtPosition(1) << endl;

	//Expect to see that the list of items has not changed
	cout << "Test 12: List Items" << endl;
	p1.ListAllItems();

	// Expect to see the current weight of the pallet
	cout << "Test 13: Get Current Weight" << endl;
	cout << "Current Weight of pallet 1: " << p1.GetCurrentWeight() << " units" << endl;
	cout << "Current Weight of pallet 2: " << p2.GetCurrentWeight() << " units" << endl;

	// Expect to see the maximum weight of the pallet
	cout << "Test 14: Get Max Weight" << endl;
	cout << "Max Weight of pallet 1: " << p1.GetMaxWeight() << " units" << endl;
	cout << "Max Weight of pallet 2: " << p2.GetMaxWeight() << " units" << endl;

	//Expecting the program not to crash when there is no item in the position
	cout << "Test 15: Get Item at Position" << endl;
	cout << p1.GetItemAtPosition(4) << endl; 

	return 0;
}

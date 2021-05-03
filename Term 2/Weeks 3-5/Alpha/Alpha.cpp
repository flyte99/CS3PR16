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
	// Create some cargo storage
	CargoStorage cs1;
	CargoStorage cs2;
	CargoStorage cs3;

	// Create some loading bays
	LoadingBay in;
	LoadingBay out;
	
	// Create some trucks
	SimpleTruck a;
	DoubleTruck b;
	ComparatorTruck c;

	int choice = 0;	// for menu
	int position1;	// position of first (or only) item
	int position2;	// position of second item
	string storagearea;	// LoadingBay (in/out) or CargoStorage (cs1/cs2/cs3)
	string trucktype;	// Trucks (simple/double/comparator)
	string pickup;	// pick up all items from storage area
	string dropoff;	// put down all items in different storage area

	do
	{
		cout << "Choose 1 to make a delivery come in" << endl;
		cout << "Choose 2 to make a delivery go out" << endl;
		cout << "Choose 3 to get a truck to pick up something" << endl;
		cout << "Choose 4 to get a truck to put down something" << endl;
		cout << "Choose 5 to list contents in a storage area" << endl;
		cout << "Choose 6 to move all items from one storage area to another" << endl;
		cout << "Choose 7 to exit" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1: cout << "You chose to make a delivery come in" << endl;

			in.Arrive();	// random pallets generated into the LoadingBay in

			break;

		case 2:	cout << "You chose to make a deliver go out" << endl;

			out.Leave(); // pallets removed from the LoadingBay out

			break;

		case 3:	cout << "You chose to get a truck to pick up something" << endl;

			cout << "What kind of truck do you want to use? (simple/double/comparator)" << endl;
			cin >> trucktype;

			if (trucktype == "simple")
			{
				cout << "Where would you like to pick up from? (in/out/cs1/cs2/cs3)" << endl;
				cin >> storagearea;

				cout << "What positon is the item in? (0-9)" << endl;
				cin >> position1;

				if (storagearea == "in")
				{
					a.PickUpItem(position1, in);
				}
				else if (storagearea == "out")
				{
					a.PickUpItem(position1, out);
				}
				else if (storagearea == "cs1")
				{
					a.PickUpItem(position1, cs1);
				}
				else if (storagearea == "cs2")
				{
					a.PickUpItem(position1, cs2);
				}
				else if (storagearea == "cs3")
				{
					a.PickUpItem(position1, cs3);
				}
				else
				{
					cout << "Error: Invalid Storage Area" << endl;
				}

			}
			else if (trucktype == "double")
			{
				cout << "Where would you like to pick up from? (in/out/cs1/cs2/cs3)" << endl;
				cin >> storagearea;

				cout << "What positon is the first item in? (0-9)" << endl;
				cin >> position1;

				cout << "What position1 is the second item in? (0-9)" << endl;
				cin >> position2;

				if (storagearea == "in")
				{
					b.PickUpItem(position1, in);
					b.PickUpItem(position2, in);
				}
				else if (storagearea == "out")
				{
					b.PickUpItem(position1, out);
					b.PickUpItem(position2, out);
				}
				else if (storagearea == "cs1")
				{
					b.PickUpItem(position1, cs1);
					b.PickUpItem(position2, cs1);
				}
				else if (storagearea == "cs2")
				{
					b.PickUpItem(position1, cs2);
					b.PickUpItem(position2, cs2);
				}
				else if (storagearea == "cs3")
				{
					b.PickUpItem(position1, cs3);
					b.PickUpItem(position2, cs3);
				}
				else
				{
					cout << "Error: Invalid Storage Area" << endl;
				}
			}
			else if (trucktype == "comparator")
			{
				cout << "Where would you like to pick up from? (in/out/cs1/cs2/cs3)" << endl;
				cin >> storagearea;

				cout << "What positon is the first item in? (0-9)" << endl;
				cin >> position1;

				cout << "What position1 is the second item in? (0-9)" << endl;
				cin >> position2;

				if (storagearea == "in")
				{
					c.PickUpItem(position1, in);
					c.PickUpItem(position2, in);
				}
				else if (storagearea == "out")
				{
					c.PickUpItem(position1, out);
					c.PickUpItem(position2, out);
				}
				else if (storagearea == "cs1")
				{
					c.PickUpItem(position1, cs1);
					c.PickUpItem(position2, cs1);
				}
				else if (storagearea == "cs2")
				{
					c.PickUpItem(position1, cs2);
					c.PickUpItem(position2, cs2);
				}
				else if (storagearea == "cs3")
				{
					c.PickUpItem(position1, cs3);
					c.PickUpItem(position2, cs3);
				}
				else
				{
					cout << "Error: Invalid Storage Area" << endl;
				}
			}
			else
			{
				cout << "Invalid Truck Type" << endl;
			}

			break;

		case 4: cout << "You chose to get a truck to put down something" << endl;

			cout << "What kind of truck do you want to use? (simple/double/comparator)" << endl;
			cin >> trucktype;

			if (trucktype == "simple")
			{
				cout << "Where would you like to put the item down? (in/out/cs1/cs2/cs3)" << endl;
				cin >> storagearea;

				cout << "What positon do you want to put the item down in? (0-9)" << endl;
				cin >> position1;

				if (storagearea == "in")
				{
					a.PutDownItem(position1, in);
				}
				else if (storagearea == "out")
				{
					a.PutDownItem(position1, out);
				}
				else if (storagearea == "cs1")
				{
					a.PutDownItem(position1, cs1);
				}
				else if (storagearea == "cs2")
				{
					a.PutDownItem(position1, cs2);
				}
				else if (storagearea == "cs3")
				{
					a.PutDownItem(position1, cs3);
				}
				else
				{
					cout << "Error: Invalid Storage Area" << endl;
				}
			}
			else if (trucktype == "double")
			{
				cout << "Where would you like to put the items down? (in/out/cs1/cs2/cs3)" << endl;
				cin >> storagearea;

				cout << "What positon do you want to put the first item down in? (0-9)" << endl;
				cin >> position1;

				cout << "What position do you want to put the second item down in? (0-9)" << endl;
				cin >> position2;

				if (storagearea == "in")
				{
					b.PutDownItem(position1, in);
					b.PutDownItem(position2, in);
				}
				else if (storagearea == "out")
				{
					b.PutDownItem(position1, out);
					b.PutDownItem(position2, out);
				}
				else if (storagearea == "cs1")
				{
					b.PutDownItem(position1, cs1);
					b.PutDownItem(position2, cs1);
				}
				else if (storagearea == "cs2")
				{
					b.PutDownItem(position1, cs2);
					b.PutDownItem(position2, cs2);
				}
				else if (storagearea == "cs3")
				{
					b.PutDownItem(position1, cs3);
					b.PutDownItem(position2, cs3);
				}
				else
				{
					cout << "Error: Invalid Storage Area" << endl;
				}
			}
			else if (trucktype == "comparator")
			{
				cout << "Where would you like to put the items down? (in/out/cs1/cs2/cs3)" << endl;
				cin >> storagearea;

				cout << "What positon do you want to put the first item down in? (0-9)" << endl;
				cin >> position1;

				cout << "What position do you want to put the second item down in? (0-9)" << endl;
				cin >> position2;

				if (storagearea == "in")
				{
					c.PutDownItem(position1, in);
					c.PutDownItem(position2, in);
				}
				else if (storagearea == "out")
				{
					c.PutDownItem(position1, out);
					c.PutDownItem(position2, out);
				}
				else if (storagearea == "cs1")
				{
					c.PutDownItem(position1, cs1);
					c.PutDownItem(position2, cs1);
				}
				else if (storagearea == "cs2")
				{
					c.PutDownItem(position1, cs2);
					c.PutDownItem(position2, cs2);
				}
				else if (storagearea == "cs3")
				{
					c.PutDownItem(position1, cs3);
					c.PutDownItem(position2, cs3);
				}
				else
				{
					cout << "Error: Invalid Storage Area" << endl;
				}
			}
			else
			{
				cout << "Invalid Truck Type" << endl;
			}

			break;

		case 5: cout << "You chose to list the contents in a storage area" << endl;

			cout << "Which storage area? (in/out/cs1/cs2/cs3)" << endl;
			cin >> storagearea;

			if (storagearea == "in")
			{
				in.ListContents();
			}
			else if (storagearea == "out")
			{
				out.ListContents();
			}
			else if (storagearea == "cs1")
			{
				cs1.ListContents();
			}
			else if (storagearea == "cs2")
			{
				cs2.ListContents();
			}
			else if (storagearea == "cs3")
			{
				cs3.ListContents();
			}
			else
			{
				cout << "Error: Invalid Storage Area" << endl;
			}

			break;

		case 6: cout << "You chose to move all the items from one storage type to another" << endl;

			cout << "Where do you want to pick the items from? (in/out/cs1/cs2/cs3)" << endl;
			cin >> pickup;

			cout << "Where do you want to drop off the items? (in/out/cs1/cs2/cs3)" << endl;
			cin >> dropoff;

			if (pickup == "in")
			{
				if (dropoff == "out")
				{
					for (int i = 0; i < 10; i++)
					{
						a.PickUpItem(i, in);
						a.PutDownItem(i, out);
					}
				}
				if (dropoff == "cs1")
				{
					for (int i = 0; i < 10; i++)
					{
						a.PickUpItem(i, in);
						a.PutDownItem(i, cs1);
					}
				}
				if (dropoff == "cs2")
				{
					for (int i = 0; i < 10; i++)
					{
						a.PickUpItem(i, in);
						a.PutDownItem(i, cs2);
					}
				}
				if (dropoff == "cs3")
				{
					for (int i = 0; i < 10; i++)
					{
						a.PickUpItem(i, in);
						a.PutDownItem(i, cs3);
					}
				}
			}

			else if (pickup == "out")
			{
				if (dropoff == "in")
				{
					for (int i = 0; i < 10; i++)
					{
						a.PickUpItem(i, out);
						a.PutDownItem(i, in);
					}
				}
				if (dropoff == "cs1")
				{
					for (int i = 0; i < 10; i++)
					{
						a.PickUpItem(i, out);
						a.PutDownItem(i, cs1);
					}
				}
				if (dropoff == "cs2")
				{
					for (int i = 0; i < 10; i++)
					{
						a.PickUpItem(i, out);
						a.PutDownItem(i, cs2);
					}
				}
				if (dropoff == "cs3")
				{
					for (int i = 0; i < 10; i++)
					{
						a.PickUpItem(i, out);
						a.PutDownItem(i, cs3);
					}
				}
			}

			else if (pickup == "cs1")
			{
				if (dropoff == "in")
				{
					for (int i = 0; i < 10; i++)
					{
						a.PickUpItem(i, cs1);
						a.PutDownItem(i, in);
					}
				}
				if (dropoff == "out")
				{
					for (int i = 0; i < 10; i++)
					{
						a.PickUpItem(i, cs1);
						a.PutDownItem(i, out);
					}
				}
				if (dropoff == "cs2")
				{
					for (int i = 0; i < 10; i++)
					{
						a.PickUpItem(i, cs1);
						a.PutDownItem(i, cs2);
					}
				}
				if (dropoff == "cs3")
				{
					for (int i = 0; i < 10; i++)
					{
						a.PickUpItem(i, cs1);
						a.PutDownItem(i, cs3);
					}
				}
			}

			else if (pickup == "cs2")
			{
				if (dropoff == "in")
				{
					for (int i = 0; i < 10; i++)
					{
						a.PickUpItem(i, cs2);
						a.PutDownItem(i, in);
					}
				}
				if (dropoff == "out")
				{
					for (int i = 0; i < 10; i++)
					{
						a.PickUpItem(i, cs2);
						a.PutDownItem(i, out);
					}
				}
				if (dropoff == "cs1")
				{
					for (int i = 0; i < 10; i++)
					{
						a.PickUpItem(i, cs2);
						a.PutDownItem(i, cs1);
					}
				}
				if (dropoff == "cs3")
				{
					for (int i = 0; i < 10; i++)
					{
						a.PickUpItem(i, cs2);
						a.PutDownItem(i, cs3);
					}
				}
			}

			else if (pickup == "cs3")
			{
				if (dropoff == "in")
				{
					for (int i = 0; i < 10; i++)
					{
						a.PickUpItem(i, cs3);
						a.PutDownItem(i, in);
					}
				}
				if (dropoff == "out")
				{
					for (int i = 0; i < 10; i++)
					{
						a.PickUpItem(i, cs3);
						a.PutDownItem(i, out);
					}
				}
				if (dropoff == "cs1")
				{
					for (int i = 0; i < 10; i++)
					{
						a.PickUpItem(i, cs3);
						a.PutDownItem(i, cs1);
					}
				}
				if (dropoff == "cs2")
				{
					for (int i = 0; i < 10; i++)
					{
						a.PickUpItem(i, cs3);
						a.PutDownItem(i, cs2);
					}
				}
			}

			else
			{
				cout << "Error: Invalid Storage Areas" << endl;
			}

			break;

		case 7: cout << "You chose to exit the program" << endl;

				break;

		default: cout << "Invalid Command" << endl;

				break;
		}

	} while (choice != 7);

	return 0;
}

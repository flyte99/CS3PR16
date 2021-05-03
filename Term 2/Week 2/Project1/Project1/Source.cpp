#include <iostream> /*C++ input and output stream*/
#include <string>
#include <cstdlib>
#include <ctime>
#include "food_and_drink.h" 

using namespace std;

int main()
{
	string name; /*The name can have infinite characters by making it a string*/
	string answer;
	int x = 0;
	string food = GetRandomFoodItem(); /*Will select random food item and assign it to food*/
	string drink = GetRandomDrinkItem(); /*Will select random drink item and assign it to drink*/

	cout << "Enter a name:" << endl;
	cin >> name;
	cout << "Does " << name << " eats or drinks?" << endl; 
	cin >> answer;
	

	if (answer == "eats")
	{
		cout << "How many items?:" << endl;
		cin >> x;

		cout << name << " " << "eats" << " " << x << " " << food << endl; /*Displays the simple statement ‘[NAME] [EATS] [x] [ITEMS]’*/
	}

	else if (answer == "drinks")
	{
		cout << "How many items?:" << endl;
		cin >> x;

		cout << name << " " << "drinks" << " " << x << " " << drink << endl; /*Displays the simple statement ‘[NAME] [DRINKS] [x] [ITEMS]’*/
	}

	return 0;
}
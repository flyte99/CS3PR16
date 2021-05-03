#include "pallet.h"
#include "cargostorage.h"
#include "simpletruck.h"
#include "palletgenerator.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

Pallet::Pallet() {
	id = -1;
	maxWeight = -1;
}
Pallet::Pallet(int id, int maxWeight) /*Constructor*/
{
	this->id = id;
	this->maxWeight = maxWeight;
}
bool Pallet::AddItem(string item)
{
	if (palletContents.size() >= maxWeight) /*Ensures pallet doesn't go over the max weight*/
	{
		cout << "Error: Max Weight Reached" << endl;
		return false;
	}
	else
	{
		palletContents.push_back(item);	/*Adds item to the vector (at the end)*/
		return true;
	}
}
void Pallet::RemoveTopItem()
{
	palletContents.pop_back();	/*Removes last item added*/
}
string Pallet::GetItemAtPosition(int position)
{
	if (position > palletContents.size())		/*Program won't crash if there is no item at the position*/
	{
		return string("Error: No Item at this Position");
	}
	else
	{
		return palletContents[position];
	}
}
void Pallet::ListAllItems()
{
	cout << "[Pallet " << id << " | Weight " << GetCurrentWeight() << "/" << GetMaxWeight() << "]" << endl;

	for (int i = palletContents.size(); i > 0; i--)	/*Loops listing all the items*/
	{
		cout << "\t" << i << ": " << palletContents[i - 1] << endl;
	}

	if (palletContents.size() == 0)
	{
		cout << "\tEmpty" << endl;
	}
}
int Pallet::GetCurrentWeight()
{
	return palletContents.size();		/*Current weight = the size of the vector*/
}
int Pallet::GetMaxWeight()
{
	return maxWeight;
}
int Pallet::GetID()
{
	return id;
}

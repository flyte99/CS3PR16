#pragma once
#ifndef CARGOSTORAGE_H
#define CARGOSTORAGE_H

#include "pallet.h"
#include "palletgenerator.h"
#include <iostream>
#include <string>
#include <vector>

class CargoStorage
{
public:
	CargoStorage();

	bool AddPalletAtPosition(int position, Pallet pallet);
	Pallet RetrievePalletFromPosition(int position);
	void ListContents();

protected:
	std::vector<Pallet> storage;

	std::vector<bool> slotFull;
};

#endif




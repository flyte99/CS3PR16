#pragma once
#ifndef SIMPLETRUCK_H
#define SIMPLETRUCK_H

#include "pallet.h"
#include "cargostorage.h"
#include "palletgenerator.h"
#include <iostream>
#include <string>
#include <vector>

class SimpleTruck
{
public:
	SimpleTruck();

	bool PickUpItem(int position, CargoStorage &storage);
	bool PutDownItem(int position, CargoStorage &storage);

private:
	Pallet forklift;
};

#endif

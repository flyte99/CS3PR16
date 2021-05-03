#pragma once
#ifndef COMPARATORTRUCK_H
#define COMPARATORTRUCK_H

#include "pallet.h"
#include "cargostorage.h"
#include "simpletruck.h"
#include "loadingbay.h"
#include "doubletruck.h"
#include "palletgenerator.h"
#include <iostream>
#include <string>
#include <vector>

class ComparatorTruck : public DoubleTruck
{
public:
	ComparatorTruck();

	virtual bool PutDownItem(int position, CargoStorage &storage);
};

#endif
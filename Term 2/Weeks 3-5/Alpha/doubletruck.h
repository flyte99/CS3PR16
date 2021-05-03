#pragma once
#ifndef DOUBLETRUCK_H
#define DOUBLETRUCK_H

#include "pallet.h"
#include "cargostorage.h"
#include "simpletruck.h"
#include "loadingbay.h"
#include "palletgenerator.h"
#include <iostream>
#include <string>
#include <vector>

class DoubleTruck : public SimpleTruck
{
public:
	DoubleTruck();

	bool PickUpItem(int position, CargoStorage &storage);
	virtual bool PutDownItem(int position, CargoStorage &storage);

protected:
	Pallet forklift1;
	Pallet forklift2;

};

#endif

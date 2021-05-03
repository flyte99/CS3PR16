#pragma once
#ifndef LOADINGBAY_H
#define LOADINGBAY_H

#include "pallet.h"
#include "cargostorage.h"
#include "simpletruck.h"
#include "palletgenerator.h"
#include <iostream>
#include <string>
#include <vector>

class LoadingBay : public CargoStorage
{
public:
	LoadingBay();
	
	void Arrive();
	void Leave();
};

#endif

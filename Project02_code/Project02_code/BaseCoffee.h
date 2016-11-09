#pragma once
#include "Coffee.h"
class BaseCoffee :
	public Coffee
{
public:
	BaseCoffee();
	~BaseCoffee();

	int getCost();
	vector<int> GetIngredientsID();
};


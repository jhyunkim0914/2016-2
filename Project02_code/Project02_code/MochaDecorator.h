#pragma once
#include "IngredientsDecorator.h"
class MochaDecorator :
	public IngredientsDecorator
{
public:
	MochaDecorator(Coffee* c);
	~MochaDecorator();

	int getCost();
	vector<int> GetIngredientsID();
};


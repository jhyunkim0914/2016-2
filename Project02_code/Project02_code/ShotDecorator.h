#pragma once
#include "IngredientsDecorator.h"
class ShotDecorator :
	public IngredientsDecorator
{
public:
	ShotDecorator(Coffee* c);
	~ShotDecorator();

	int getCost();
	vector<int> GetIngredientsID();
};


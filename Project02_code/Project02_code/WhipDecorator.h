#pragma once
#include "IngredientsDecorator.h"
class WhipDecorator :
	public IngredientsDecorator
{
public:
	WhipDecorator(Coffee* c);
	~WhipDecorator();

	int getCost();
	vector<int> GetIngredientsID();
};


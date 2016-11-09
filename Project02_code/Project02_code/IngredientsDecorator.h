#pragma once
#include "Coffee.h"
class IngredientsDecorator :
	public Coffee
{
public:
	IngredientsDecorator();
	IngredientsDecorator(Coffee* coffee);
	~IngredientsDecorator();

protected:
	Coffee* pCoffee;
};


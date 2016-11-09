#include "IngredientsDecorator.h"

IngredientsDecorator::IngredientsDecorator()
{
}

IngredientsDecorator::IngredientsDecorator(Coffee * coffee)
{
	pCoffee = coffee;
}

IngredientsDecorator::~IngredientsDecorator()
{
	if (pCoffee)
	{
		delete pCoffee;
	}
}
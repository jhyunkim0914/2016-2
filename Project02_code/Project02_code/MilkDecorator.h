#pragma once
#include "IngredientsDecorator.h"
class MilkDecorator :
	public IngredientsDecorator
{
public:
	MilkDecorator(Coffee* c);
	~MilkDecorator();

	int getCost();
	vector<int> GetIngredientsID();
};


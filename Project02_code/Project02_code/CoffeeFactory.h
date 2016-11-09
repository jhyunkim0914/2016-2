#pragma once
//#include "Coffee.h"
#include "BaseCoffee.h"
#include "MilkDecorator.h"
#include "MochaDecorator.h"
#include "ShotDecorator.h"
#include "WhipDecorator.h"

class CoffeeFactory
{
public:
	CoffeeFactory();
	~CoffeeFactory();

	Coffee* makeCoffee(int coffeeID);
};


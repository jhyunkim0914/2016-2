#include "CoffeeFactory.h"

CoffeeFactory::CoffeeFactory()
{
}

CoffeeFactory::~CoffeeFactory()
{
}

Coffee * CoffeeFactory::makeCoffee(int coffeeID)
{
	Coffee *newCoffee = new BaseCoffee();

	switch (coffeeID)
	{
	case 1:
		break;
	case 2:
		newCoffee = new MilkDecorator(newCoffee); //카푸치노(커피+우유)
		break;
	case 3:
		newCoffee = new MochaDecorator(newCoffee); //모카커피(커피+모카);
		break;
	}
	return newCoffee;
}

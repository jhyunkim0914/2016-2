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
		newCoffee = new MilkDecorator(newCoffee); //īǪġ��(Ŀ��+����)
		break;
	case 3:
		newCoffee = new MochaDecorator(newCoffee); //��īĿ��(Ŀ��+��ī);
		break;
	}
	return newCoffee;
}

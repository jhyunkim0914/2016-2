#include "MochaDecorator.h"

MochaDecorator::MochaDecorator(Coffee * c)
{
	pCoffee = c;
}

MochaDecorator::~MochaDecorator()
{
}

int MochaDecorator::getCost()
{
	return pCoffee->getCost() + 500;
}

vector<int> MochaDecorator::GetIngredientsID()
{
	vector<int> ingredientsIDs;
	ingredientsIDs = pCoffee->GetIngredientsID();
	ingredientsIDs.push_back(3);
	return ingredientsIDs;
}

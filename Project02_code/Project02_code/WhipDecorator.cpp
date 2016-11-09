#include "WhipDecorator.h"

WhipDecorator::WhipDecorator(Coffee * c)
{
	pCoffee = c;
}

WhipDecorator::~WhipDecorator()
{
}

int WhipDecorator::getCost()
{
	return pCoffee->getCost() + 0;
}

vector<int> WhipDecorator::GetIngredientsID()
{
	vector<int> ingredientsIDs;
	ingredientsIDs = pCoffee->GetIngredientsID();
	ingredientsIDs.push_back(5);
	return ingredientsIDs;
}

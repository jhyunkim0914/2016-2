#include "MilkDecorator.h"

MilkDecorator::MilkDecorator(Coffee * c)
{
	pCoffee = c;
}

MilkDecorator::~MilkDecorator()
{
}

int MilkDecorator::getCost()
{
	return pCoffee->getCost() + 1000;
}

vector<int> MilkDecorator::GetIngredientsID()
{
	vector<int> ingredientsIDs;
	ingredientsIDs = pCoffee->GetIngredientsID();
	ingredientsIDs.push_back(2);
	return ingredientsIDs;
}

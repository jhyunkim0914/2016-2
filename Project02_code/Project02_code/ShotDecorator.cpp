#include "ShotDecorator.h"

ShotDecorator::ShotDecorator(Coffee * c)
{
	pCoffee = c;
}

ShotDecorator::~ShotDecorator()
{
}

int ShotDecorator::getCost()
{
	return pCoffee->getCost() + 500;
}

vector<int> ShotDecorator::GetIngredientsID()
{
	vector<int> ingredientsIDs;
	ingredientsIDs = pCoffee->GetIngredientsID();
	ingredientsIDs.push_back(4);
	return ingredientsIDs;
}

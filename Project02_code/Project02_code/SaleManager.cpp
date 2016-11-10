#include "SaleManager.h"

SaleManager::SaleManager()
{
	price = 0;
}

SaleManager::~SaleManager()
{
}

void SaleManager::addPrice(int price)
{
	this->price += price;
}

void SaleManager::setPrice(int price)
{
	this->price = price;
}

int SaleManager::getPrice()
{
	return price;
}

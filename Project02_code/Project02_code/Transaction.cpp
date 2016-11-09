#include "Transaction.h"

Transaction::Transaction()
{
}

Transaction::Transaction(vector<int> order, int price)
{
	orderedCoffeeInfo = order;
	this->price = price;
}

Transaction::~Transaction()
{
}

vector<int> Transaction::getCoffeeInfo()
{
	return orderedCoffeeInfo;
}

int Transaction::getPrice()
{
	return price;
}

void Transaction::printTransaction()
{
	for (vector<int>::iterator iter = orderedCoffeeInfo.begin(); iter != orderedCoffeeInfo.end(); iter++)
	{
		cout << *iter << "-";
	}
	cout << price << "¿ø" << endl;
}

#include "OrderTransactionManager.h"

OrderTransactionManager::OrderTransactionManager()
{
}

OrderTransactionManager::~OrderTransactionManager()
{
}

void OrderTransactionManager::addTransaction(Transaction t)
{
	orderTransactions.push_back(t);
}

Transaction OrderTransactionManager::getFrontTransaction()
{
	vector<Transaction>::iterator iter = orderTransactions.begin();
	return *iter;
}

Transaction OrderTransactionManager::getTransactionByIndex(int idx)
{
	return orderTransactions[idx];
}

void OrderTransactionManager::deleteTransactionFromFront()
{
	vector<Transaction>::iterator iter = orderTransactions.begin();
	orderTransactions.erase(iter);
}

void OrderTransactionManager::deleteTransactionByIndex(int idx)
{
	vector<Transaction>::iterator iter = orderTransactions.begin();
	orderTransactions.erase(iter + idx);
}

void OrderTransactionManager::printTransactions()
{
	int index = 1;
	for (vector<Transaction>::iterator iter = orderTransactions.begin(); iter != orderTransactions.end(); iter++)
	{
		cout << index << "¹ø. ";		iter->printTransaction();
	}
}

bool OrderTransactionManager::isEmpty()
{
	if (orderTransactions.empty())
		return true;
	else
		return false;
}

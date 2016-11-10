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
	Transaction result;
	int price = -1;

	for (; iter != orderTransactions.end(); iter++)
	{
		//0원 음료가 출력이 가능하게 한다.
		
		//비싼 음료가 먼저 출력되게 한다.
		if (iter->getPrice() > price)
		{
			price = iter->getPrice();
			result = *iter;
		}
	}
	
	return result;
}

Transaction OrderTransactionManager::getTransactionByIndex(int idx)
{
	return orderTransactions[idx];
}

void OrderTransactionManager::deleteTransactionFromFront()
{
	if (orderTransactions.empty())
		return;
	vector<Transaction>::iterator iter = orderTransactions.begin();
	orderTransactions.erase(iter);
}

void OrderTransactionManager::deleteTransactionByIndex(int idx)
{
	if (orderTransactions.size() <= idx)
		return;
	vector<Transaction>::iterator iter = orderTransactions.begin();
	orderTransactions.erase(iter + idx);
}

void OrderTransactionManager::deleteTransactionByIndex(Transaction* transaction)
{
	for (vector<Transaction>::iterator iter = orderTransactions.begin(); iter != orderTransactions.end(); iter++)
	{
		if (*iter == *transaction)
		{
			orderTransactions.erase(iter);
			return;
		}
	}
}

void OrderTransactionManager::printTransactions()
{
	int index = 1;
	for (vector<Transaction>::iterator iter = orderTransactions.begin(); iter != orderTransactions.end(); iter++)
	{
		cout << index << "번. ";		iter->printTransaction();
		index++;
	}
}

bool OrderTransactionManager::isEmpty()
{
	if (orderTransactions.empty())
		return true;
	else
		return false;
}

int OrderTransactionManager::getLength()
{
	return orderTransactions.size();
}

#pragma once
#include "Transaction.h"
#include <vector>
#include <iostream>
using namespace std;
class OrderTransactionManager
{
public:
	OrderTransactionManager();
	~OrderTransactionManager();

	void addTransaction(Transaction t);
	Transaction getFrontTransaction();
	Transaction getTransactionByIndex(int idx);
	void deleteTransactionFromFront();
	void deleteTransactionByIndex(int idx);
	void printTransactions();
	bool isEmpty();

private:
	vector<Transaction> orderTransactions;
};


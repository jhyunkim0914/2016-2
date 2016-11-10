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
	void deleteTransactionByIndex(Transaction* transaction);
	void printTransactions();
	bool isEmpty();
	int getLength();

private:
	vector<Transaction> orderTransactions;
};


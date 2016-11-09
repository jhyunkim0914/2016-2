#pragma once
#include <vector>
#include <iostream>
using namespace std;
class Transaction
{
public:
	Transaction();
	Transaction(vector<int> order, int price);
	~Transaction();
	vector<int> getCoffeeInfo();
	int getPrice();
	void printTransaction();

private:
	vector<int> orderedCoffeeInfo;
	int price;
};


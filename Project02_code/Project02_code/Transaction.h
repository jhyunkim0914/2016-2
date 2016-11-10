#pragma once
#include <vector>
#include <iostream>
#include <string>

using namespace std;
class Transaction
{
public:
	Transaction();
	Transaction(vector<int> order, int price);
	~Transaction();
	vector<int> getCoffeeInfo();
	int getPrice();
	void printCoffee();
	void printTransaction();
	bool operator==(Transaction transaction);
private:
	vector<int> orderedCoffeeInfo;
	int price;
};


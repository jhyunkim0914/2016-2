#pragma once
#include <string>
#include <vector>
using namespace std;

class Coffee
{
public:
	Coffee();
	~Coffee();

	virtual int getCost() = 0;
	virtual vector<int> GetIngredientsID() = 0;
private:
	int cost;
	vector<int> ingredientsIDs;
};


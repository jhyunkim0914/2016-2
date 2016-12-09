#pragma once
#include <iostream>
#include <string>
using namespace std;

class Composer
{
public:
	Composer();
	~Composer();
	bool setComposerFromKB();
	int getId();
	string getName();
	void setId(int id);
	void setName(string name);

private:
	int id;
	string name;
};


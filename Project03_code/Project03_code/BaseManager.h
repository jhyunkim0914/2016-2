#pragma once
#include <fstream>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

class BaseManager
{
public:
	BaseManager();
	~BaseManager();	

	void setFileName(string _name);

protected:
	string fileName;
};


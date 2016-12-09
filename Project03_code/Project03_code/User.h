#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class User
{
public:
	User();
	int getIsAdmin();
	void setIsAdmin(int isAdmin);
	int getId();
	void setId(int id);
	string getPW();
	void setPW(string password);
	vector<int> *getPurchasedList();
	void setPurchasedList(vector<int> list);
	void setUserFromKB();
	~User();

private:
	int isAdmin;
	int id;
	string password;
	vector<int> purchasedList;
};


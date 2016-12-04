#include "User.h"

User::User()
{
}

int User::getIsAdmin()
{
	return isAdmin;
}

void User::setIsAdmin(int isAdmin)
{
	this->isAdmin = isAdmin;
}

int User::getId()
{
	return id;
}

void User::setId(int id)
{
	this->id = id;
}

string User::getPW()
{
	return password;
}

void User::setPW(string password)
{
	this->password = password;
}

vector<int>* User::getPurchasedList()
{
	return &purchasedList;
}

void User::setPurchasedList(vector<int> list)
{
	this->purchasedList = list;
}

User::~User()
{
}

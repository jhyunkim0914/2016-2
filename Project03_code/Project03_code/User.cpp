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

void User::setUserFromKB()
{
	int tempId;
	int isAdmin;
	string tempPW;
	cout << "관리자입니까?(0/1)";
	cin >> isAdmin;
	cout << "아이디(숫자) : ";
	cin >> tempId;
	cout << "비밀번호 : ";
	cin >> tempPW;
	this->isAdmin = isAdmin;  this->id = tempId; this->password = tempPW;
}

User::~User()
{
}

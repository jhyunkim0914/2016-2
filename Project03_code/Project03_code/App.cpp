#include "App.h"

App::App()
{
	um = new UserManager("userDB");
}

App::~App()
{
}

void App::run()
{
	um->setDBFromFile();

	vector<User> temp;

	/*
	temp = um->getAllUserList();

	for (vector<User>::iterator it = temp.begin(); it != temp.end(); it++)
	{
		cout << "메모리 상의 유저";
		cout << it->getIsAdmin() << '\t'
			<< it->getId() << '\t'
			<< it->getPW() << '\t';
		for (vector<int>::iterator it2 = it->getPurchasedList()->begin(); it2 != it->getPurchasedList()->end(); it2++)
		{
			cout << *it2 << '\t';
		}
		cout << endl;
	}
	*/

	return;
}

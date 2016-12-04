#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct status
{
	char name[80];
	float balance;
	unsigned long account_num;
};

int main()
{
	struct status acc;   strcpy_s(acc.name, "Ralph Trantor");
	acc.balance = 1123.23;
	acc.account_num = 34235678;
	ofstream outbal("balance", ios::out | ios::binary);
	if (!outbal)
	{
		cout << "Cannot open file.\n";
		return 1;
	}   outbal.write((char *)&acc, sizeof(struct status));
	outbal.close();   // 다시 읽기

	strcpy_s(acc.name, "");
	acc.balance = -1;
	acc.account_num = -1;



	ifstream inbal("balance", ios::in | ios::binary);

	if (!inbal)
	{
		cout << "Cannot open file.\n";
		return 1;
	}   inbal.read((char *)&acc, sizeof(struct status));
	cout << acc.name << endl;
	cout << "Account # " << acc.account_num;
	cout.precision(2);
	cout.setf(ios::fixed);
	cout << endl << "Balance: $" << acc.balance;   inbal.close();
	return 0;

}
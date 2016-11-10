#include "Transaction.h"

Transaction::Transaction()
{
}

Transaction::Transaction(vector<int> order, int price)
{
	orderedCoffeeInfo = order;
	this->price = price;
}

Transaction::~Transaction()
{
}

vector<int> Transaction::getCoffeeInfo()
{
	return orderedCoffeeInfo;
}

int Transaction::getPrice()
{
	return price;
}

void Transaction::printCoffee()
{
	//���� �̻���
	string title1 = "�Ƹ޸�ī��";
	string title2 = "īǪġ��";
	string title3 = "��īĿ��";
	string title4 = "��";
	string title5 = "����ũ��";
	string menu = "";

	bool isAdded = false;

	menu += "�ֹ��Ͻ� ";

	for (vector<int>::iterator iter = orderedCoffeeInfo.begin(); iter != orderedCoffeeInfo.end(); iter++)
	{
		if (*iter == 1)
			menu += title1;
		else if (*iter == 2)
			menu += title2;
		else if (*iter == 3)
			menu += title3;
	}
	for (vector<int>::iterator iter = orderedCoffeeInfo.begin(); iter != orderedCoffeeInfo.end(); iter++)
	{
		if (*iter == 4 || *iter == 5)
		{
			isAdded = true;
			break;
		}
	}
	if (isAdded)
	{
		menu += "�� ";

	}
	for (vector<int>::iterator iter = orderedCoffeeInfo.begin(); iter != orderedCoffeeInfo.end(); iter++)
	{
		if (*iter == 4)
		{
			menu += title4;
			menu += ",";
		}
		else if (*iter == 5)
		{
			menu += title5;
			menu += ",";
		}
	}
	if (isAdded)
	{
		menu[menu.length() - 1] = ' ';
		menu += "�߰�";
	}
	
	menu += "���Խ��ϴ�.";

	cout << menu << endl;
	cout << "�� ������ " << price << "�� �Դϴ�." << endl;
}

void Transaction::printTransaction()
{
	string result = "";
	for (vector<int>::iterator iter = orderedCoffeeInfo.begin(); iter != orderedCoffeeInfo.end(); iter++)
	{
		
		string title1 = "�Ƹ޸�ī��";
		string title2 = "īǪġ��";
		string title3 = "��īĿ��";
		string title4 = "��";
		string title5 = "����ũ��";
		

		if (*iter == 1)
			result = result + title1 + ",";
		else if (*iter == 2)
			result = result + title2 + ",";
		else if (*iter == 3)
			result = result + title3 + ",";
		else if (*iter == 4)
			result = result + title4 + ",";
		else if (*iter == 5)
			result = result + title5 + ",";
	}
	cout << result << endl;
}

bool Transaction::operator==(Transaction transaction)
{
	if (transaction.getPrice() == price && transaction.getCoffeeInfo() == orderedCoffeeInfo)
		return true;
	else
		return false;
}

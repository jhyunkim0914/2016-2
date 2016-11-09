#include "StockManager.h"

StockManager::StockManager()
{
}

StockManager::~StockManager()
{
}

bool StockManager::addStockByIngredientsID(vector<int> ingredientsID)
{

	for (vector<int>::iterator iter = ingredientsID.begin(); iter != ingredientsID.end(); iter++)
	{
		if (*iter == 1)
			coffeeStock++;
		else if (*iter == 2)
			milkStock++;
		else if (*iter == 3)
			mochaStock++;
		else if (*iter == 4)
			shotStock++;
		else if (*iter == 5)
			whipStock++;
	}
	return true;
}

bool StockManager::addStockByNumber(vector<int> ingredientsID)
{
	coffeeStock += ingredientsID[0];
	milkStock += ingredientsID[1];
	mochaStock += ingredientsID[2];
	shotStock += ingredientsID[3];
	whipStock += ingredientsID[4];
	return true;
}

bool StockManager::reduceStockByIngredientsID(vector<int> ingredientsID)
{
	//1.Ŀ�� 2.���� 3.��ī 4.�� 5.����ũ��
	for (vector<int>::iterator iter = ingredientsID.begin(); iter != ingredientsID.end(); iter++)
	{
		if (*iter == 1 && coffeeStock < 1)
			return false;
		else if (*iter == 2 && milkStock < 1)
			return false;
		else if (*iter == 3 && mochaStock < 1)
			return false;
		else if (*iter == 4 && shotStock < 1)
			return false;
		else if (*iter == 5 && whipStock < 1)
			return false;
	}

	//��ü �����˻�
	//�ش������ ��� ���� �ִ°�?
	//���Ŀ� ��� ����

	for (vector<int>::iterator iter = ingredientsID.begin(); iter != ingredientsID.end(); iter++)
	{
		if (*iter == 1)
			coffeeStock--;
		else if (*iter == 2)
			milkStock--;
		else if (*iter == 3)
			mochaStock--;
		else if (*iter == 4)
			shotStock--;
		else if (*iter == 5)
			whipStock--;
	}
	return true;
}

void StockManager::setCoffeeStock(int cs)
{
	this->coffeeStock = cs;
}

void StockManager::setMilkStock(int ms)
{
	this->milkStock = ms;
}

void StockManager::setMochaStock(int ms)
{
	this->mochaStock = ms;
}

void StockManager::setShotStock(int ss)
{
	this->shotStock = ss;
}

void StockManager::setWhipStock(int ws)
{
	this->whipStock = ws;
}

int StockManager::getCoffeeStock()
{
	return coffeeStock;
}

int StockManager::getMilkStock()
{
	return milkStock;
}

int StockManager::getMochaStock()
{
	return mochaStock;
}

int StockManager::getShotStock()
{
	return shotStock;
}

int StockManager::getWhipStock()
{
	return whipStock;
}

void StockManager::printStock()
{
	cout << "Ŀ�� ���� : " << coffeeStock << endl;
	cout << "���� ���� : " << milkStock << endl;
	cout << "��ī ���� : " << mochaStock << endl;
	cout << "�� ���� : " << shotStock << endl;
	cout << "���� ���� : " << whipStock << endl;
}

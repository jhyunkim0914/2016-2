#include "ManagerFacade.h"

ManagerFacade::ManagerFacade()
{
}

ManagerFacade::ManagerFacade(OrderTransactionManager * _otm, StockManager * _sm, SaleManager * _slm)
{
	otm = _otm;
	sm = _sm;
	slm = _slm;
}

ManagerFacade::~ManagerFacade()
{
}

void ManagerFacade::orderIngredients()
{
	int input;
	vector<int> params;
	cout << "Ŀ�� ���� : ";
	cin >> input;
	params.push_back(input);
	cout << "���� ���� : ";
	cin >> input;
	params.push_back(input);
	cout << "��ī ���� : ";
	cin >> input;
	params.push_back(input);
	cout << "�� ���� : ";
	cin >> input;
	params.push_back(input);
	cout << "���� ���� : ";
	cin >> input;
	params.push_back(input);

	sm->addStockByIngredientsID(params);
}

void ManagerFacade::printStockStatus()
{
	sm->printStock();
}

void ManagerFacade::printTransactionStatus()
{
	otm->printTransactions();
}

void ManagerFacade::printSales()
{
	cout << "�� �Ǹž��� " << slm->getPrice() << "�� �Դϴ�." << endl;
}

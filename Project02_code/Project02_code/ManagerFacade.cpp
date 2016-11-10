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
	int totalPrice = 0;

	cout << "Ŀ�� ���� : ";
	cin >> input;
	params.push_back(input);
	totalPrice = totalPrice + input * 2000;

	cout << "���� ���� : ";
	cin >> input;
	params.push_back(input);
	totalPrice = totalPrice + input * 500;

	cout << "��ī ���� : ";
	cin >> input;
	params.push_back(input);
	totalPrice = totalPrice + input * 200;

	cout << "�� ���� : ";
	cin >> input;
	params.push_back(input);
	totalPrice = totalPrice + input * 200;

	cout << "���� ���� : ";
	cin >> input;
	params.push_back(input);
	totalPrice = totalPrice + input * 100;


	if (totalPrice > slm->getPrice())
	{
		cout << "�ܾ��� �����մϴ�." << endl;
	}
	else
	{
		sm->addStockByNumber(params);
		slm->setPrice(slm->getPrice() - totalPrice);
		cout << "�ֹ��� �Ϸ�Ǿ����ϴ�." << endl;
	}
	
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
	cout << "�� �ں����� " << slm->getPrice() << "�� �Դϴ�." << endl;
}

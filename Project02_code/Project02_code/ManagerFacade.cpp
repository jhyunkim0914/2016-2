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

	cout << "커피 수량 : ";
	cin >> input;
	params.push_back(input);
	totalPrice = totalPrice + input * 2000;

	cout << "우유 수량 : ";
	cin >> input;
	params.push_back(input);
	totalPrice = totalPrice + input * 500;

	cout << "모카 수량 : ";
	cin >> input;
	params.push_back(input);
	totalPrice = totalPrice + input * 200;

	cout << "샷 수량 : ";
	cin >> input;
	params.push_back(input);
	totalPrice = totalPrice + input * 200;

	cout << "휘핑 수량 : ";
	cin >> input;
	params.push_back(input);
	totalPrice = totalPrice + input * 100;


	if (totalPrice > slm->getPrice())
	{
		cout << "잔액이 부족합니다." << endl;
	}
	else
	{
		sm->addStockByNumber(params);
		slm->setPrice(slm->getPrice() - totalPrice);
		cout << "주문이 완료되었습니다." << endl;
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
	cout << "총 자본금은 " << slm->getPrice() << "원 입니다." << endl;
}

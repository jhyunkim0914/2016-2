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
	cout << "커피 수량 : ";
	cin >> input;
	params.push_back(input);
	cout << "우유 수량 : ";
	cin >> input;
	params.push_back(input);
	cout << "모카 수량 : ";
	cin >> input;
	params.push_back(input);
	cout << "샷 수량 : ";
	cin >> input;
	params.push_back(input);
	cout << "휘핑 수량 : ";
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
	cout << "총 판매액은 " << slm->getPrice() << "원 입니다." << endl;
}

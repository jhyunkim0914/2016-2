#pragma once
#include "StockManager.h"
#include "OrderTransactionManager.h"
#include "SaleManager.h"
class ManagerFacade
{
public:
	ManagerFacade();
	ManagerFacade(OrderTransactionManager * _otm, StockManager* _sm, SaleManager* _slm);
	~ManagerFacade();

	void orderIngredients();
	void printStockStatus();
	void printTransactionStatus();
	void printSales();

private:
	OrderTransactionManager * otm;
	StockManager* sm;
	SaleManager* slm;
};


#pragma once
#include "CoffeeFactory.h"
#include "ProductPriceCalculator.h"
#include "OrderTransactionManager.h"
#include "StockManager.h"
#include "SaleManager.h"
class CounterFacade
{
public:
	CounterFacade();
	CounterFacade(OrderTransactionManager* _otm, StockManager* _sm, SaleManager* _slm);
	~CounterFacade();

	void order();
	void serveCoffee();
	void cancle();

private:
	CoffeeFactory cf;
	OrderTransactionManager* otm;
	StockManager* sm;
	SaleManager* slm;
};


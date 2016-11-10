#include "CounterFacade.h"

CounterFacade::CounterFacade()
{
}

CounterFacade::CounterFacade(OrderTransactionManager * _otm, StockManager * _sm, SaleManager * _slm)
{
	otm = _otm;
	sm = _sm;
	slm = _slm;
}

CounterFacade::~CounterFacade()
{
}

void CounterFacade::order()
{
	int coffeeId = -1;
	Coffee *orderedCoffee;
	vector<int> order;
	char yn;

	cout << "커피 주문:" << endl;
	cout << "(1.아메리카노 2.카푸치노 3.모카커피)" << endl;
	cout << "기본 커피의 아이디를 입력해 주세요: ";
	
	while (1)
	{
		cin >> coffeeId;
		if (coffeeId == 1)
		{
			orderedCoffee = cf.makeCoffee(1);
			order.push_back(1);
			break;
		}
		else if (coffeeId == 2)
		{
			orderedCoffee = cf.makeCoffee(2);
			order.push_back(2);
			break;
		}
		else if (coffeeId == 3)
		{
			orderedCoffee = cf.makeCoffee(3);
			order.push_back(3);
			break;
		}
		else
		{
			cout << "올바르지 않은 입력입니다." << endl;
			cin.clear();
			cin.ignore(256, '\n');
		}
	}
	while (1)
	{
		cout << "샷을 추가 하시겠습니까? (Y/N): ";
		cin >> yn;
		if (yn == 'Y')
		{
			orderedCoffee = new ShotDecorator(orderedCoffee);
			order.push_back(4);
			break;
		}
		else if (yn == 'N')
		{
			break;
		}
		else
		{
			cout << "올바르지 않은 입력입니다." << endl;
			cin.clear();
			cin.ignore(256, '\n');
		}
	}
	while (1)
	{
		cout << "휘핑크림을 추가 하시겠습니까? (Y/N): ";
		cin >> yn;
		if (yn == 'Y')
		{
			orderedCoffee = new WhipDecorator(orderedCoffee);
			order.push_back(5);
			break;
		}
		else if (yn == 'N')
		{
			break;
		}
		else
		{
			cout << "올바르지 않은 입력입니다." << endl;
			cin.clear();
			cin.ignore(256, '\n');
		}
	}

	cout << "__________________________________________________________" << endl;

	int discountId = -1;
	int price = orderedCoffee->getCost();
	ProductPriceCalculator cal;

	cout << "할인 방법을 선택하여 주십시오:" << endl;
	cout << "1. 매장에서 마시고 간다." << endl;
	cout << "2. 테이크아웃 한다." << endl;
	cout << "3. 쿠폰을 사용한다." << endl;
	while (1)
	{
		cin >> discountId;
		if (discountId == 1)
		{
			cal.setDiscountAlgoritm(1);
			break;
		}
		else if (discountId == 2)
		{
			cal.setDiscountAlgoritm(2);
			break;
		}
		else if (discountId == 3)
		{
			cal.setDiscountAlgoritm(3);
			break;
		}
		else
		{
			cout << "올바르지 않은 입력입니다." << endl;
			cin.clear();
			cin.ignore(256, '\n');
		}
	}

	price = cal.discountPrice(price);

	
	vector<int> igd = orderedCoffee->GetIngredientsID();
	for (vector<int>::iterator iter = igd.begin(); iter != igd.end(); ++iter) {
		cout << *iter << "-";
	}
	cout << endl;

	for (vector<int>::iterator iter = order.begin(); iter != order.end(); ++iter) {
		cout << *iter << "-";
	}
	cout << endl;
	cout << price << "원" << endl;
	

	if (sm->reduceStockByIngredientsID(orderedCoffee->GetIngredientsID()))
	{
		otm->addTransaction(Transaction(order, price));
		slm->addPrice(price);
	}
}

void CounterFacade::serveCoffee()
{
	cout << "커피 제공:" << endl;
	if (otm->isEmpty())
		cout << "주문이 없습니다." << endl;
	else
	{
		otm->getFrontTransaction().printCoffee();
		otm->deleteTransactionByIndex(&otm->getFrontTransaction());
	}
}

void CounterFacade::cancle()
{
	if (otm->isEmpty())
	{
		cout << "삭제할 주문이 없습니다." << endl;
		return;
	}
	else
	{
		int idx;
		otm->printTransactions();
		cout << "삭제하고자 하는 주문을 선택하십시오: ";
		cin >> idx;
		if (idx == 0)
		{
			cout << "명령취소" << endl;
			return;
		}
		else if (idx > otm->getLength())
		{
			cout << "잘못된 값을 입력하였습니다." << endl;
			return;
		}
		else if(idx > 0 && idx <= otm->getLength())
		{
			sm->addStockByIngredientsID(otm->getTransactionByIndex(idx - 1).getCoffeeInfo());
			otm->deleteTransactionByIndex(idx - 1);
			cout << "삭제가 완료되었습니다." << endl;
		}
		else
		{
			cout << "올바르지 않은 입력입니다." << endl;
			cin.clear();
			cin.ignore(256, '\n');
			return;
		}
		return;
	}
}

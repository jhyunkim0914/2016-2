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

	cout << "Ŀ�� �ֹ�:" << endl;
	cout << "(1.�Ƹ޸�ī�� 2.īǪġ�� 3.��īĿ��)" << endl;
	cout << "�⺻ Ŀ���� ���̵� �Է��� �ּ���: ";
	
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
			cout << "�ùٸ��� ���� �Է��Դϴ�." << endl;
			cin.clear();
			cin.ignore(256, '\n');
		}
	}
	while (1)
	{
		cout << "���� �߰� �Ͻðڽ��ϱ�? (Y/N): ";
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
			cout << "�ùٸ��� ���� �Է��Դϴ�." << endl;
			cin.clear();
			cin.ignore(256, '\n');
		}
	}
	while (1)
	{
		cout << "����ũ���� �߰� �Ͻðڽ��ϱ�? (Y/N): ";
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
			cout << "�ùٸ��� ���� �Է��Դϴ�." << endl;
			cin.clear();
			cin.ignore(256, '\n');
		}
	}

	cout << "__________________________________________________________" << endl;

	int discountId = -1;
	int price = orderedCoffee->getCost();
	ProductPriceCalculator cal;

	cout << "���� ����� �����Ͽ� �ֽʽÿ�:" << endl;
	cout << "1. ���忡�� ���ð� ����." << endl;
	cout << "2. ����ũ�ƿ� �Ѵ�." << endl;
	cout << "3. ������ ����Ѵ�." << endl;
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
			cout << "�ùٸ��� ���� �Է��Դϴ�." << endl;
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
	cout << price << "��" << endl;
	

	if (sm->reduceStockByIngredientsID(orderedCoffee->GetIngredientsID()))
	{
		otm->addTransaction(Transaction(order, price));
		slm->addPrice(price);
	}
}

void CounterFacade::serveCoffee()
{
	cout << "Ŀ�� ����:" << endl;
	if (otm->isEmpty())
		cout << "�ֹ��� �����ϴ�." << endl;
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
		cout << "������ �ֹ��� �����ϴ�." << endl;
		return;
	}
	else
	{
		int idx;
		otm->printTransactions();
		cout << "�����ϰ��� �ϴ� �ֹ��� �����Ͻʽÿ�: ";
		cin >> idx;
		if (idx == 0)
		{
			cout << "������" << endl;
			return;
		}
		else if (idx > otm->getLength())
		{
			cout << "�߸��� ���� �Է��Ͽ����ϴ�." << endl;
			return;
		}
		else if(idx > 0 && idx <= otm->getLength())
		{
			sm->addStockByIngredientsID(otm->getTransactionByIndex(idx - 1).getCoffeeInfo());
			otm->deleteTransactionByIndex(idx - 1);
			cout << "������ �Ϸ�Ǿ����ϴ�." << endl;
		}
		else
		{
			cout << "�ùٸ��� ���� �Է��Դϴ�." << endl;
			cin.clear();
			cin.ignore(256, '\n');
			return;
		}
		return;
	}
}

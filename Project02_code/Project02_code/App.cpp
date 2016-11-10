#include "App.h"

App::App()
{
	
	OrderTransactionManager *otm = new OrderTransactionManager();
	StockManager *sm = new StockManager();
	SaleManager *slm = new SaleManager();

	sm->setCoffeeStock(10);
	sm->setMilkStock(10);
	sm->setMochaStock(10);
	sm->setShotStock(10);
	sm->setWhipStock(10);

	slm->setPrice(100000);

	cf = new CounterFacade(otm, sm, slm);
	mf = new ManagerFacade(otm, sm, slm);
	
}

App::~App()
{
	delete cf;
	delete mf;
}

void App::run()
{
	int command1 = -1;
	int command2 = -1;

	while (1)
	{
		cout << "Ŀ�Ǽ� �Ŵ�����Ʈ ���α׷�" << endl;
		cout << "1. �����޴�" << endl;
		cout << "2. ����޴�" << endl;
		cout << "0. ������" << endl;

		cin >> command1;
		if (command1 == 1)
		{
			while (1)
			{
				cout << "�����޴�" << endl;
				cout << "1. �ֹ��ޱ�" << endl;
				cout << "2. Ŀ������" << endl;
				cout << "3. �ֹ����" << endl;
				cout << "4. �ǵ��ư���" << endl;
				cin >> command2;

				if (command2 == 1)
					cf->order();
				else if (command2 == 2)
					cf->serveCoffee();
				else if (command2 == 3)
					cf->cancle();
				else if (command2 == 4)
					break;
				else
				{
					cout << "�ùٸ��� ���� �Է��Դϴ�." << endl;
					cin.clear();
					cin.ignore(256, '\n');
				}
			}
		}
		else if (command1 == 2)
		{
			while (1)
			{
				cout << "����޴�" << endl;
				cout << "1. ������" << endl;
				cout << "2. ���Ȯ��" << endl;
				cout << "3. �ֹ� ���� Ȯ��" << endl;
				cout << "4. �ܿ� �ں��� Ȯ��" << endl;
				cout << "5. �ǵ��ư���" << endl;
				cin >> command2;

				if (command2 == 1)
					mf->orderIngredients();
				else if (command2 == 2)
					mf->printStockStatus();
				else if (command2 == 3)
					mf->printTransactionStatus();
				else if (command2 == 4)
					mf->printSales();
				else if (command2 == 5)
					break;
				else
				{
					cout << "�ùٸ��� ���� �Է��Դϴ�." << endl;
					cin.clear();
					cin.ignore(256, '\n');
				}
			}
		}
		else if (command1 == 0)
		{
			break;
		}
		else if (command1 == -1)
		{
			command2 = -1;
		}
		else
		{
			cout << "�ùٸ��� ���� �Է��Դϴ�." << endl;
			cin.clear();
			cin.ignore(256, '\n');
		}
	}
}

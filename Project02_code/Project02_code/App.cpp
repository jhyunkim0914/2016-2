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
		cout << "커피숍 매니지먼트 프로그램" << endl;
		cout << "1. 점원메뉴" << endl;
		cout << "2. 점장메뉴" << endl;
		cout << "0. 나가기" << endl;

		cin >> command1;
		if (command1 == 1)
		{
			while (1)
			{
				cout << "점원메뉴" << endl;
				cout << "1. 주문받기" << endl;
				cout << "2. 커피제공" << endl;
				cout << "3. 주문취소" << endl;
				cout << "4. 되돌아가기" << endl;
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
					cout << "올바르지 않은 입력입니다." << endl;
					cin.clear();
					cin.ignore(256, '\n');
				}
			}
		}
		else if (command1 == 2)
		{
			while (1)
			{
				cout << "점장메뉴" << endl;
				cout << "1. 재료발주" << endl;
				cout << "2. 재고확인" << endl;
				cout << "3. 주문 내역 확인" << endl;
				cout << "4. 잔여 자본금 확인" << endl;
				cout << "5. 되돌아가기" << endl;
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
					cout << "올바르지 않은 입력입니다." << endl;
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
			cout << "올바르지 않은 입력입니다." << endl;
			cin.clear();
			cin.ignore(256, '\n');
		}
	}
}

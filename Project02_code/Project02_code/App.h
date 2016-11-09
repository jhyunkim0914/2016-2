#pragma once
#include "CounterFacade.h"
#include "ManagerFacade.h"
class App
{
public:
	App();
	~App();

	void run();
private:
	CounterFacade* cf;
	ManagerFacade* mf;
};


#pragma once
class SaleManager
{
public:
	SaleManager();
	~SaleManager();

	void addPrice(int price);
	int getPrice();
private:
	int price;
};


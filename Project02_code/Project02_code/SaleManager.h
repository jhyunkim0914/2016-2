#pragma once
class SaleManager
{
public:
	SaleManager();
	~SaleManager();

	void addPrice(int price);
	void setPrice(int price);
	int getPrice();
private:
	int price;
};


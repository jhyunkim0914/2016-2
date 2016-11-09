#pragma once
class DiscountAlgorithm
{
public:
	DiscountAlgorithm();
	~DiscountAlgorithm();

	virtual int discount(int price) = 0;
};


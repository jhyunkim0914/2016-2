#pragma once
#include "DiscountAlgorithm.h"
class DiscountTakeOut :
	public DiscountAlgorithm
{
public:
	DiscountTakeOut();
	~DiscountTakeOut();

	int discount(int price);
};


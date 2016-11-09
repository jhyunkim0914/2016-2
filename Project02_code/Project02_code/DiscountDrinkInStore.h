#pragma once
#include "DiscountAlgorithm.h"
class DiscountDrinkInStore :
	public DiscountAlgorithm
{
public:
	DiscountDrinkInStore();
	~DiscountDrinkInStore();

	int discount(int price);
};


#pragma once
#include "DiscountAlgorithm.h"
class DiscountCoupon :
	public DiscountAlgorithm
{
public:
	DiscountCoupon();
	~DiscountCoupon();

	int discount(int price);
};


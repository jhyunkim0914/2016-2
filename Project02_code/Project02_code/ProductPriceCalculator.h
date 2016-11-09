#pragma once
#include "DiscountCoupon.h"
#include "DiscountDrinkInStore.h"
#include "DiscountTakeOut.h"

class ProductPriceCalculator
{
public:
	ProductPriceCalculator();
	~ProductPriceCalculator();

	bool setDiscountAlgoritm(int discountAlgorithmID);
	int discountPrice(int price);

private:
	DiscountAlgorithm* dcalg;
};


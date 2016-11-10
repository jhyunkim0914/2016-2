#include "ProductPriceCalculator.h"

ProductPriceCalculator::ProductPriceCalculator()
{
}

ProductPriceCalculator::~ProductPriceCalculator()
{
}

bool ProductPriceCalculator::setDiscountAlgoritm(int discountAlgorithmID)
{
	if (discountAlgorithmID == 1)
		dcalg = new DiscountDrinkInStore();
	else if (discountAlgorithmID == 2)
		dcalg = new DiscountTakeOut();
	else if (discountAlgorithmID == 3)
		dcalg = new DiscountCoupon();
	else
		return false;
	return true;
}

int ProductPriceCalculator::discountPrice(int price)
{
	return dcalg->discount(price);
}

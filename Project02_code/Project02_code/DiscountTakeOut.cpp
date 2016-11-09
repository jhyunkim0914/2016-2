#include "DiscountTakeOut.h"

DiscountTakeOut::DiscountTakeOut()
{
}

DiscountTakeOut::~DiscountTakeOut()
{
}

int DiscountTakeOut::discount(int price)
{
	return price/10*9;
}

#include "Bank.h"

void Bank::incrementBillCounter()
{
	billCounter++;
}

unsigned Bank::getBillCounter() const
{
	return billCounter;
}

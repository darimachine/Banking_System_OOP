#include "Bank.h"

void Bank::addEmployee(BankEmployee& employee)
{
	bankEmployees.pushBack(&employee);
}

void Bank::printOnIndex(int index)
{
	std::cout<<bankEmployees[index]->getName();
}





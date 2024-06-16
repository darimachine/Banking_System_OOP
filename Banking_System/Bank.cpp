#include "Bank.h"

BankEmployee* Bank::findTheLeastEngagedEmployee()
{
	unsigned size = bankEmployees.getSize();
	if (size < 1)
	{
		throw std::invalid_argument("There is no employee!!");
	}
	BankEmployee* leastEngagedEmployee = bankEmployees[0];
	int minTaskCount = bankEmployees[0]->getTaskCount();
	for (int i = 1; i < size; i++)
	{
		if (minTaskCount > bankEmployees[i]->getTaskCount()) {
			minTaskCount = bankEmployees[i]->getTaskCount();
			leastEngagedEmployee = bankEmployees[i];
		}
	}
	return leastEngagedEmployee;
}

Bank::Bank(const MyString& name) :name(name)
{

}

const MyString& Bank::getName() const
{
	return name;
}

void Bank::addEmployee(BankEmployee& employee)
{
	bankEmployees.pushBack(&employee);
}

void Bank::printOnIndex(int index)
{
	std::cout<<bankEmployees[index]->getName();
}

void Bank::addTask(Task* task)
{
	BankEmployee* employee = findTheLeastEngagedEmployee();
	employee->addTask(task);
}





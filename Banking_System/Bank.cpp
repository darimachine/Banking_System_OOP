#include "Bank.h"

BankEmployee& Bank::findTheLeastEngagedEmployee()
{
	unsigned size = bankEmployees.getSize();
	if (size < 1)
	{
		throw std::invalid_argument("There is no employee!!");
	}
	BankEmployee& leastEngagedEmployee = bankEmployees[0]; // problem ne chete bankEmployees[0]
	int minTaskCount = bankEmployees[0].getTaskCount();
	for (int i = 1; i < size; i++)
	{
		if (minTaskCount > bankEmployees[i].getTaskCount()) {
			minTaskCount = bankEmployees[i].getTaskCount();
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
	bankEmployees.pushBack(employee);
}

Vector<BankEmployee>& Bank::getBankEmployees()
{
	return bankEmployees;
}

const Vector<BankEmployee>& Bank::getBankEmployees() const
{
	return bankEmployees;
	// TODO: insert return statement here
}

void Bank::printOnIndex(int index)
{
	std::cout<<bankEmployees[index].getName();
}

void Bank::addTask(Task* task)
{
	//task->viewDetails(); // test
	//std::cout<<bankEmployees[0].getName();
	BankEmployee& employee = findTheLeastEngagedEmployee();
	employee.addTask(task);
}

void Bank::saveToFile(std::ofstream& ofs) const
{
	name.saveToFile(ofs);
	int bankEmployeeSize = bankEmployees.getSize();
	ofs.write((const char*)&bankEmployeeSize, sizeof(bankEmployeeSize));
	for (int i = 0; i < bankEmployeeSize; i++)
	{
		bankEmployees[i].saveEmployeeToFile(ofs);
	}
}

void Bank::readFromFile(std::ifstream& ifs)
{
	name.readFromFile(ifs);
	int bankEmployeeSize;
	ifs.read((char*)&bankEmployeeSize, sizeof(bankEmployeeSize));
	for (int i = 0; i < bankEmployeeSize; i++)
	{
		BankEmployee current;
		current.readEmployeeFromFile(ifs);
		bankEmployees.pushBack(std::move(current));
	}
}





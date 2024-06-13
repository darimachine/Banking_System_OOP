#pragma once
#include "MyVector.hpp"
#include "Task.h"
#include "BankEmployee.h"
class Bank
{
	MyString name;
	unsigned billCounter = 0;
	Vector<BankEmployee> bankemployees;

public:
	void addTask(Task* task);
	void incrementBillCounter();
	unsigned getBillCounter() const;
};


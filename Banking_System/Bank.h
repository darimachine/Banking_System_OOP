#pragma once
#include "MyVector.hpp"
#include "Task.h"
#include "BankEmployee.h"
class Bank
{
	MyString name;
	unsigned billCounter = 0; // for unique ID's on every bill
	Vector<BankEmployee> bankEmployees;

public:
	void addTask(Task* task);
	void incrementBillCounter();
	unsigned getBillCounter() const;
};


#pragma once
#include "MyVector.hpp"
#include "Task.h"
#include "BankEmployee.h"
#include "SharedPtr.hpp"
#include "UniquePointer.hpp"
class Bank
{
	MyString name;
	Vector<BankEmployee*> bankEmployees; // DOESNT NEED DELETE BECAUSE ITS SHALLOW COPY FROM THE SYSTEM
	BankEmployee* findTheLeastEngagedEmployee();
public:
	Bank() = default;
	Bank(const MyString& name);
	

	const MyString& getName() const;

	void addEmployee(BankEmployee& employee);

	void printOnIndex(int index);
	void addTask(Task* task);
	
};


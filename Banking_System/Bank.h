#pragma once
#include "MyVector.hpp"
#include "Task.h"
#include "BankEmployee.h"
#include "SharedPtr.hpp"
#include "UniquePointer.hpp"
class Bank
{
	MyString name;
	Vector<BankEmployee*> bankEmployees;

public:
	Bank() = default;
	void addEmployee(BankEmployee& employee);
	void printOnIndex(int index);
	void addTask(Task* task);
	
};


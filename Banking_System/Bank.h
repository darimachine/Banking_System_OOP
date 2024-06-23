#pragma once
#include "Utilities/MyVector.hpp"
#include "Tasks/Task.h"
#include "Users/BankEmployee.h"

#include "Utilities/PolyMorphic_Ptr.hpp"
class Bank
{
	MyString name;
	Vector<BankEmployee> bankEmployees; // DOESNT NEED DELETE BECAUSE ITS SHALLOW COPY FROM THE SYSTEM

	BankEmployee& findTheLeastEngagedEmployee();
public:
	Bank() = default;
	Bank(const MyString& name);
	

	const MyString& getName() const;

	void addEmployee(BankEmployee& employee);
	Vector<BankEmployee>& getBankEmployees();
	const Vector<BankEmployee>& getBankEmployees() const;
	void printOnIndex(int index);
	void addTask(Task* task);

	void saveToFile(std::ofstream& ofs) const;

	void readFromFile(std::ifstream& ifs);
	
};


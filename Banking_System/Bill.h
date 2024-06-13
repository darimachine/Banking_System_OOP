#pragma once
#include "MyString.h"
class Bill
{
	
	MyString bankName;
	unsigned accountID;
	double balance;
public:
	Bill(const MyString& bankName,double balance,unsigned id);
	double getBalance() const;
	unsigned getID() const;
	const MyString& getBankName() const;
	void deposit(double amount);
	void withdraw(double amount);
};


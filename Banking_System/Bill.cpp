#include "Bill.h"

Bill::Bill(const MyString& bankName,double balance,unsigned id)
{
	this->bankName = bankName;
	accountID = id;
	this->balance = balance;
}
double Bill::getBalance() const {
	return balance;
}
unsigned Bill::getID() const
{
	return accountID;
}
void Bill::deposit(double amount) {
	balance += amount;
}
void Bill::withdraw(double amount) {
	if (balance >= amount)
	{
		balance -= amount;
	}
}

const MyString& Bill::getBankName() const
{
	return bankName;
	
}

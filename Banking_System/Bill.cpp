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

void Bill::saveToFile(std::ofstream& ofs) const
{
	bankName.saveToFile(ofs);
	ofs.write((const char*)&accountID, sizeof(accountID));
	ofs.write((const char*)&balance, sizeof(balance));
}

void Bill::readFromFile(std::ifstream& ifs)
{
	bankName.readFromFile(ifs);
	ifs.read((char*)&accountID, sizeof(accountID));
	ifs.read((char*)&balance, sizeof(balance));
}

const MyString& Bill::getBankName() const
{
	return bankName;
	
}

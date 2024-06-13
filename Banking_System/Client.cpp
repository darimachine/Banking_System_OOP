#include "Client.h"

void Client::messages() const
{
	
	
}

Client::Client(const MyString& name, const MyString& egn, unsigned age, const MyString& password) 
	:User(name,egn,age,password)
{
}

void Client::addCheck(const Check& check)
{
	checks.pushBack(check);
}

void Client::addBill(const Bill& bill)
{
	bankAccounts.pushBack(bill);
}

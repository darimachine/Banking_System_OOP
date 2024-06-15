#include "ChangeAccountTaskApproved.h"
#include "Client.h"

using std::cout;
using std::endl;
double ChangeAccountTaskApproved::getBalance() const
{
	int index = client.findbankAccountIndex(oldBank, accountID);
	return client.getBill(index).getBalance();
}
ChangeAccountTaskApproved::ChangeAccountTaskApproved(const MyString& newBank, Client& client, const MyString& oldBank, unsigned accountID)
	:ChangeAccountTask("Change Approved",newBank,client,oldBank,accountID)
{
}

void ChangeAccountTaskApproved::viewDetails() const
{
	
	cout << type << "request from:\n";
	cout << "Name: " << client.getName() << endl;
	cout << "EGN: " << client.getEGN() << endl;
	cout << "Age: " << client.getAge() << endl;
	cout << "Previous Bank: " << oldBank << endl;
	cout << "Account number: " << accountID << endl;
	cout << "Balance: " << getBalance() << "$\n";
}

void ChangeAccountTaskApproved::viewMessage() const
{
	cout << type << " - " << client.getName() << " want to join " << newBank << ".\n";
	//[1] Change(approved) - Stancho wants to join Health_Savings_Accounts.
}

Task* ChangeAccountTaskApproved::clone() const
{
	return new ChangeAccountTaskApproved(*this);
}

Task* ChangeAccountTaskApproved::finish()
{
	unsigned id = generateUniqueNumber();
	double balance = getBalance();
	Bill account(newBank, balance, id);
	client.addBill(account);
	client.removeBill(oldBank, accountID);
	MyString tempMessage = "You changed your savings account to";
	tempMessage += newBank;
	tempMessage += ". New account id is ";
	char idStr[20];
	intToStr(id, idStr);
	tempMessage += idStr;
	tempMessage += ".";
	//besen sum
	client.addMessage(tempMessage);
	return nullptr;
}

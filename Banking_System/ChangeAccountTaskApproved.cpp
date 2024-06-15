#include "ChangeAccountTaskApproved.h"
#include "Client.h"
using std::cout;
using std::endl;
ChangeAccountTaskApproved::ChangeAccountTaskApproved(const MyString& newBank, Client& client, const MyString& oldBank, unsigned accountID)
	:ChangeAccountTask("Change Approved",newBank,client,oldBank,accountID)
{
}

void ChangeAccountTaskApproved::viewDetails() const
{
	int index = client.findbankAccountIndex(oldBank, accountID);
	cout << type << "request from:\n";
	cout << "Name: " << client.getName() << endl;
	cout << "EGN: " << client.getEGN() << endl;
	cout << "Age: " << client.getAge() << endl;
	cout << "Previous Bank: " << oldBank << endl;
	cout << "Account number: " << accountID << endl;
	cout << "Balance: " << client.getBill(index).getBalance() << "$\n";
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
	return nullptr;
}

#include "ChangeAccountTaskApproved.h"
#include "Client.h"
using std::cout;
using std::endl;
ChangeAccountTaskApproved::ChangeAccountTaskApproved(const MyString& newBank, Client& client, Bill& billToChange)
	:ChangeAccountTask("Change Approved",newBank,client,billToChange)
{
}

void ChangeAccountTaskApproved::viewDetails() const
{
	cout << type << "request from:\n";
	cout << "Name: " << client.getName() << endl;
	cout << "EGN: " << client.getEGN() << endl;
	cout << "Age: " << client.getAge() << endl;
	cout << "Previous Bank: " << billToValidate.getBankName() << endl;
	cout << "Account number: " << billToValidate.getID() << endl;
	cout << "Balance: " << billToValidate.getBalance() << "$\n";
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

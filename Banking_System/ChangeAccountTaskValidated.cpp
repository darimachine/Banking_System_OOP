#include "ChangeAccountTaskValidated.h"
#include "Client.h"
using std::cout;
using std::endl;
ChangeAccountTaskValidated::ChangeAccountTaskValidated(const MyString& newBank, Client& client, const MyString& oldBank, unsigned accountID)
	:ChangeAccountTask("Change Validated",newBank,client,oldBank,accountID)
{
}

void ChangeAccountTaskValidated::viewDetails() const
{
	int index = client.findbankAccountIndex(oldBank,accountID);
	cout << type << "request from:\n";
	cout << "Name: " << client.getName() << endl;
	cout << "EGN: " << client.getEGN() << endl;
	cout << "Age: " << client.getAge() << endl;
	cout << "Account number: " << accountID << endl;
	cout << "Balance: " <<  client.getBill(index).getBalance()<< "$\n";

}

void ChangeAccountTaskValidated::viewMessage() const
{
	cout << "Change - " << newBank << " asks if " << client.getName() << " is real user.\n";
	//[2] Change - Health_Savings_Accounts asks if Stancho is real user.
}

Task* ChangeAccountTaskValidated::clone() const
{
	return new ChangeAccountTaskValidated(*this);
}

Task* ChangeAccountTaskValidated::finish()
{
	return nullptr;
}

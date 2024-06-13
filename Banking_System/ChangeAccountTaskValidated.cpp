#include "ChangeAccountTaskValidated.h"
#include "Client.h"
using std::cout;
using std::endl;
ChangeAccountTaskValidated::ChangeAccountTaskValidated(const MyString& newBank, Client& client, Bill& billToChange)
	:ChangeAccountTask("Change Validated",newBank,client,billToChange)
{
}

void ChangeAccountTaskValidated::viewDetails() const
{
	cout << type << "request from:\n";
	cout << "Name: " << client.getName() << endl;
	cout << "EGN: " << client.getEGN() << endl;
	cout << "Age: " << client.getAge() << endl;
	cout << "Account number: " << billToValidate.getID() << endl;
	cout << "Balance: " << billToValidate.getBalance() << "$\n";

}

void ChangeAccountTaskValidated::viewMessage() const
{
	cout << "Change - " << billToValidate.getBankName() << " asks if " << client.getName() << " is real user.\n";
	//[2] Change - Health_Savings_Accounts asks if Stancho is real user.
}

Task* ChangeAccountTaskValidated::clone() const
{
	return new ChangeAccountTaskValidated(*this);
}

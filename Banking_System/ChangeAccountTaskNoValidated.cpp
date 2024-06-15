#include "ChangeAccountTaskNoValidated.h"
#include "Client.h"
using std::cout;
using std::endl;


ChangeAccountTaskNoValidated::ChangeAccountTaskNoValidated(const MyString& newBank, Client& client, const MyString& oldBank, unsigned accountID)
	:ChangeAccountTask("Change Not Validated",newBank,client, oldBank,accountID)
{

}

void ChangeAccountTaskNoValidated::viewDetails() const
{
	cout << type << "request from:\n";
	cout << "Name: " << client.getName() << endl;
	cout << "EGN: " << client.getEGN() << endl;
	cout << "Age: " << client.getAge() << endl;
	cout << "Bank: " << oldBank << endl;
}

void ChangeAccountTaskNoValidated::viewMessage() const
{
	cout << "Change - " << client.getName() << " want to join " << oldBank << ".\n";
	
}

Task* ChangeAccountTaskNoValidated::clone() const
{
	return new ChangeAccountTaskNoValidated(*this);
}

Task* ChangeAccountTaskNoValidated::finish()
{
	cout << "Cannot proceed - please make sure " << client.getName() << "is real user by asking the bank!\n";
	return nullptr;
}




#include "ChangeAccountTaskNoValidated.h"
#include "Client.h"
using std::cout;
using std::endl;


ChangeAccountTaskNoValidated::ChangeAccountTaskNoValidated(const MyString& newBank, Client& client,Bill& billToChange)
	:ChangeAccountTask("Change Not Validated",newBank,client,billToChange)
{

}

void ChangeAccountTaskNoValidated::viewDetails() const
{
	cout << type << "request from:\n";
	cout << "Name: " << client.getName() << endl;
	cout << "EGN: " << client.getEGN() << endl;
	cout << "Age: " << client.getAge() << endl;
	cout << "Bank: " << billToValidate.getBankName() << endl;
}

void ChangeAccountTaskNoValidated::viewMessage() const
{
	cout << "Change - " << client.getName() << " want to join " << billToValidate.getBankName() << ".\n";
	
}

Task* ChangeAccountTaskNoValidated::clone() const
{
	return new ChangeAccountTaskNoValidated(*this);
}


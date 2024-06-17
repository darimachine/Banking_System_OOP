#include "RegisterCommand.h"
#include "Client.h"
#include "BankEmployee.h"
#include "ExternalCompanyEmployee.h"
using std::cout;
using std::cin;
using std::endl;
void RegisterCommand::execute(BankSystem* app)
{
	MyString name;
	MyString egn;
	unsigned age;
	MyString role;
	char roleGet[1024];
	MyString bankAssociated;
	MyString password;

	cout << "Name: ";
	cin >> name;

	cout << "EGN: ";
	cin >> egn;

	cout << "Age: ";
	cin >> age;

	cout << "Role: ";
	cin >> role;

	if (role == "Client")
	{
		cout << "Password: ";
		cin >> password;
		
		try {
			Client client(name, egn, age, password);
			app->signUpClient(std::move(client));
			cout << "Succesfully Registered\n";
		}
		catch (std::invalid_argument er)
		{
			cout << er.what() << endl;
		}
		catch (std::runtime_error er)
		{
			cout << er.what() << endl;
		}
		catch (std::exception er)
		{
			cout << er.what() << endl;
		}
	}
	else if (role == "Employee")
	{
		cout << "Bank associated: ";
		cin >> bankAssociated;
		
		cout << "Password: ";
		cin >> password;
		
		try {
			BankEmployee bankEmployee(name, egn, age, password, bankAssociated);
			app->signUpBankEmployee(bankEmployee);
			cout << "Succesfully Registered\n";
		}
		catch (std::invalid_argument er)
		{
			cout << er.what() << endl;
		}
		catch (std::runtime_error er)
		{
			cout << er.what() << endl;
		}
		catch (std::exception er)
		{
			cout << er.what() << endl;
		}

	}
	else if (role == "Third-partyEmployee")
	{
		cout << "Password: ";
		cin >> password;
		
		try {
			ExternalCompanyEmployee extrnalEmployee(name, egn, age, password);
			app->signUpExternalEmployee(std::move(extrnalEmployee));
			cout << "Succesfully Registered\n";
		}
		catch (std::invalid_argument er)
		{
			cout << er.what() << endl;
		}
		catch (std::runtime_error er)
		{
			cout << er.what() << endl;
		}
		catch (std::exception er)
		{
			cout << er.what() << endl;
		}
	}
	else {
		std::cout << "Wrong Role!!\n";
	}
	
}

#include "SendCheckCommand.h"
#include "../Check.h"
using std::cin;
using std::cout;
void SendCheckCommand::execute(BankSystem* app)
{
	double sum;
	cin >> sum;
	MyString vericationCode;
	cin >> vericationCode;
	MyString egn;
	cin >> egn;
	ExternalCompanyEmployee* employee = app->getLoggedExternalEmployee();
	try {
		
		Check check(employee->getName(), vericationCode, sum, egn);
		Client& client = app->getClientByEgn(egn);
		client.addCheck(check);
		MyString message = "You have a check assigned to you by ";
		message += employee->getName();
		message += ".";
		client.addMessage(message);
		
	}
	catch(std::invalid_argument& er){
		cout << er.what() << std::endl;
	}
}

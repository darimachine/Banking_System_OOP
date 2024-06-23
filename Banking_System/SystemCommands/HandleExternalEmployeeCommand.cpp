#include "HandleExternalEmployeeCommand.h"
#include "../ExternalEmployeesCommands/SendCheckCommand.h"
using std::cin;
void HandleExternalEmployeeCommand::execute(BankSystem* app)
{
	SendCheckCommand sendCheckCommand;
	MyString command;
	cin >> command;
	if (command == "send_check")
	{
		sendCheckCommand.execute(app);
	}
	else if (command == "exit")
	{
		app->logout();
		std::cout << "Logged Out\n";
	}
	else if (command == "whoami")
	{
		app->getLoggedExternalEmployee()->whoami();
	}
	else if (command == "help")
	{
		app->getLoggedExternalEmployee()->help();
	}
	else if (command == "save")
	{
		app->save();
		app->exit();
	}
	else {
		std::cout << "Unknown Command\n";
		cin.clear();
		cin.ignore(1024, '\n');
	}
}
